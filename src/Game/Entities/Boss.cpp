#include "Boss.h"
 
Boss::Boss(string id, int health, int baseDamage, string entityName, int ox, int oy) : Enemy(id, health, baseDamage, entityName, ox, oy) {
   vector<ofImage> downFrames;
   vector<ofImage> upFrames;
   vector<ofImage> leftFrames;
   vector<ofImage> rightFrames;
   ofImage temp;
   this->spawn = false;
   this->anotherHealthBar = true;
 
   sprite.load("images/entities/enemy/sprite.png");
 
 
   int w = 48, h = 48;
 
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 4; ++j) {
           temp.cropFrom(sprite, (w*i), (h*j), w, h);
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
   fighting = new Animation(7, leftFrames);
 
   direction = Direction::down;
}
 
void Boss::inOverworldDraw() {
   // uncomment these if you want the coordinates of the enemies in the current area
   // ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125 * ((stoi(id) % 10) - 1), 100);
   // ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125 * ((stoi(id) % 10) - 1), 120);
   // ofDrawBitmapString("ow:" + to_string(ox), 100 + 125 * ((stoi(id) % 10) - 1), 140);
   // ofDrawBitmapString("oy:" + to_string(oy), 100 + 125 * ((stoi(id) % 10) - 1), 160);
   if(spawn){
       overworldSprite.draw(renderX, renderY, ow, oh);
    }
}

void Boss::reset() {
    spawn = false;
    anotherHealthBar = true;
}

void Boss::keyPressed(int key){
    if( key == 'b'){
        spawn = true;
    }
}

 
Boss::~Boss() {
   delete walkUp;
   delete walkDown;
   delete walkLeft;
   delete walkRight;
   delete fighting;
}