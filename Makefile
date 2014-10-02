
#Info
NAME=game
VERSION_MAJOR=0
VERSION_MINOR=0
VERSION_PATCH=1
BRANCH=git


CC      = g++
SOURCE  = src/main.cpp src/timer.cpp src/events.cpp src/mesh.cpp src/scene.cpp src/scenes/mainmenu.cpp
OBJECTS	= ${SOURCE:.c=.o}
CFLAGS  = --std=c++11 -I./include -I./libs/irrlicht/include
LDFLAGS = -lIrrlicht

all:
	mkdir -p ./bin
	$(CC) -g -o bin/$(NAME) $(CFLAGS) $(LDFLAGS) $(SOURCE)

all-test: compile link

compile: ${SOURCE}
	echo ${SOURCE}
	#$(CC) -c $@ $(CFLAGS) $< ${SRC}

android:
	# Compiling irrlicht opengl-es
	ndk-build --directory ./libs/irrlicht-gles/src/Android/
	ndk-build --directory ./Android
	cd ./Android ; ant debug

link: ${OBJECTS}
	echo ${OBJECTS}
	#$(CC) -o $@ $(CFLAGS) ${OBJ}

clean:
	rm *.o

.PHONY: all compile link clean
