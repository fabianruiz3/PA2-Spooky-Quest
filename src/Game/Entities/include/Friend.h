#pragma once

#include "Entity.h"
#include "Animation.h"

class Friend : public Entity{
    private:
    ofImage buddy;
    ofImage interactingImage;
    Direction direction;
    bool interaction = false;
    bool walking = false;
    int speed = 8;
    int renderX = 1000;
    int renderY = 1000;
    int moveTimer;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;

   public:
    Friend(int ox, int oy);
   ~Friend();
    void inOverworldUpdate();
    void inOverworldDraw();
    void setRenderX(int x) { renderX = x; };
    void setRenderY(int y) { renderY = y; };
    void setInteracting(bool react){interaction = react;}
    
};

    