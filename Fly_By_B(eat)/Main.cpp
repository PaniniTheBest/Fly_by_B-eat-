#include "Render_3D_Objects.h"
//#include "GameObject.h"
#include "Input.h"
#include "libs.h"
//#include "Camera.h"
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


float value = 0.0f;
float rotateAngle = 0.0f;
Vector3 playerPosition(0, 0, 0);
Vector3 playerRotation(0, 0, 0);
float playerAngle = 0.0f;
Render_3D_Objects player;
Render_3D_Objects otherObject;
camera2 cam2;
//camera cam;
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

Render_3D_Objects ObjTest1, ObjTest_2;
float movementSpeed = 0.01f;
void Update()
{
    Color color;
    float deltaTime = FindDeltaTime();
    value += (1.0f * deltaTime);

	if (value >= 15.0f)
	{
		PlaySong(L"yay.wav");
	}

    glutMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });
    glutPassiveMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });

    cam2.targetX = playerPosition.x;
    cam2.targetY = playerPosition.y;
    cam2.targetZ = playerPosition.z;
    cam2.ApplyCamera();

    ObjTest1.Transform_Object_Position(10.0f, 0.0f, 20.0f);
    ObjTest1.Transform_Object_Size(-1.0f, 5.0f, 0.0f);
    ObjTest1.Apply_Color(255, 0, 0);
    ObjTest1.Create_3D_Cube(2, 2, 5);
	ObjTest1.SetCollider(ObjTest1.GetColliderPosition(), ObjTest1.GetColliderScale());

  /*  ObjTest_2.Transform_Object_Position(-10.0f, 0.01f, 0.0f);*/
    Vector3 toLERP = GetLERPObjects(ObjTest_2, ObjTest1);
    
    glPushMatrix();
    ObjTest_2.SetCollider(ObjTest_2.GetColliderPosition(), ObjTest_2.GetColliderScale());
    if (!ObjTest_2.CheckCollision(ObjTest1))
    {
        ObjTest_2.TrackPoint(movementSpeed, toLERP, ObjTest_2.GetColliderPosition(), ObjTest1.GetColliderPosition());
    }
        
    ObjTest_2.Apply_Color(0, 255, 0, 100);
    ObjTest_2.Create_3D_Cylinder(4.0f, 4.0f, 8);
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-4.0f, 10.0f, 0.0f);
    RenderVariable(toLERP.x, 255.0f, 0.0f, 0.0f);
	glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 11.0f, 0.0f);
    RenderVariable(toLERP.y, 0.0, 255.0f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 12.0f, 0.0f);
    RenderVariable(toLERP.z, 0.0f, 0.0f, 255.0f);
    glPopMatrix();

    //==============================================

    //TEXT TEXT//
    glTranslatef(-20.0f, 3.0f, 0.0f);
    RenderText("According to all known laws of aviation, there is no way that a bee should be able to fly."
        , 255.0f, 255.0f, 255.0f);

    glTranslatef(-1.0f, -6.0f, 0.0f);
    RenderVariable(value, 255.0f, 0.0f, 0.0f);

    //rotateAngle += 1.0f;

    //TEXTURE TEST //
    StartEnablingTextures();
    BindSelectTexture(_textureId);

    //Bottom
    RenderType(true, true);
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);

    glNormal3f(0.0, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.5f, -2.5f, 2.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.5f, -2.5f, 2.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.5f, -2.5f, -2.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.5f, -2.5f, -2.5f);

    glEnd();

    //Back
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.5f, -2.5f, -2.5f);
    glTexCoord2f(5.0f, 5.0f);
    glVertex3f(0.0f, 2.5f, -2.5f);
    glTexCoord2f(10.0f, 0.0f);
    glVertex3f(2.5f, -2.5f, -2.5f);

    glEnd();

    //Left
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 0.7f, 0.3f);
    glBegin(GL_QUADS);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-2.5f, -2.5f, 2.5f);
    glVertex3f(-2.5f, -2.5f, -2.5f);
    glVertex3f(-2.5f, 2.5f, -2.5f);
    glVertex3f(-2.5f, 2.5f, 2.5f);

    glEnd();
    //========================================================
    //  PLAYER OBJECT
    //Camera bound by playerPosition

    Vector3 colliderScale(10, 10, 10); 
    Vector3 colliderPos(0.0f, 5.0f, 0.0f);
    Color betterColorTest(255, 0.0f, 255);

    player.Create_3D_Cone(5.0f, 10, 10);
    player.Transform_Object_Position(0.0f, 0.0f, 0.0f);
    player.Apply_Color(betterColorTest);
    player.SetCollider(player.GetColliderPosition() + colliderPos, colliderScale);
        if (Input::GetKey('d'))
        {
            /*Vector3 rightMovement(0.1f, 0, 0);
            playerPosition += rightMovement;*/
            Vector3 rightRotation(5.0f, 0, 0.0f);
            playerRotation += rightRotation;
            playerAngle += 1.0f;
        }
        if (Input::GetKey('a'))
        {
            /*Vector3 leftMovement(-0.1f, 0, 0);
            playerPosition += leftMovement;*/
            Vector3 leftRotation(-5.0f, 0, 0.0f);
            playerRotation += leftRotation;
            playerAngle -= 1.0f;
        }
        if (Input::GetKey('w'))
        {
            Vector3 topMovement(0, 0.1f, 0);
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
    player.Transform_Object_Position(playerPosition);
    player.Transform_Object_Rotation(playerAngle, playerRotation);
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
        otherObject.Transform_Object_Position(5.0f, 5.0f, 0.0f);
        otherObject.Transform_Object_Size(2.0f, 2.0f, 2.0f);
        otherObject.Transform_Object_Rotation(0.0f, 0.0f, 0.0f, 1.0f);

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
    otherObject.Transform_Object_Position(pos.x, pos.y, pos.z);
    otherObject.Transform_Object_Size(scale.x, scale.y, scale.z);
    otherObject.Create_3D_Cube(1.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv)
{
    PlaySong(L"Majula.wav");
    PrepEngine(argc, argv);
}


