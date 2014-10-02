#include <irrlicht.h>

using namespace irr;
using namespace scene;

#include "main.h"
#include "mesh.h"

/*

	Mesh baseclass

*/

Mesh::Mesh (const char* modelfile) {
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



AnimatedMesh::AnimatedMesh (const char* modelfile) : Mesh (modelfile){
	
}
void AnimatedMesh::startAnimation () {
	
}