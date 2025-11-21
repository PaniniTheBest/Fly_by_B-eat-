#include "_3D_Shapes.h"
#include "Camera.h"

camera cam;
float rotateAngle = 0.0f;

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    cam.ApplyCamera();
    //==============================================
    //Render 3D objects here \/ \/ \/
    _3D_Shapes Cube_test;
    Cube_test.Move_Object(0.0f, -4.0f, 0);
    //Cube_test.Apply_Color(255.0f, 0.0f, 0.0f);
    Cube_test.Create_3D_Cube(5.0f,10.0f,20.0f);

    _3D_Shapes Cube_test2;
    Cube_test.Move_Object(0.0f, 30.0f, 0);
    Cube_test.Apply_Color(255.0f, 0.0f, 0.0f);
    Cube_test.Create_3D_Cube(3.0f, 5.0f, 10.0f);
    //==============================================
    glutSwapBuffers();
}

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

int main(int argc, char** argv)
{
    //init GLUT and create a window
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(320, 320);

    glutCreateWindow("=+= Fly by B(eat) =+=");
    //register callbacks
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}