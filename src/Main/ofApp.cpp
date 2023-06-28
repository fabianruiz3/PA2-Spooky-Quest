#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    ofSetFrameRate(30);
    ofSetWindowTitle("PA2");
    initAreas();
    // Declaration and Initialization of States
    player = new Player(100, 6);
    titleState = new TitleState();
    overworldState = new OverworldState(player, currentArea);
    battleState = new BattleState(player, currentArea);
    winState = new WinState();
    endGameState = new EndGameState();
    pauseState = new PauseState();
    // Initial State
    currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::initAreas() {
    /**
     * @brief
     * each area is 672 pixels wide and 640 pixels high,
     * with 10 and 8 pixels of space between the player and the edge of the map respectively
     * each in-game pixel is 4 * 1 screen pixel
     */

    vector<Enemy *> enemies4;
    vector<ImmovableEntity *> immovableEntities4;
    vector<Friend *> friendEntities4;
    ofPoint entrancePosition4(4 * 110, 4 * 116);
    Enemy *area4Enemy1 = new Enemy("41", 24, 5, "enemy4", 4 * 120, 4 * 342);
    Enemy *area4Enemy2 = new Enemy("42", 24, 5, "enemy4", 4 * 254, 4 * 130);
    Enemy *area4Enemy3 = new Enemy("43", 24, 5, "enemy4", 4 * 542, 4 * 124);
    Enemy *area4Enemy4 = new Enemy("44", 24, 5, "enemy4", 4 * 532, 4 * 368);
    Enemy *area4Enemy5 = new Enemy("45", 24, 5, "enemy4", 4 * 266, 4 * 312);
    Enemy *area4Enemy6 = new Enemy("46", 24, 5, "enemy4", 4 * 194, 4 * 532);
    Boss *area4Boss = new Boss("41", 30, 5, "boss4", 1600, 824);
    Friend *friend4 = new Friend(850, 400);
    ImmovableEntity *area4ImmovableEntity1 =  new ImmovableEntity( 650, 664, 80, 80, "41", "rock4", "images/entities/rock.png");
    enemies4.push_back(area4Enemy1);
    enemies4.push_back(area4Enemy2);
    enemies4.push_back(area4Enemy3);
    enemies4.push_back(area4Enemy4);
    enemies4.push_back(area4Enemy5);
    enemies4.push_back(area4Enemy6);
    enemies4.push_back(area4Boss);
    immovableEntities4.push_back(area4ImmovableEntity1);
    friendEntities4.push_back(friend4);
    area4 = new Area("Area4", NULL, "images/areas/area4.png", "audio/ice.wav", "images/stages/stage4.png", entrancePosition4, enemies4, immovableEntities4, friendEntities4);

    vector<Enemy *> enemies3;
    vector<ImmovableEntity *> immovableEntities3;
    ofPoint entrancePosition3(432, 640);
    vector<Friend *> friendEntities3;
    Enemy *area3Enemy1 = new Enemy("31", 24, 5, "enemy3", 480, 1680);
    Enemy *area3Enemy2 = new Enemy("32", 24, 5, "enemy3", 1600, 2160);
    Boss *area3Boss = new Boss("31", 30, 5, "boss3", 2120, 760);
    Friend *friend3 = new Friend(2312, 1448);
    ImmovableEntity *area3ImmovableEntity1 =  new ImmovableEntity( 1260, 990, 120, 120, "31", "rock3", "images/entities/rock.png");
    friendEntities3.push_back(friend3);
    enemies3.push_back(area3Enemy1);
    enemies3.push_back(area3Enemy2);
    enemies3.push_back(area3Boss);
    immovableEntities3.push_back(area3ImmovableEntity1);
    area3 = new Area("Area3", area4, "images/areas/area3.png", "audio/snow.wav", "images/stages/stage3.png", entrancePosition3, enemies3, immovableEntities3, friendEntities3);

    vector<Enemy *> enemies2;
    vector<ImmovableEntity *> immovableEntities2;
    vector<Friend *> friendEntities2;
    ofPoint entrancePosition2(328, 624);
    Enemy *area2Enemy1 = new Enemy("21", 18, 4, "enemy2", 1128, 664);
    Enemy *area2Enemy2 = new Enemy("22", 18, 4, "enemy2", 712, 1800);
    Enemy *area2Enemy3 = new Enemy("23", 18, 4, "enemy2", 2080, 800);
    Boss *area2Boss = new Boss("21", 24, 4, "boss2", 1576, 1360);
    Friend *friend2 = new Friend(500, 1300);
    ImmovableEntity *area2ImmovableEntity1 =  new ImmovableEntity( 608, 1200, 100, 100, "21", "rock2", "images/entities/rock.png");
    friendEntities2.push_back(friend2);
    enemies2.push_back(area2Enemy1);
    enemies2.push_back(area2Enemy2);
    enemies2.push_back(area2Enemy3);
    enemies2.push_back(area2Boss);
    immovableEntities2.push_back(area2ImmovableEntity1);
    area2 = new Area("Area2", area3, "images/areas/area2.png", "audio/sand.mp3", "images/stages/stage2.png", entrancePosition2, enemies2, immovableEntities2, true, friendEntities2);

    vector<Enemy *> enemies1;
    vector<ImmovableEntity *> immovableEntities1;
    vector<Friend *> friendEntities1;
    ofPoint entrancePosition1(4 * 414, 4 * 566);
    Enemy *area1Enemy1 = new Enemy("11", 15, 3, "enemy1", 4 * 480, 4 * 432);
    Enemy *area1Enemy2 = new Enemy("12", 15, 3, "enemy1", 856, 1472);
    Enemy *area1Enemy3 = new Enemy("13", 15, 3, "enemy1", 4 * 420, 4 * 178);
    Boss *area1Boss = new Boss("11", 18, 3, "boss1", 4 * 225, 4 * 178);
    Friend *friend1 = new Friend(1110, 1000);
     ImmovableEntity *area1ImmovableEntity1 =  new ImmovableEntity( 1344, 766, 100, 100, "11", "rock1", "images/entities/rock.png");
    enemies1.push_back(area1Enemy1);
    enemies1.push_back(area1Enemy2);
    enemies1.push_back(area1Enemy3);
    enemies1.push_back(area1Boss);
     immovableEntities1.push_back(area1ImmovableEntity1);
    friendEntities1.push_back(friend1);
    area1 = new Area("Area1", area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, immovableEntities1, friendEntities1);
    currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update() {
    currentState->update();
    if (currentState->hasFinished()) {
        currentState->toggleMusic();
        if (currentState->getNextState() == "Title") {
            endGameState->setWin(false);
            area1->resetEnemies();
            area2->resetEnemies();
            area3->resetEnemies();
            area4->resetEnemies();
            currentArea = area1;
            battleState->reset();
            battleState->setStage(currentArea->getStage());
            overworldState->loadArea(currentArea);
            currentState = titleState;
        } else if (currentState->getNextState() == "Overworld") {
            currentState = overworldState;
        } else if(currentState->getNextState()== "Pause"){
            pauseState->setPreviousState(currentState->getCurrentState());
            currentState = pauseState;
            currentState->setNextState("");
        }
        else if (currentState->getNextState() == "Battle") {
            if(currentState->getCurrentState() != "Pause"){
                battleState->startBattle(overworldState->getEnemy());
            }else{
                battleState->continueBattle(overworldState->getEnemy());
            }
            currentState = battleState;
        } else if (currentState->getNextState() == "Win") {
            overworldState->getEnemy()->kill();
            if (currentArea->getRemainingEnemies() == 0 || battleState->isBossDead()) {
                if (currentArea->getNextArea() == NULL) {
                    endGameState->setWin(true);
                    currentState = endGameState;
                    player->reset();
                } else {
                    currentArea = currentArea->getNextArea();
                    overworldState->loadArea(currentArea);
                    battleState->setStage(currentArea->getStage());
                    currentState = winState;
                }
            } else {
                currentState = winState;
            }
        } else if (currentState->getNextState() == "End"){
            currentState = endGameState;
            player->reset();
        }
        currentState->toggleMusic();
        currentState->reset();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentState->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    currentState->dragEvent(dragInfo);
}