#include "Friend.h"

   Friend::Friend(int ox, int oy) : Entity(ox,oy,50,64) {
    moveTimer = 60;
    vector<ofImage> downFrames;
    vector<ofImage> upFrames;
    vector<ofImage> leftFrames;
    vector<ofImage> rightFrames;
    ofImage buddy;
    ofImage temp;
    buddy.load("images/entities/enemy/sprite.png");

    int w = 48, h = 48;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp.cropFrom(buddy, 294 + w * i, 192 + h * j, w - 12, h);
            if (j == 0)
                downFrames.push_back(temp);
            else if (j == 1)
                leftFrames.push_back(temp);
            else if (j == 2)
                rightFrames.push_back(temp);
            else
                upFrames.push_back(temp);
        }   
    }

    walkDown = new Animation(3, downFrames);
    walkUp = new Animation(3, upFrames);
    walkLeft = new Animation(3, leftFrames);
    walkRight = new Animation(3, rightFrames);

    direction = Direction::down;
}

void Friend::inOverworldUpdate() {
    if (moveTimer == 60) {
        walking = true;
        switch (direction) {
            case Direction::left:
                direction = Direction::up;
                break;
            case Direction::right:
                direction = Direction::down;
                break;
            case Direction::up:
                direction = Direction::right;
                break;
            case Direction::down:
                direction = Direction::left;
                break;
        }
    }
    if (moveTimer == 45) {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0) moveTimer = 60;

    if (walking) {
        switch (direction) {
            case Direction::left:
                this->ox -= speed;
                walkLeft->update();
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                this->ox += speed;
                walkRight->update();
                overworldSprite = walkRight->getCurrentFrame();
                break;
            case Direction::up:
                this->oy -= speed;
                walkUp->update();
                overworldSprite = walkUp->getCurrentFrame();
                break;
            case Direction::down:
                this->oy += speed;
                walkDown->update();
                overworldSprite = walkDown->getCurrentFrame();
                break;
        }
    } else {
        switch (direction) {
            case Direction::left:
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                overworldSprite = walkRight->getCurrentFrame();;
                break;
            case Direction::up:
                overworldSprite = walkUp->getCurrentFrame();
                break;
            case Direction::down:
                overworldSprite = walkDown->getCurrentFrame();
                break;
        }
    }
}

void Friend::inOverworldDraw() {
    overworldSprite.draw(renderX, renderY, ow, oh);
    if(interaction) {
      interactingImage.load("images/objects/Interaction.png");
      interactingImage.draw(renderX+30, renderY-30,110,60);
      }
}

Friend::~Friend() {
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}
