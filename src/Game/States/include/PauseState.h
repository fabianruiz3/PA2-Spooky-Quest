#pragma once

#include "State.h"

class PauseState : public State{
    private:
    ofImage PauseScreen;

    public:
    PauseState();
    void draw();
    void keyPressed(int key);
    void update();
    void reset();

};