#pragma once

#include "Entity.h"


class ImmovableEntity : public Entity {
    private:
        string id;
        string entityName;
        string spriteImagePath;
        int renderX = 1000;
        int renderY = 1000;

    public:
        ImmovableEntity(int ox, int oy, int ow, int oh, string id, string entityName, string spriteImagePath);
        void inOverworldDraw();
        void inOverworldUpdate();
        void setRenderX(int x) { renderX = x; };
        void setRenderY(int y) { renderY = y; };
};