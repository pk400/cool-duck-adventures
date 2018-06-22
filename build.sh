#! /bin/bash

g++ -std=c++0x -o run -framework SFML -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system Main.cpp src/Game.cpp src/GSM.cpp src/MenuState.cpp src/Player.cpp src/PlayState.cpp