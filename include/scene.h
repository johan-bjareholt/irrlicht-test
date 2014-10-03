#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <irrlicht.h>

using namespace irr;

/*
	Template scene
*/

class Scene {
public:
	Scene ();

	virtual void logicsLoop() {};

	virtual void getEvent(const SEvent&) {};
	virtual void inputLoop() {};
};

extern Scene* currentScene;

#endif