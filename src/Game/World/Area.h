#pragma once

#include "Enemy.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "ImmovableEntity.h"
#include "Friend.h"

class Area {
   private:
    string name;
    ofImage areaImage;
    ofSoundPlayer areaMusic;
    ofImage areaStage;
    ofPoint entrancePosition;
    std::vector<Enemy *> enemies;
    std::vector<Friend *> friends;
    Area *nextArea;
    std::vector<ImmovableEntity *> immovableEntities;
    bool drainHealth;

   public:
    Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<ImmovableEntity *> immovableEntities,vector<Friend *>friends);
    Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<ImmovableEntity *> immovableEntities, bool drainHealth, vector<Friend *>friends);
    void resetEnemies();
    string getName() { return name; }
    ofImage getImage() { return areaImage; }
    ofSoundPlayer getMusic() { return areaMusic; }
    ofImage getStage() { return areaStage; }
    ofPoint getEntrancePos() { return entrancePosition; }
    vector<Enemy *> getEnemies() { return enemies; }
    vector<Friend *> getFriends(){return friends;}
    vector<ImmovableEntity *> getImmovableEntities() { return immovableEntities; }
    int getRemainingEnemies();
    bool isDrainHealth(){return drainHealth; }
    Area *getNextArea() { return nextArea; }
    void setName(string name) { this->name = name; }
    void setEnemies(std::vector<Enemy *> enemies) { this->enemies = enemies; }
};