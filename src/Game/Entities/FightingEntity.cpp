#include "FightingEntity.h"

FightingEntity::FightingEntity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage) : Entity( ox, oy, ow, oh) {
    this->fx = fx;
    this->fy = fy;
    this->fh = fh;
    this->fw = fw;
    this->health = health;
    this->baseDamage = baseDamage;
}

FightingEntity::~FightingEntity(){}

void FightingEntity::inOverworldDraw() {
    overworldSprite.draw(ox, oy, ow, oh);
}

void FightingEntity::fightingDraw() {
    fightingSprite.draw(fx, fy, fw, fh);
}
