#include <irrlicht.h>

using namespace irr;
using namespace scene;

#include "main.h"
#include "mesh.h"

/*

	Mesh baseclass

*/

Mesh::Mesh (scene::ISceneManager* smgr, const char* modelfile) {
	this->smgr = smgr;
	mesh = smgr->getMesh(modelfile);
	if (!mesh)
	{
		device->drop();
		return;
	}
}
void Mesh::addToScene () {
	node = smgr->addMeshSceneNode( mesh );
	node->setMaterialFlag(video::EMF_LIGHTING, false);
}


/*

	Animated mesh baseclass

*/



AnimatedMesh::AnimatedMesh (scene::ISceneManager* smgr, const char* modelfile) : Mesh (smgr,modelfile){
	
}
void AnimatedMesh::startAnimation () {
	
}