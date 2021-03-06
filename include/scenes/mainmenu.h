#ifndef SCENE_MAINMENU_H
#define SCENE_MAINMENU_H

#include "scene.h"

using namespace irr;

class MainMenuScene : public Scene {
	irr::scene::ICameraSceneNode* camera;
public:
	MainMenuScene ();
	virtual void logicsLoop();

	virtual void getEvent(const SEvent&);
	virtual void inputLoop();
};

#endif