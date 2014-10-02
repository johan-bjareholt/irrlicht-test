#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <irrlicht.h>

/*
	Template scene
*/

class Scene {
public:
	Scene () {};

	virtual void logicsLoop() {};

	virtual void getEvent() {};
	virtual void inputLoop() {};
};

extern Scene* currentScene;

#endif