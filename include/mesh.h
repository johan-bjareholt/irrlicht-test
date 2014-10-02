/*

	Mesh baseclass

*/


class Mesh {
	IMesh* mesh;
	IMeshSceneNode* node;
public:
	Mesh (const char* modelfile);
	void addToScene ();
};

/*

	Animated mesh baseclass

*/

class AnimatedMesh : public Mesh {
	IAnimatedMesh* mesh;
	IAnimatedMeshSceneNode* node;
public:
	AnimatedMesh (const char* modelfile);
	void startAnimation ();
};