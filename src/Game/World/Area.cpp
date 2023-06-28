#include "Area.h"

Area::Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<ImmovableEntity *> immovableEntities, vector<Friend *>friends) {
    this->name = name;
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->immovableEntities = immovableEntities;
    this->drainHealth = false;
    this->friends = friends;
}

Area::Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<ImmovableEntity *> immovableEntities, bool drainHealth,vector<Friend *>friends) {
    this->name = name;
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->immovableEntities = immovableEntities;
    this->drainHealth = drainHealth;
    this->friends= friends;
}

void Area::resetEnemies() {
    for (unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
        enemies.at(i)->reset();
    }
}

int Area::getRemainingEnemies() {
    int count = 0;
    for (unsigned int i = 0; i < enemies.size(); i++)
        if (!enemies.at(i)->isDead())
            count++;

    return count;
}
