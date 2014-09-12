#include <irrlicht.h>

#include <iostream>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

// Irrlicht device
IrrlichtDevice *device;
// Video Driver
IVideoDriver* driver;
// Scene Manager
ISceneManager* smgr;
// GUIEnvironment
IGUIEnvironment* guienv;



class Logger : public ILogger {};

class Timer {
private:
	u32 now;
	u32 then;
	long framec;
public:
	Timer() {
		framec = 0;
		update();
	}
	void update(){
		then = now;
		now = device->getTimer()->getTime();
		framec++;
	}
	int getFPS(){
		return driver->getFPS();
	}
	u32 frameDeltaTime() {
		return (f32)(now - then) / 1000.f;
	}
	u32 frameDeltaTimeMs() {
		return (f32)(now - then);
	}
};

class EventReceiver : public IEventReceiver
{
private:
	 bool KeyIsDown[KEY_KEY_CODES_COUNT];
public:
	virtual bool OnEvent(const SEvent& event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			if (event.KeyInput.PressedDown)
			{
				switch(event.KeyInput.Key){
					case KEY_SPACE:{

					}
					case KEY_ESCAPE:{
						device->closeDevice();
					}
					default:
						return true;
				}
			}
		}
	}
    virtual bool IsKeyDown(EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
    
    EventReceiver()
    {
        for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }
};

// EventReceiver
EventReceiver eventReceiver;



class Mesh {
	IMesh* mesh;
	IMeshSceneNode* node;
public:
	Mesh (const char* modelfile) {
		mesh = smgr->getMesh(modelfile);
		if (!mesh)
		{
			device->drop();
			return;
		}
	}
	void addToScene () {
		node = smgr->addMeshSceneNode( mesh );
		node->setMaterialFlag(EMF_LIGHTING, false);
	}
};

class AnimatedMesh : public Mesh {
	IAnimatedMesh* mesh;
	IAnimatedMeshSceneNode* node;
public:
	AnimatedMesh (const char* modelfile) : Mesh (modelfile){
		
	}
	void startAnimation () {
		
	}
};

int load(){
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
	// Scene Manager, holds all assets to be rendered
	smgr = device->getSceneManager();
	// GUIEnvironment, 2d top graphics
	guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht OpenGL renderer!",
		rect<s32>(10,10,260,22), false, true, 0, -1, true);

	AnimatedMesh box = AnimatedMesh("./assets/models/box/box.b3d");
	box.addToScene();
	box.startAnimation();

	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
}

void loop(){
	Timer timer = Timer();
	wchar_t windowcaption[75];
	while(device->run())
	{
		// Start frame
		driver->beginScene(true, true, SColor(255,100,101,140));

		// Work
		smgr->drawAll();
		guienv->drawAll();

		// End frame
		driver->endScene();
		timer.update();
		swprintf(windowcaption, 75, L"Johans Irrlicht Demo - FPS: %i", timer.getFPS() );
		device->setWindowCaption(windowcaption);
	}
	device->drop();
}

int main(){
	if (load())
		loop();
	return 0;
}