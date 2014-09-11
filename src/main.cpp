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
		//Mesh(modelfile);
	}
	void addToScene () {
		node = smgr->addAnimatedMeshSceneNode( mesh );
		node->setMaterialFlag(EMF_LIGHTING, false);
	}
	void addAnimation () {
		node->setMaterialTexture( 0, driver->getTexture("./assets/models/box/box.mtl") );
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
			fullscreen, stencilbuffer, vsync, 0);
	if (!device)
		return -1;

	device->setWindowCaption(L"Johans Irrlicht Demo");

	// Gets the video driver
	driver = device->getVideoDriver();
	// Scene Manager, holds all assets to be rendered
	smgr = device->getSceneManager();
	// GUIEnvironment, 2d top graphics
	guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht OpenGL renderer!",
		rect<s32>(10,10,260,22), false, true, 0, -1, true);

	Mesh box = Mesh("./assets/models/box/box.b3d");
	box.addToScene();

	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
}

void loop(){
	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}
	device->drop();
}

int main(){
	if (load())
		loop();
	return 0;
}