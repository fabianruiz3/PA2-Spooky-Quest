#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area) {
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
}

void OverworldState::loadArea(Area *area) {
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::update() {
    player->inOverworldUpdate();
    if(player->getHealth() <= 0){
        setNextState("End");
        setFinished(true);
    }

    interactionTimer++;// sets how long the interaction image will play
    if(interactionTimer == 50){
        area->getFriends().at(0)->setInteracting(false);
    }
    

    if(area->isDrainHealth() && drainTimer == 0){
        player->setHealth(player->getHealth() - 1);
        drainTimer = 60;
    }
    else if(area->isDrainHealth()){
        drainTimer--;
    }

    if(area->getRemainingEnemies() == 1){
        for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
            if(area->getEnemies().at(i)->shouldSpawn() == false){
                area->getEnemies().at(i)->setSpawn(true);
            }
        }
    }

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead() && area->getEnemies().at(i)->shouldSpawn()) {
            area->getEnemies().at(i)->inOverworldUpdate();
            if (player->collides(area->getEnemies().at(i))) {
                setEnemy(area->getEnemies().at(i));
                setNextState("Battle");
                setFinished(true);
                break;
            }
        }
    }
    for (unsigned int i = 0; i < area->getImmovableEntities().size(); i++) {
        if (player->collides(area->getImmovableEntities().at(i))) {
            player->collideWithImmovable();
        }       
    }

    for(unsigned int i =0; i < area->getFriends().size(); i++){
        area->getFriends().at(i)->inOverworldUpdate();
        if(player->collides(area->getFriends().at(i))){
            interacting  = true;

        }
       else{
        interacting = false;
       }
    }
    camera->update();
}

void OverworldState::draw() {
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->inOverworldDraw();

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead() && area->getEnemies().at(i)->shouldSpawn()) {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->inOverworldDraw();
        }
    }

    for (unsigned int i = 0; i < area->getImmovableEntities().size(); i++){
        int playerDistanceX = area->getImmovableEntities().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getImmovableEntities().at(i)->getOY() - camera->getPlayerY();
        area->getImmovableEntities().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getImmovableEntities().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getImmovableEntities().at(i)->inOverworldDraw();
    }

    for(unsigned int i = 0; i < area->getFriends().size(); i++){
        int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
        area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getFriends().at(i)->inOverworldDraw();
    }
    //Draws HUD
    ofDrawBitmapString("Current Area: ",2,30);
    ofDrawBitmapString(this->area->getName(),110,30);
    ofDrawBitmapString("Current Health: " ,2,40);
    ofDrawBitmapString(player->getHealth(), 130,40);
    ofDrawBitmapString("Current Living Enemies: ", 2,50);
    ofDrawBitmapString(this->area->getRemainingEnemies(),190,50);
}

void OverworldState::keyPressed(int key) {
    player->keyPressed(key);
    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead()) {
            area->getEnemies().at(i)->keyPressed(key);
        }
    }
    
    if(key == 'r') {area->resetEnemies();};
    if(key == 'e'){ 
        if(interacting){
            interactionTimer=0;
            area->getFriends().at(0)->setInteracting(true);
        }

    }
    if(key == OF_KEY_ESC){
        setCurrentState("Overworld");
        setNextState("Pause");
        setFinished(true);
    }
}


void OverworldState::keyReleased(int key) {
    player->keyReleased(key);
}

void OverworldState::reset() {
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}