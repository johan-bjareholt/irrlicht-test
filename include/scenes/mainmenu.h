#include "scene.h"


class MainMenuScene : public Scene {
	irr::scene::ICameraSceneNode* camera;
public:
	MainMenuScene ();

	void logicsLoop();

	void getEvent();
	void inputLoop();
};