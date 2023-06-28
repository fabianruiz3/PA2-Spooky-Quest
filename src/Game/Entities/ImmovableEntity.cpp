#include "ImmovableEntity.h"


ImmovableEntity::ImmovableEntity(int ox, int oy, int ow, int oh, string id, string entityName, string spriteImagePath) : Entity(ox, oy, ow, oh){
    this->id = id;
    this->entityName = entityName;
    this->spriteImagePath = spriteImagePath;
    overworldSprite.load(spriteImagePath);
}

void ImmovableEntity::inOverworldDraw() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void ImmovableEntity::inOverworldUpdate(){

}