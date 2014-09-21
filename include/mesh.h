/*

	Mesh baseclass

*/


class Mesh {
	IMesh* mesh;
	IMeshSceneNode* node;
	scene::ISceneManager* smgr;
public:
	Mesh (scene::ISceneManager* smgr, const char* modelfile);
	void addToScene ();
};

/*

	Animated mesh baseclass

*/

class AnimatedMesh : public Mesh {
	IAnimatedMesh* mesh;
	IAnimatedMeshSceneNode* node;
public:
	AnimatedMesh (scene::ISceneManager* smgr, const char* modelfile);
	void startAnimation ();
};