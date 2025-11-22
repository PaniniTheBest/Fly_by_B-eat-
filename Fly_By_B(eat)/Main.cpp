#include "_3D_Shapes.h"
#include "libs.h"

float rotateAngle = 0.0f;

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(  0.0f, 0.0f, 20.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f);

    glTranslatef(0.0f, 5.0f, 0.0f);
    //glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
    //==============================================
    //Render 3D objects here \/ \/ \/
    _3D_Shapes Cube_test, ObjTest_2;
    /*Cube_test.Move_Object(0.0f, -2.0f, 0);
    Cube_test.Transform_Object_Size(1, 0.5, 1);
    Cube_test.Apply_Color(255.0f, 0.0f, 0.0f);
    Cube_test.Rotate_Object(rotateAngle, 0, 45, 0);
    Cube_test.Create_3D_Cube(5.0f, 10.0f,4);*/
    
    ObjTest_2.Move_Object(0.0f, -5.0f, 0.0f);
    ObjTest_2.Apply_Color(0, 255, 0);
    ObjTest_2.Rotate_Object(rotateAngle + 3, 0, 20, 0);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    ObjTest_2.Create_3D_Cone(3.0f, 5.0f, 6);
    //==============================================
    rotateAngle += 1.0f;
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
    //GLFWwindow* window = glfwCreateWindow();
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