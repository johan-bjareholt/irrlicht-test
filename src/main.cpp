#include <irrlicht.h>

#include <iostream>


using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



#include "main.h"
// Irrlicht device
IrrlichtDevice *device;
// Video Driver
IVideoDriver* driver;

#include "timer.h"
#include "events.h"
#include "mesh.h"
#include "scene.h"

int main(){
	// Settings
	bool fullscreen = false;
	bool stencilbuffer = false;
	bool vsync = false;

	// Create video device
	device =
		createDevice( video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
			fullscreen, stencilbuffer, vsync, &eventReceiver);
	if (!device)
		return -1;

	// Gets the video driver
	driver = device->getVideoDriver();

	// Create scene
	currentScene = new Scene();

	timer = new Timer();
	wchar_t windowcaption[75];
	const f32 MOVEMENT_SPEED = 5.f;
	while(device->run())
	{
		// Start frame
		driver->beginScene(true, true, SColor(255,100,101,140));

		// Work
		currentScene->inputLoop();
		currentScene->graphicsLoop();

		// End frame
		driver->endScene();

		timer->update();
		swprintf(windowcaption, 75, L"Johans Irrlicht Demo - FPS: %i", timer->getFPS() );
		device->setWindowCaption(windowcaption);
	}
	device->drop();

	return 0;
}