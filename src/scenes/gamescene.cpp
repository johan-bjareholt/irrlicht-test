#include "main.h"


#include "scene.h"
#include "scenes/gamescene.h"

#include "main.h"
#include "timer.h"
#include "events.h"
#include "mesh.h"

using namespace irr;

using namespace scene;
using namespace gui;

GameScene::GameScene () : Scene () {
	guienv->addStaticText(L"You are now in-game, move around with WASD.",
		core::rect<s32>(10,10,400,30), false, true, 0, -1, true);
	guienv->addEditBox(L"Editable Text", rect<s32>(10, 50, 400, 80));

	Mesh* box = new AnimatedMesh("./assets/models/box/box.b3d");
	box->addToScene();

	// Camera
	camera = smgr->addCameraSceneNodeFPS(0,100,5);
	camera->setFOV(45.0f*180.0f/irr::core::DEGTORAD);
	camera->setFarValue(1200000.0f);
	camera->setPosition(core::vector3df(0,10,-30));
	camera->setInputReceiverEnabled(false);
}

void GameScene::logicsLoop(){
	
}

void GameScene::getEvent(const SEvent& event){
	switch(event.EventType){
		case irr::EET_KEY_INPUT_EVENT:
			if (event.KeyInput.PressedDown)
			{
				switch(event.KeyInput.Key)
				{
					case KEY_SPACE:{
						logger->log("You pressed space");
						break;
					}
					case KEY_ESCAPE:{
						device->closeDevice();
						break;
					}
				}
				return;
			}
		default:
			break;
	}
}

void GameScene::inputLoop(){
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