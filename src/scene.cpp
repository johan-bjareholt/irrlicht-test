#include <irrlicht.h>

using namespace irr;

using namespace scene;
using namespace gui;

#include "main.h"
#include "timer.h"
#include "events.h"
#include "mesh.h"

#include "scene.h"


Scene* currentScene;

Scene::Scene () {
	guienv->addStaticText(L"Hello World! This is the Irrlicht OpenGL renderer!",
		core::rect<s32>(10,10,260,22), false, true, 0, -1, true);
/*
	AnimatedMesh* box = new AnimatedMesh(smgr,"./assets/models/box/box.b3d");
	box->addToScene();
	box->startAnimation();
*/
	// Camera
	camera = smgr->addCameraSceneNodeFPS(0,100,5);
	camera->setFOV(45.0f*180.0f/irr::core::DEGTORAD);
	camera->setFarValue(1200000.0f);
	camera->setPosition(core::vector3df(0,10,-30));
	camera->setInputReceiverEnabled(false);
}

void Scene::graphicsLoop(){
	// Draw 3d
	smgr->drawAll();
	// Draw gui
	guienv->drawAll();
}

void Scene::getEvent(){

}

void Scene::inputLoop(){
	const f32 MOVEMENT_SPEED = 5.f;
	core::vector3df nodePosition = camera->getPosition();

	if(eventReceiver.IsKeyDown(irr::KEY_KEY_W))
		nodePosition.Y += MOVEMENT_SPEED * timer->frameDeltaTime();
	else if(eventReceiver.IsKeyDown(irr::KEY_KEY_S))
		nodePosition.Y -= MOVEMENT_SPEED * timer->frameDeltaTime();

	if(eventReceiver.IsKeyDown(irr::KEY_KEY_A))
		nodePosition.X -= MOVEMENT_SPEED * timer->frameDeltaTime();
	else if(eventReceiver.IsKeyDown(irr::KEY_KEY_D))
		nodePosition.X += MOVEMENT_SPEED * timer->frameDeltaTime();

	camera->setPosition(nodePosition);
}