#include "main.h"


#include "scene.h"
#include "scenes/mainmenu.h"
#include "scenes/gamescene.h"

#include "main.h"
#include "timer.h"
#include "events.h"
#include "mesh.h"

using namespace irr;

using namespace scene;
using namespace gui;

MainMenuScene::MainMenuScene () : Scene () {
	guienv->addStaticText(L"Hello World! This is the Irrlicht OpenGL renderer!",
		core::rect<s32>(10,10,260,22), false, true, 0, -1, true);

	// Camera
	camera = smgr->addCameraSceneNodeFPS(0,100,5);
	camera->setFOV(45.0f*180.0f/irr::core::DEGTORAD);
	camera->setFarValue(1200000.0f);
	camera->setPosition(core::vector3df(0,10,-30));
	camera->setInputReceiverEnabled(false);
}

void MainMenuScene::logicsLoop(){
	
}

void MainMenuScene::getEvent(const SEvent& event){
	switch(event.EventType){
		case irr::EET_KEY_INPUT_EVENT:
			if (event.KeyInput.PressedDown)
			{
				switch(event.KeyInput.Key)
				{
					case KEY_SPACE:{
						logger->log("You pressed space");
						currentScene = new GameScene();
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

void MainMenuScene::inputLoop(){
}