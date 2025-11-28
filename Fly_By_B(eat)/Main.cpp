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


float value = 0.0f;
float rotateAngle = 0.0f;
Vector3 playerPosition(0, 0, 0);
Render_3D_Objects player;
Render_3D_Objects otherObject;
camera2 cam2;
//camera cam;

//void Character()
//{
//    const char keys[] = { 'w', 'a', 's', 'd' };
//
//    player.SetPosition(0.0f, 0.0f, 0.0f);
//    player.SetScale(1.0f, 1.0f, 1.0f);
//    player.SetRotation(0.0f, 0.0f, 0.0f, 1.0f);
//
//    for (char key : keys)
//    {
//        if (Input::GetKey(key))
//        {
//            Vector3 movement(0, 0, 0);
//
//            if (Input::GetKey('w')) movement.y += 10.1f;
//            if (Input::GetKey('s')) movement.y -= 10.1f;
//            if (Input::GetKey('a')) movement.x -= 10.1f;
//            if (Input::GetKey('d')) movement.x += 10.1f;
//
//           
//            Vector3 currentPos = player.GetPosition();
//
//          
//            Vector3 newPos(
//                currentPos.x + movement.x,
//                currentPos.y + movement.y,
//                currentPos.z + movement.z
//            );
//
//           
//            player.SetPosition(newPos);
//
//            break; 
//        }
//    }
//}

//void processSpecialKeys(int key, int x, int y)
//{
//    switch (key)
//    {
//        case GLUT_KEY_UP:
//            Vector3 topMove(0.0f, 0.1f, 0.0f);
//            playerPos += topMove;
//        case GLUT_KEY_DOWN:
//            Vector3 downMove(0.0f, -0.1f, 0.0f);
//            playerPos += downMove;
//        case GLUT_KEY_LEFT:
//            Vector3 leftMove(-0.1f, 0.0f, 0.0f);
//            playerPos += leftMove;
//        case GLUT_KEY_RIGHT:
//            Vector3 rightMove(0.1f, 0.0f, 0.0f);
//            playerPos += rightMove;
//    }
//}
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
void Update()
{
    float deltaTime = FindDeltaTime();
    value += (1.0f * deltaTime);

    glutMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });
    glutPassiveMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });

    Render_3D_Objects ObjTest1, ObjTest_2;

    cam2.targetX = playerPosition.x;
    cam2.targetY = playerPosition.y;
    cam2.targetZ = playerPosition.z;
    cam2.ApplyCamera();

    ObjTest1.Transform_Object_Position(0.0f, 0.0f, 10.0f);
    ObjTest1.Transform_Object_Size(-1.0f, 5.0f, 0.0f);
    ObjTest1.Apply_Color(255, 0, 0);
    ObjTest1.Create_3D_Cube(2, 2, 5);

    ObjTest_2.Transform_Object_Position(-5.0f, 0.01f, 0.0f);
    ObjTest_2.Apply_Color(0, 255, 0, 100);
    ObjTest_2.Create_3D_Cylinder(4.0f, 4.0f, 8);
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
    Vector3 colliderScale(10, 10, 10); 
    Vector3 colliderPos(0.0f, 5.0f, 0.0f);
    player.Create_3D_Cone(5.0f, 10, 10);
    player.Apply_Color(255, 105, 0);
    player.SetCollider(player.GetColliderPosition() + colliderPos, colliderScale);
        if (Input::GetKey('d'))
        {
            Vector3 rightMovement(0.1f, 0, 0);
            playerPosition += rightMovement;
        }
        if (Input::GetKey('a'))
        {
            Vector3 leftMovement(-0.1f, 0, 0);
            playerPosition += leftMovement;
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

    if (Input::GetKey('x'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (Input::GetKey('z'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
        

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
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.5f, 1.0f);


    glPushMatrix();
    {
        Vector3 pos = otherObject.GetColliderPosition();
        Vector3 scale = otherObject.GetColliderScale();

        glTranslatef(pos.x, pos.y, pos.z);
        glScalef(scale.x, scale.y, scale.z);

        glutSolidCube(1.0f);
    }
    glPopMatrix();
}

int main(int argc, char** argv)
{
    PlaySong(L"Majula.wav");
    PrepEngine(argc, argv);
}

//IDK WHY MY SHIT ISN'T WORKING
