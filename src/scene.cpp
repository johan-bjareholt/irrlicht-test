#include <irrlicht.h>

using namespace irr;

using namespace scene;
using namespace gui;

#include "main.h"
#include "timer.h"
#include "events.h"
#include "mesh.h"

#include "scene.h"


Scene::Scene () {
	smgr->clear();
	guienv->clear();
}