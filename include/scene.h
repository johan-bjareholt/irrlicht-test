class Scene {
	// Scene Manager
	scene::ISceneManager* smgr;
	scene::ICameraSceneNode* camera;
	// GUIEnvironment
	gui::IGUIEnvironment* guienv;
public:
	Scene ();

	void graphicsLoop();

	void getEvent();
	void inputLoop();
};

extern Scene* currentScene;