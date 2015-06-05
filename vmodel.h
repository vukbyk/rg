#ifndef VMODEL_H
#define VMODEL_H

#include "vobject.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class vModel : public vObject
{
public:

    float *vertexArray;
    float *normalArray;
    float *uvArray;
    int numVerts;

    vModel();
    void draw();
    void init();
};

#endif // VMODEL_H
