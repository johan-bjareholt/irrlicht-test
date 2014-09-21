
#Info
NAME=game
VERSION_MAJOR=0
VERSION_MINOR=0
VERSION_PATCH=1
BRANCH=git


CC      = g++
SOURCE  = src/main.cpp src/timer.cpp src/events.cpp src/mesh.cpp src/scene.cpp
CFLAGS  = --std=c++11 -I./include -I./libs/irrlicht-1.8.1/include
LDFLAGS = -lIrrlicht

all: compile

.PHONY: compile
compile:
	$(CC) -o bin/$(NAME) $(CFLAGS) $(LDFLAGS) $(SOURCE)

main.o: main.cpp main.h
	$(CC) -o $@ $(CFLAGS) $<

.PHONY: clean cleanest

clean:
	rm *.o
