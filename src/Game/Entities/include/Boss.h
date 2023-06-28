#pragma once

#include "Enemy.h"

class Boss : public Enemy{
    public:
        Boss(string id, int health, int baseDamage, string entityName, int ox, int oy);
        ~Boss();
        void inOverworldDraw();
        void keyPressed(int key);
        void reset();
};