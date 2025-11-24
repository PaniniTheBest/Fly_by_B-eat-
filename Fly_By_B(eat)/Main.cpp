#include "_3D_Shapes.h"
#include "GameObject.h"
#include "Input.h"
#include "libs.h"
#include "Camera.h"
#include "Engine.h"

float rotateAngle = 0.0f;
//Vector3 playerPos;
//GameObject player;
//camera cam;

//void RenderScene(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    gluLookAt(  0.0f, 0.0f, 50.0f,
//                0.0f, 0.0f, 0.0f,
//                0.0f, 1.0f, 0.0f);
//
//    //cam.ApplyCamera();
//    glTranslatef(0.0f, 3.0f, 0.0f);
//    //glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
//    //==============================================
//    //Render 3D objects here / / /
//    _3D_Shapes ObjTest1, ObjTest_2;
//
//    ObjTest1.Transform_Object_Position(-5.0f, 0.0f, 0.0f);
//    ObjTest1.Transform_Object_Size(-1.0f,5.0f,0.0f);
//    ObjTest1.Apply_Color(255, 0, 0);
//    ObjTest1.Create_3D_Cube(2, 2, 5);
//
//    ObjTest_2.Transform_Object_Position(0.01f, 0.01f, 0.0f);
//    ObjTest_2.Apply_Color(0, 255, 0);
//    ObjTest_2.Create_3D_Cylinder(4.0f, 4.0f, 8);
//    
//    //==============================================
//    rotateAngle += 1.0f;
//    glutSwapBuffers();
//
//}
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

//void processNormalKeys()
//{
//    const char keys[] = { 'w', 'a', 's', 'd' };
//
//    for (char key : keys)
//    {
//        if (Input::GetKey(key))
//        {
//            switch (key)
//            {
//            case 'w':
//                Vector3 topMove(0.0f, 0.1, 0);
//                playerPos += topMove;
//                break;
//            case 'a':
//                Vector3 leftMove(-0.1f, 0, 0);
//                playerPos += leftMove;
//                break;
//            case 's':
//                Vector3 downMove(0, -0.1f, 0);
//                playerPos += downMove;
//                break;
//            case 'd':
//                Vector3 rightMove(0, 0.1f, 0);
//                playerPos += rightMove;
//                break;
//            }
//        }
//    }
//}

void Update()
{
    Vector3 colliderScale(1, 1, 1);
    //player.SetCollider(player.GetPosition(), colliderScale)

    //void processNormalKeys();
    //player.SetPosition(playerPos)
}

int main(int argc, char** argv)
{
    PrepEngine(argc, argv);
}

//IDK WHY MY SHIT ISN'T WORKING
