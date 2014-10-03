#ifndef SCENE_GAMESCENE_H
#define SCENE_GAMESCENE_H

#include "scene.h"

using namespace irr;

class GameScene : public Scene {
	irr::scene::ICameraSceneNode* camera;
public:
	GameScene ();
	virtual void logicsLoop();

	virtual void getEvent(const SEvent&);
	virtual void inputLoop();
};

#endif