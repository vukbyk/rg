#include "mainwindow.h"
#include <QApplication>
#include <GL/glut.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include <stdio.h>
#include <string>

#include <QTimer>
//#include <QElapsedTimer>

#include <bullet/btBulletDynamicsCommon.h>


#include <vobject.h>
#include <vmodel.h>
#include <vrigidbody.h>
#include <camera.h>
#include <floorgrid.h>
#include <cube.h>
#include <vworld.h>

#include <iostream>

using namespace std;

//int main(int argc, char *argv[])
//{
//    glutInit(&argc, argv);
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

//Screen dimension constants
float screenWidth = 640;
float screenHeight = 480;

//Starts up SDL, creates window, and initializes OpenGL
bool init();

//Initializes matrices and clear color
bool initGL();

//Input handler
void handleKeys( unsigned char key, int x, int y );

//Per frame update
void update();

//Renders quad to the screen
void render();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//OpenGL context
SDL_GLContext gContext;

//Render flag
bool gRenderQuad = true;


//camera cam;
//cube k;
vRigidBody vrb;

bool init()
{

    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Use OpenGL 2.1
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create context
            gContext = SDL_GL_CreateContext( gWindow );
            if( gContext == NULL )
            {
                printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Use Vsync
                if( SDL_GL_SetSwapInterval( 1 ) < 0 )
                {
                    printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
                }

                //Initialize OpenGL
                if( !initGL() )
                {
                    printf( "Unable to initialize OpenGL!\n" );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool initGL()
{


    bool success = true;
    GLenum error = GL_NO_ERROR;

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }

    gluPerspective(45.0,screenWidth/screenHeight,1.0,500.0);

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }

    //Initialize clear color
//    glClearColor( 0.f, 0.f, 0.f, 1.f );

    glClearColor(.2,.2,.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float dif[]= {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);

    gluLookAt(0,2,-5, 0,0,0, 0,1,0);
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        success = false;
    }
    vrb.init();

    return success;
}

void handleKeys( unsigned char key, int x, int y )
{
    //Toggle quad
    if( key == 'q' )
    {
        gRenderQuad = !gRenderQuad;
    }
}

void update()
{
    //No per frame update needed
}

void render()
{
    //Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Render quad
//    if( gRenderQuad )
    {
//        k.draw();
        glLoadIdentity();
        float pos[]= {2, 2, 3, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        vrb.draw();
//        glBegin( GL_QUADS );
//            glColor3f(1.0,0.0,0.0);
//            glVertex2f( -0.5f, -0.5f );
//            glVertex2f( 0.5f, -0.5f );
//            glVertex2f( 0.5f, 0.5f );
//            glVertex2f( -0.5f, 0.5f );
//        glEnd();
    }
}

void close()
{
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* argv[] )
{
    glutInit(&argc, argv);//nece biti potrebno
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //Enable text input
        SDL_StartTextInput();

        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                //Handle keypress with current mouse position
                else if( e.type == SDL_TEXTINPUT )
                {
                    int x = 0, y = 0;
                    SDL_GetMouseState( &x, &y );
                    handleKeys( e.text.text[ 0 ], x, y );
                }

                if( e.type == SDL_WINDOWEVENT) // The window is resized
                {
                    if(e.window.event == SDL_WINDOWEVENT_RESIZED)
                    {

                        screenWidth  = e.window.data1;
                        screenHeight = e.window.data2;

                        glMatrixMode( GL_PROJECTION );
                        glViewport(0, 0, screenWidth, screenHeight);
                        glLoadIdentity();

                        gluPerspective(45.0,screenWidth/screenHeight,1.0,500.0);

    //                    glOrtho( 0, screenWidth, screenHeight, 0, -1, 1 );
                        glMatrixMode( GL_MODELVIEW );

//                        cout<<"Height "<<screenHeight <<" width "<< screenWidth<<endl;
                    }

                }
            }

            //Render quad
            render();

            //Update screen
            SDL_GL_SwapWindow( gWindow );

        }

        //Disable text input
        SDL_StopTextInput();
    }

    //Free resources and close SDL
    close();

    return 0;
}

