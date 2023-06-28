# PA2-Spooky-Quest
Welcome to the PA2-Spooky-Quest repository! This repository contains a 2D top-down strategy game developed as part of the Advanced Programming Course (CIIC4010) Programming Assignment at UPRM. The game was developed using OpenFrameworks.

## Setup
1. Clone this project inside an OpenFrameworks installation's "apps/myApps/" directory
   
2. Open a terminal and navigate to the project directory.
   
3. Run the following command to compile the program:
```make```

4. Once the compilation is complete, run the following command to execute the program:
```make run```


## Game Description
Spooky Quest is a strategy game where the player navigates through different areas and engages in battles with enemies. The objective is to defeat all enemies in each area, including boss battles, to progress to the next area or win the game.

## How to Play
- Use the <kbd>W</kbd>, <kbd>A</kbd>, <kbd>S</kbd>, and <kbd>D</kbd> to move the player character.
- Collide with enemies to engage in Rock, Paper, Scissors battles to defeat them.
- Press <kbd>e</kbd> to interact with Friends and trigger speech text or interaction indicators.
- Press <kbd>ESC</kbd> to enter the Pause State during Battle or Overworld States.
- In the Pause State, press <kbd>ESC</kbd> again to exit the Pause State.

##  Debugging
- Press <kbd>h</kbd> to reset the player's health to full.
- Press <kbd>b</kbd> to spawn the Boss in the current Area.
- Pressing <kbd>r</kbd> respawns all defeated enemies in current Area.

## Entities

### Friends
Players can interact with Friends by colliding with them and pressing the <kbd>e</kbd> key.
Interacting with a Friend triggers speech text to appear on the screen or some other interaction indicator.

### Enemy
Normal enemies are represented as entities that move around the game area.
They engage in battles with the player character using the Rock, Paper, Scissors mechanism.

### Boss
Bosses appear in an Area after defeating all other Enemies in that area.
Boss battles consist of two phases, requiring the player to deplete the Boss's health bar twice to defeat them.
Defeating a Boss allows the player to progress to the next Area or triggers a win state if there are no remaining Areas.

### Immovable
Immobile entities, such as rocks, do not move or have any interaction.
The player cannot move through immovable entities when colliding with them.

## Student Information
Fabian J. Ruiz Gomez
- Email: fabian.ruiz3@upr.edu
- GitHub username: fabianruiz3

Dahyna G. Martínez Pérez
- Email: dahyna.martinez@upr.edu
- Github username: Dahyna-Martinez
