#include "RenderObjects.h"
#include "Input.h"
#include "libs.h"
#include "Camera.h"
#include "Camera2.h"
#include "Text.h"
#include "Engine.h"
#include <windows.h>
#include <mmsystem.h>
#include "ImageLoader.h"
#include "AudioManager.h"
#include "Collider.h"
#include <thread>
#include <atomic>
#include <mutex>
#include "RotationObject.h"

const Vector3 gravity (0.0f, -0.1f, 0.0f);
float value = 0.0f;
float rotateAngle = 0.0f;
Vector3 playerPosition(0, 0, 0);
Vector3 playerRotation(0, 0, 0);
float playerAngle = 0.0f;
//RenderObjects player;
RenderObjects otherObject;
RenderObjects fly[5];
camera cam;
//Enemy Test
RenderObjects floorz;
//camera cam;
// Create game objects with colliders
RenderObjects player;
RenderObjects obstacle;
RenderObjects ground;

int GlobalScore = 0;

//GLuint loadTexture(Image* image) {
//    GLuint textureId;
//    glGenTextures(1, &textureId); //Make room for our texture
//    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
//    //Map the image to the texture
//    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
//        0,                            //0 for now
//        GL_RGB,                       //Format OpenGL uses for image
//        image->width, image->height,  //Width and height
//        0,                            //The border of the image
//        GL_RGB, //GL_RGB, because pixels are stored in RGB format
//        GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
//        //as unsigned numbers
//        image->pixels);               //The actual pixel data
//    return textureId; //Returns the id of the texture
//}
GLuint _textureId; //The id of the texture

void InitiateRender()
{
        /*glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);*/

		_textureId = InitializeTexture("vtr4.bmp");
}

void Initialize()
{

}

RenderObjects ObjTest1, ObjTest_2, Goober;
float movementSpeed = 0.01f;
Vector3 FloorcolliderScale(20.0f, 0.5f, 20.0f);
RenderObjects frogPart1, frogPart2, frogPart3, frogPart4, frogEye1, frogEye2, frogEye3, frogEye4;

void Squegee()
{
    //=======FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===
    Color frogGreen(0, 255, 100);
    Color frogEyeGreen(0, 255, 150);
    Color WhiteEyes(255, 255, 255);
    Color BlackEyes(0, 0, 0);
    frogPart1.TransformObjectPosition(0, 10, 0);
    frogPart1.TransformObjectRotation(Rotation::camYaw, 0, 1, 0);
    frogPart1.Apply_Color(frogGreen);
    frogPart1.SetCollider(frogPart1.GetObjectPosition(), Vector3(3, 3, 3));
    frogPart1.Create3DSphere(5, 15, 15);

    frogPart2.TransformObjectPosition(3.5f, 3, 0);
    frogPart2.Apply_Color(frogEyeGreen);
    frogPart2.Create3DSphere(2, 15, 15);

    frogPart3.TransformObjectPosition(0, 3, 3.5f);
    frogPart3.Apply_Color(frogEyeGreen);
    frogPart3.Create3DSphere(2, 15, 15);

    frogPart4.TransformObjectPosition(2, 1, 2);
    frogPart4.Apply_Color(frogGreen);
    frogPart4.Create3DSphere(4, 15, 15);

    frogEye1.TransformObjectPosition(4.5f, 3, 0);
    frogEye1.Apply_Color(WhiteEyes);
    frogEye1.Create3DSphere(1.5, 15, 15);

    frogEye2.TransformObjectPosition(5, 3, 0.3);
    frogEye2.Apply_Color(BlackEyes);
    frogEye2.Create3DSphere(1.3, 15, 15);

    frogEye3.TransformObjectPosition(0, 3, 4.5f);
    frogEye3.Apply_Color(WhiteEyes);
    frogEye3.Create3DSphere(1.5, 15, 15);

    frogEye4.TransformObjectPosition(0.3, 3, 5);
    frogEye4.Apply_Color(BlackEyes);
    frogEye4.Create3DSphere(1.3, 15, 15);

    frogPart2.SetParent(&frogPart1);
    frogPart3.SetParent(&frogPart1);
    frogPart4.SetParent(&frogPart1);
    frogEye1.SetParent(&frogPart1);
    frogEye2.SetParent(&frogPart1);
    frogEye3.SetParent(&frogPart1);
    frogEye4.SetParent(&frogPart1);


    if (Input::GetKey('w'))
    {
        frogPart1.TransformObjectRotation(90, 0, 90, 0);
    }
    if (Input::GetKey('a'))
    {
        frogPart1.TransformObjectRotation(180, 0, 180, 0);
    }
    if (Input::GetKey('s'))
    {
        frogPart1.TransformObjectRotation(270, 0, 270, 0);
    }
    if (Input::GetKey('d'))
    {
        frogPart1.TransformObjectRotation(360, 0, 360, 0);
    }
    //=======FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===
}

