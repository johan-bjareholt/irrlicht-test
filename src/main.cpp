#include <irrlicht.h>

#ifdef _IRR_ANDROID_PLATFORM_

#include <android_native_app_glue.h>
#include "android_tools.h"
#include "android/window.h"

#endif

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



#include "main.h"
// Irrlicht device
IrrlichtDevice* device;
// Video Driver
IVideoDriver* driver;
// Scene Manager, holds all assets to be rendered
scene::ISceneManager* smgr;
// GUIEnvironment, 2d top graphics
gui::IGUIEnvironment* guienv;
// Logger
ILogger* logger;
// Filesystem
IFileSystem* fs;

#include "timer.h"
// Global timer variable
Timer* timer;
#include "events.h"
#include "mesh.h"
#include "scene.h"
// Global currentScene variable
Scene* currentScene;
#include "scenes/mainmenu.h"



#ifdef _IRR_ANDROID_PLATFORM_
int mainloop(android_app* app)
#else
int mainloop()
#endif
{	
	/*
		Settings
	*/
	SIrrlichtCreationParameters param;

	param.LoggingLevel = ELL_DEBUG;

	// Video settings
	param.Bits = 24;
	param.ZBufferBits = 16;
	param.AntiAlias  = 0;
	param.Vsync = false;
	param.Fullscreen = false;
	param.Stencilbuffer = false;
	param.EventReceiver = &eventReceiver;
	#ifdef _IRR_ANDROID_PLATFORM_
	param.DriverType = EDT_OGLES2;
	param.WindowSize = dimension2d<u32>(0,0);	// using 0,0 it will automatically set it to the maximal size
	param.PrivateData = app;
	#else
	param.DriverType = video::EDT_OPENGL;
	param.WindowSize = dimension2d<u32>(640,480);
	#endif

	// Create video device
	device = createDeviceEx(param);
	if (!device)
		return -1;

	// Gets the video driver
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();
	logger = device->getLogger();
	fs = device->getFileSystem();

	logger->log("Irrlicht device is created");

	/*

		Android specifics
	
	*/
	#ifdef _IRR_ANDROID_PLATFORM_
	// Create native android window
	ANativeWindow* nativeWindow = static_cast<ANativeWindow*>(driver->getExposedVideoData().OGLESAndroid.Window);

	/* Get display metrics. We are accessing the Java functions of the JVM directly in this case as there is no NDK function for that yet.
	   Checkout android_tools.cpp if you want to know how that is done. */
	irr::android::SDisplayMetrics displayMetrics;
	memset(&displayMetrics, 0, sizeof displayMetrics);
	irr::android::getDisplayMetrics(app, displayMetrics);

	// The Android assets file-system does not know which sub-directories it has (blame google).
	// So we have to add all sub-directories in assets manually. Otherwise we could still open the files, 
	// but existFile checks will fail (which are for example needed by getFont).
	for ( u32 i=0; i < fs->getFileArchiveCount(); ++i )
	{
		IFileArchive* archive = fs->getFileArchive(i);
		if ( archive->getType() == EFAT_ANDROID_ASSET )
		{
			archive->addDirectoryToFileList("./");
			break;
		}
	}
	#endif 
	// Exiting android specifics

    IGUISkin* skin = guienv->getSkin();
    IGUIFont* font = guienv->getFont("assets/fonts/fontlucida.png");
    if (font)
        skin->setFont(font);
    skin->setFont(guienv->getBuiltInFont(), EGDF_TOOLTIP);

	// Create scene
	currentScene = new MainMenuScene();
	// Create and start timer
	timer = new Timer();

	wchar_t windowcaption[75];
	const f32 MOVEMENT_SPEED = 5.f;
	//ITimer* timer = device->getTimer();
	//timer->getTime();
	logger->log("Entering game loop");
	while(device->run())
	{
		if (device->isWindowActive()){
			// Start frame
			driver->beginScene(true, true, SColor(0,100,100,130));
			// Check for held down keys and such
			currentScene->inputLoop();
			// For frame dependent game logic
			currentScene->logicsLoop();
			// Draw 3d
			smgr->drawAll();
			// Draw gui
			guienv->drawAll();

			// End frame
			driver->endScene();

			swprintf(windowcaption, 75, L"Johans Irrlicht Demo - FPS: %i", timer->getFPS() );
			device->setWindowCaption(windowcaption);
		}
		device->yield();
		timer->update();
	}
	device->drop();

	return 0;
}

#ifdef _IRR_ANDROID_PLATFORM_
void android_main(android_app* app)
{
	app_dummy();
	mainloop(app);
}
#else
int main(){

	mainloop();

	return 0;
}
#endif