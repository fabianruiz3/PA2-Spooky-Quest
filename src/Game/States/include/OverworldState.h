#pragma once

#include "Area.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "ImmovableEntity.h"
#include "State.h"
#include "Friend.h"

class OverworldState : public State {
   private:
    ofImage overworldImage;
    Player *player;
    OverworldCamera *camera;
    Area *area;
    Enemy *enemy;
    Friend *buddy;
    int drainTimer = 60;
    int interactionTimer = 0;
    bool interacting = false;
   public:
    OverworldState(Player *player, Area *area);
    Player *getPlayer() { return player; };
    void setEnemy(Enemy *enemy) { this->enemy = enemy; };
    Enemy *getEnemy() { return enemy; };
    Friend *getFriend() { return buddy; };
    void loadArea(Area *Area);
    Area *getArea() { return area; };
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void reset();
};