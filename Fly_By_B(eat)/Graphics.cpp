#include "Graphics.h"
#include "Engine.h"


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
//
//void Timer(int timer)
//{
//    glutPostRedisplay();
//    glutTimerFunc(16, Timer, 0);
//}
//
//void RenderScene()
//{
//    float rotateAngle = 0.0f;
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    gluLookAt(0.0f, 0.0f, 50.0f,
//        0.0f, 0.0f, 0.0f,
//        0.0f, 1.0f, 0.0f);
//
//    //cam.ApplyCamera();
//    glTranslatef(0.0f, 3.0f, 0.0f);
//    //glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
//    //==============================================
//    //Render 3D objects here / / /
//    Render_3D_Shapes ObjTest1, ObjTest_2;
//
//    ObjTest1.Transform_Object_Position(-5.0f, 0.0f, 0.0f);
//    ObjTest1.Transform_Object_Size(-1.0f, 5.0f, 0.0f);
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
//}