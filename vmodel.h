#ifndef VMODEL_H
#define VMODEL_H

#include "vobject.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

class vModel : public vObject
{
public:

    float *vertexArray;
    float *normalArray;
    float *uvArray;
    unsigned int numVerts;
    unsigned int idTexture;

    vModel();
    void draw();
    void init();
    void loadTexture(const char *filename);
};

#endif // VMODEL_H
