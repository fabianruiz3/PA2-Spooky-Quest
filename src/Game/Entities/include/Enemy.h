#pragma once

#include "Animation.h"
#include "FightingEntity.h"

class Enemy : public FightingEntity {
   protected:
    Direction direction;
    int speed = 8;
    bool walking = false;
    int renderX = 1000;
    int renderY = 1000;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    Animation *fighting;
    string id;
    int moveTimer;
    bool dead = false;
    bool spawn = true;
    bool anotherHealthBar = false;
    string entityName;
    ofImage sprite;

   public:
    Enemy(string id, int health, int baseDamage, string entityName, int ox, int oy);
    ~Enemy();
    int getOX() { return ox; };
    int getOY() { return oy; };
    bool isDead() { return dead; };
    bool shouldSpawn() { return spawn; };
    bool hasAnotherHealthBar() { return anotherHealthBar; };
    void kill() { this->dead = true; };
    void revive() { this->dead = false; };
    void setRenderX(int x) { renderX = x; };
    void setRenderY(int y) { renderY = y; };
    void setSpawn(bool s) { spawn = s; };
    void setAnotherHealthBar( bool hb ) {anotherHealthBar = hb; };
    void inOverworldUpdate();
    void fightingUpdate();
    virtual void inOverworldDraw();
    virtual void keyPressed(int key);
    virtual void reset();
    string getId() { return id; };
    ofImage getSprite() { return overworldSprite; };
};