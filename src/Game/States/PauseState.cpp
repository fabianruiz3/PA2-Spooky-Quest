#include "PauseState.h"

PauseState::PauseState(){
    PauseScreen.load("images/ui/PauseScreen.png");
    currentState = "Pause";
}

void PauseState::draw(){
    ofSetBackgroundColor(0,0,0);
    PauseScreen.draw((ofGetWidth()/2)-100, (ofGetHeight()/2)-100,200,200);
}

void PauseState::keyPressed(int key){
    if(key == OF_KEY_ESC){
        setNextState(getPreviousState());
        setFinished(true);
    }
}

void PauseState::update(){}
void PauseState::reset(){}
