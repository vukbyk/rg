#include "vmodel.h"

vModel::vModel()
{
    Assimp::Importer importer;
    //aiProcessPreset_TargetRealtime_Fast has the configs you'll need
    const aiScene *scene = importer.ReadFile("../models/flyingmachine.obj", aiProcessPreset_TargetRealtime_Fast);
    //assuming you only want the first mesh
    aiMesh *mesh = scene->mMeshes[0];

    numVerts = mesh->mNumFaces*3;

    vertexArray = new float[mesh->mNumFaces*3*3];
    normalArray = new float[mesh->mNumFaces*3*3];
    uvArray = new float[mesh->mNumFaces*3*2];

    for(unsigned int i=0;i<mesh->mNumFaces;i++)
    {
    const aiFace& face = mesh->mFaces[i];

        for(int j=0;j<3;j++)
        {
            aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
            memcpy(uvArray,&uv,sizeof(float)*2);
            uvArray+=2;

            aiVector3D normal = mesh->mNormals[face.mIndices[j]];
            memcpy(normalArray,&normal,sizeof(float)*3);
            normalArray+=3;

            aiVector3D pos = mesh->mVertices[face.mIndices[j]];
            memcpy(vertexArray,&pos,sizeof(float)*3);
            vertexArray+=3;
        }
    }

    uvArray-=mesh->mNumFaces*3*2;
    normalArray-=mesh->mNumFaces*3*3;
    vertexArray-=mesh->mNumFaces*3*3;



}

void vModel::draw()
{

//    init();

    glLoadMatrixf(&tm[0][0]);
//    glBegin(GL_TRIANGLES);
//        glColor3f(1,.5,0);
//        for(int i=0; i < numVerts*3; i+=3)
//        {
//            glNormal3f(normalArray[i],normalArray[i+1],normalArray[i+2]);
//            glVertex3f(vertexArray[i],vertexArray[i+1],vertexArray[i+2]);
//        }
//    glEnd();
    glCallList(1);

}

void vModel::init()
{
    loadTexture("../models/flyingmachine_FLYINGMACHINECREATURE.png");
    glNewList(1, GL_COMPILE);
        glBegin(GL_TRIANGLES);
//            glColor3f(1,.5,0);
//        glMaterialfv();
            for(int i=0; i < numVerts; i++)
            {
                glTexCoord2d(uvArray[2*i], uvArray[2*i+1]);
                glNormal3f(normalArray[3*i],normalArray[3*i+1],normalArray[3*i+2]);
                glVertex3f(vertexArray[3*i],vertexArray[3*i+1],vertexArray[3*i+2]);
            }
        glEnd();
    glEndList();
}

void vModel::loadTexture(const char* filename)
{
        SDL_Surface* img = IMG_Load(filename);
        if (!img)
        {
            printf("Error: \"%s\"\n",SDL_GetError());
        }
        glGenTextures(1, &idTexture);
        glBindTexture(GL_TEXTURE_2D, idTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_INT_8_8_8_8, img->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        SDL_FreeSurface(img);
}
