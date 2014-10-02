#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <irrlicht.h>


// Irrlicht device
extern irr::IrrlichtDevice *device;
// Video Driver
extern irr::video::IVideoDriver* driver;
// Scene Manager, holds all assets to be rendered
extern irr::scene::ISceneManager* smgr;
// GUIEnvironment, 2d top graphics
extern irr::gui::IGUIEnvironment* guienv;
// Logger
extern irr::ILogger* logger;
// Filesystem
extern irr::io::IFileSystem* fs;

#endif