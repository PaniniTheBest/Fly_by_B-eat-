#include "Render_3D_Shapes.h"
#include "GameObject.h"
#include "Input.h"
#include "libs.h"
#include "Camera.h"
#include "Text.h"
#include "engine.h"
#include <windows.h>
#include <mmsystem.h>
#include "ImageLoader.h"


float value = 0.0f;
float rotateAngle = 0.0f;
int timeSinceStart = 0, previousTime = 0;

GameObject player;
camera cam;
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
/*
void RenderScene(void)
{
    timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (timeSinceStart - previousTime) / 1000.0f;
    previousTime = timeSinceStart;
    value += (1.0f * deltaTime);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 50.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    //cam.ApplyCamera();
    glTranslatef(0.0f, 3.0f, 0.0f);
    //glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
    //==============================================
    //Render 3D objects here / / /
    Render_3D_Shapes ObjTest1, ObjTest_2;

    ObjTest1.Transform_Object_Position(0.0f, 0.0f, 10.0f);
    ObjTest1.Transform_Object_Size(-1.0f, 5.0f, 0.0f);
    ObjTest1.Apply_Color(255, 0, 0);
    ObjTest1.Create_3D_Cube(2, 2, 5);

    ObjTest_2.Transform_Object_Position(0.01f, 0.01f, 0.0f);
    ObjTest_2.Apply_Color(0, 255, 0, 100);
    ObjTest_2.Create_3D_Cylinder(4.0f, 4.0f, 8);
    //==============================================

    //TEXT TEXT//
    glTranslatef(-20.0f, 3.0f, 0.0f);
    RenderText("According to all known laws of aviation, there is no way that a bee should be able to fly."
        , 255.0f, 255.0f, 255.0f);

    glTranslatef(-1.0f, -6.0f, 0.0f);
    RenderVariable(value, 255.0f, 0.0f, 0.0f);
    
    rotateAngle += 1.0f;

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
    glutSwapBuffers();
}
*/
//void ChangeSize(int w, int h)
//{
//    if (h == 0)
//        h = 1;
//
//    float ratio = 1.0 * w / h;
//
//    //fix the matrixmode to projection 
//    glMatrixMode(GL_PROJECTION);
//    //Reset the value of matrices
//    glLoadIdentity();
//    //Set the viewport of the window
//    glViewport(0, 0, w, h);
//    gluPerspective(45, ratio, 1, 1000);
//    // Get Back to Model View
//    glMatrixMode(GL_MODELVIEW);
//}
void Initialize()
{
    

}
void Update()
{
    timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (timeSinceStart - previousTime) / 1000.0f;
    previousTime = timeSinceStart;
    value += (1.0f * deltaTime);

    Render_3D_Shapes ObjTest1, ObjTest_2;

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
    //Vector3 colliderScale(1, 1, 1); 
    //player.SetCollider(player.GetPosition(), colliderScale)   
    //void processNormalKeys();
    //player.SetPosition(playerPos)
}

int main(int argc, char** argv)
{
    PlaySound(TEXT ("Majula.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    PrepEngine(argc, argv);
}

//IDK WHY MY SHIT ISN'T WORKING
