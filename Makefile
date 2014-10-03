
#Info
NAME=game
VERSION_MAJOR=0
VERSION_MINOR=0
VERSION_PATCH=1
BRANCH=git


CXX      = g++

FILES		= main timer events mesh scene scenes/mainmenu scenes/gamescene
OBJFILES	= $(patsubst %,obj/%.o,$(FILES))
CPPFILES	= $(patsubst %,src/%.cpp,$(FILES))

CPPFLAGS  = --std=c++11
INCLUDE_DIRS := ./include ./libs/irrlicht/include
LIBRARIES 	 := Irrlicht

CPPFLAGS  += $(foreach includedir,$(INCLUDE_DIRS),-I$(includedir))
LDFLAGS   += $(foreach library,$(LIBRARIES),-l$(library))


all: setup compile link

setup:
	mkdir -p bin
	mkdir -p obj
	mkdir -p obj/scenes

compile: ${OBJFILES}

link:
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(OBJFILES) -o bin/$(NAME)

obj/%.o: src/%.cpp
	$(CXX) -c $(LDFLAGS) $(CPPFLAGS) -o $@ $<


android:
	# Compiling irrlicht opengl-es
	ndk-build --directory ./libs/irrlicht-gles/src/Android
	# Build android native binaries
	ndk-build --directory ./Android
	# 
	cd ./Android ; ant debug


clean:
	rm -r obj bin

.PHONY: all setup link android clean
