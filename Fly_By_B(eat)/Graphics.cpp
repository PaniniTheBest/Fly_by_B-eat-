#include "Graphics.h"
#include "Engine.h"


void ChangeSize(int w, int h)
{
    if (h == 0)
        h = 1;

    float ratio = 1.0 * w / h;

    //fix the matrixmode to projection 
    glMatrixMode(GL_PROJECTION);
    //Reset the value of matrices
    glLoadIdentity();
    //Set the viewport of the window
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    // Get Back to Model View
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int timer)
{
    glutPostRedisplay();
    glutTimerFunc(16, Timer, 0);
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 50.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    //cam.ApplyCamera();
    //glTranslatef(0.0f, 3.0f, 0.0f);
    //glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
    //==============================================
    //Render 3D objects here / / /
    Update();

    glutSwapBuffers();
}