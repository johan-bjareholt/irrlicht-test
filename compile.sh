#!/bin/bash
LIBRARIES="-lIrrlicht"
INCLUDES="-I./libs/irrlicht-1.8.1/include"
g++ -std=c++11 -o bin/game -lIrrlicht $LIBRARIES $INCLUDES src/main.cpp
