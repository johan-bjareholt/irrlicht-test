class Scene {
	scene::ICameraSceneNode* camera;
public:
	Scene ();

	void graphicsLoop();

	void getEvent();
	void inputLoop();
};

extern Scene* currentScene;