void AddScore()
{
    GlobalScore += 10;
}

void Update()
{
    //Don't put 3d objects above
    cam.ApplyCamera();

    ObjTest1.TransformObjectPosition(10.0f, 0.0f, 20.0f);
    ObjTest1.TransformObjectSize(-1.0f, 5.0f, 0.0f);
    ObjTest1.Apply_Color(255, 0, 0);
    ObjTest1.Create3DCube(2, 2, 5);
	ObjTest1.SetCollider(ObjTest1.GetColliderPosition(), ObjTest1.GetColliderScale());

    //EVERYTHING BELOW HERE IS LERP//
  /*  ObjTest_2.TransformObjectPosition(-10.0f, 0.01f, 0.0f);*/
    Vector3 toLERP = GetLERPObjects(ObjTest_2, ObjTest1, 0.1);
    
    //glPushMatrix();
    ObjTest_2.SetCollider(ObjTest_2.GetColliderPosition(), ObjTest_2.GetColliderScale());
    if (!ObjTest_2.CheckCollision(ObjTest1))
    {
        ObjTest_2.TrackPoint(movementSpeed, toLERP, ObjTest_2.GetColliderPosition(), ObjTest1.GetColliderPosition());
    }
    
    ObjTest_2.Apply_Color(0, 255, 0, 100);
    ObjTest_2.Create3DCylinder(4.0f, 4.0f, 8);

    Color GooberColor(255.0f, 255.0f, 255.0f);

    Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.005f);  // 8% per frame
    Goober.TransformObjectPosition(GooberLERP);

    //Goober.TransformObjectPosition(5.0f, 5.0f, 5.0f);
    Goober.TransformObjectSize(5.0f, 5.0f, 5.0f);
    Goober.SetCollider(Goober.GetColliderPosition(), Goober.GetColliderScale());
    Goober.Apply_Color(GooberColor);
    Goober.Create3DSphere(2.5f, 20.0f, 10.0f);

    if (!Goober.CheckCollision(frogPart1))
    {
        Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.005f);  // 8% per frame
        Goober.TransformObjectPosition(GooberLERP);
    }

    if (Goober.CheckCollision(frogPart1))
    {
        srand(time(NULL));
        int randomSpawn = rand() % 40;
        AddScore();
        Goober.TransformObjectPosition(randomSpawn*-1, 0, 10);
    }

    /*glPopMatrix();*/

 //   Text LERPx, LERPy, LERPz;
	//LERPx.ColorText(255.0f, 0.0f, 0.0f);
	//LERPx.TranslateText(-4.0f, 10.0f, 0.0f);
 //   LERPx.RenderVariableAsText(toLERP.x);

 //   LERPy.ColorText(0.0, 255.0f, 0.0f);
 //   LERPy.TranslateText(-4.0f, 11.0f, 0.0f);
 //   LERPy.RenderVariableAsText(toLERP.y);

	//LERPz.ColorText(0.0f, 0.0f, 255.0f);
	//LERPz.TranslateText(-4.0f, 12.0f, 0.0f);
 //   LERPz.RenderVariableAsText(toLERP.z);

    //==============================================

    //TEXT TEXT//
	Text ScoreWord, ScoreVariable, HitMarker;

    ScoreWord.ColorText(255.0f, 255.0f, 0.0f);
    ScoreWord.TranslateText(-45.0f, 0.0f, -20.0f);
    ScoreWord.RenderText("SCORE: ");

    ScoreVariable.ColorText(255.0f, 0.0f, 0.0f);
    ScoreVariable.TranslateText(-35.0f, 0.0f, -19.0f);
    ScoreVariable.RenderIntVariableAsText(GlobalScore);

    //rotateAngle += 1.0f;

    ////TEXTURE TEST //
    //StartEnablingTextures();
    //BindSelectTexture(_textureId);

    ////Bottom
    //RenderType(true, true);
    //glColor3f(1.0f, 0.2f, 0.2f);
    //glBegin(GL_QUADS);

    //glNormal3f(0.0, 1.0f, 0.0f);
    //glTexCoord2f(0.0f, 0.0f);
    //glVertex3f(-2.5f, -2.5f, 2.5f);
    //glTexCoord2f(1.0f, 0.0f);
    //glVertex3f(2.5f, -2.5f, 2.5f);
    //glTexCoord2f(1.0f, 1.0f);
    //glVertex3f(2.5f, -2.5f, -2.5f);
    //glTexCoord2f(0.0f, 1.0f);
    //glVertex3f(-2.5f, -2.5f, -2.5f);

    //glEnd();

    ////Back
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glBegin(GL_TRIANGLES);

    //glNormal3f(0.0f, 0.0f, 1.0f);
    //glTexCoord2f(0.0f, 0.0f);
    //glVertex3f(-2.5f, -2.5f, -2.5f);
    //glTexCoord2f(5.0f, 5.0f);
    //glVertex3f(0.0f, 2.5f, -2.5f);
    //glTexCoord2f(10.0f, 0.0f);
    //glVertex3f(2.5f, -2.5f, -2.5f);

    //glEnd();

    ////Left
    //glDisable(GL_TEXTURE_2D);
    //glColor3f(1.0f, 0.7f, 0.3f);
    //glBegin(GL_QUADS);

    //glNormal3f(1.0f, 0.0f, 0.0f);
    //glVertex3f(-2.5f, -2.5f, 2.5f);
    //glVertex3f(-2.5f, -2.5f, -2.5f);
    //glVertex3f(-2.5f, 2.5f, -2.5f);
    //glVertex3f(-2.5f, 2.5f, 2.5f);

    //glEnd();

    Squegee();
    //========================================================
    //  PLAYER OBJECT
    //Camera bound by playerPosition

    Vector3 colliderScale(10, 10, 10); 
    Vector3 colliderPos(0.0f, 5.0f, 0.0f);
    Color betterColorTest(255, 0.0f, 255);

    player.Create3DCone(5.0f, 10, 10);
    player.TransformObjectPosition(playerPosition);
    //Floor bound
    if(playerPosition.y > floorz.GetColliderPosition().y)
        playerPosition += gravity;

    player.Apply_Color(betterColorTest);
    player.SetCollider(player.GetColliderPosition() + colliderPos, colliderScale);
        if (Input::GetKey('d'))
        {
            /*Vector3 rightMovement(0.1f, 0, 0);
            playerPosition += rightMovement;*/
            Vector3 rightRotation(0.0f, 0, 5.0f);
            playerRotation += rightRotation;
            playerAngle += 1.0f;
        }
        if (Input::GetKey('a'))
        {
            /*Vector3 leftMovement(-0.1f, 0, 0);
            playerPosition += leftMovement;*/
            Vector3 leftRotation(0.0f, 0, -5.0f);
            playerRotation += leftRotation;
            playerAngle -= 1.0f;
        }
        if (Input::GetKey('w'))
        {
            Vector3 topMovement(0, 0.5f, 0);
            playerPosition += topMovement;
        }
        if (Input::GetKey('s'))
        {
            Vector3 downMovement(0, -0.1f, 0);
            playerPosition += downMovement;
        }
        if (player.CheckCollision(otherObject))
        {
            cout << "Collision detected!" << endl;
        }

        if (player.CheckCollision(floorz))
        {
            cout << "Collision detected!" << endl;
        }
    player.TransformObjectPosition(playerPosition);
    player.TransformObjectRotation(playerAngle, playerRotation);
    //================================================
    if (Input::GetKey('x'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (Input::GetKey('z'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    //=================================================    

    static bool initialized = false;
    if (!initialized)
    {
        otherObject.TransformObjectPosition(5.0f, 5.0f, 0.0f);
        otherObject.TransformObjectSize(2.0f, 2.0f, 2.0f);
        otherObject.TransformObjectRotation(0.0f, 0.0f, 0.0f, 1.0f);

        Vector3 colliderScale(2, 2, 2);
        otherObject.SetCollider(otherObject.GetColliderPosition(), colliderScale);

        initialized = true;
    }

    bool isColliding = player.CheckCollision(otherObject);

    if (isColliding)
        otherObject.Apply_Color(255.0f, 0.0f, 0.0f);
    else
        otherObject.Apply_Color(125.0f, 125.0f, 255.0f);

    Vector3 pos = otherObject.GetColliderPosition();
    Vector3 scale = otherObject.GetColliderScale();
    otherObject.TransformObjectPosition(pos.x, pos.y, pos.z);
    otherObject.TransformObjectSize(scale.x, scale.y, scale.z);
    otherObject.Create3DCube(1.0f, 1.0f, 1.0f);

    //Floor
   // floorz.Create3DCube(20.0f, 0.5f, 20.0f);
   // Vector3 floorPos = floorz.GetColliderPosition();
   // Vector3 floorScale = floorz.GetColliderScale();
   //floorz.TransformObjectPosition(0, -10.0f, 0);
   // floorz.SetCollider(floorz.GetColliderPosition(), FloorcolliderScale);
   
}

int main(int argc, char** argv)
{
    PlaySong(L"Majula.wav");
    PrepEngine(argc, argv);

    glutMotionFunc(Rotation::mouseMotion);
    glutPassiveMotionFunc(Rotation::mousePassiveMotion);
}



