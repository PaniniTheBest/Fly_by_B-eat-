#include "_3D_Shapes.h"
#include "GameObject.h"
#include "Input.h"
#include "libs.h"

float rotateAngle = 0.0f;
Vector3 playerPos;
GameObject player;

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
    _3D_Shapes ObjTest1, ObjTest_2;
    ObjTest1.Move_Object(8, -1.0f, 0);
    ObjTest1.Create_3D_Cylinder(2, 2, 5);

    ObjTest_2.Move_Object(-3, -10, 0);
    ObjTest_2.Create_3D_Cone(2, 2, 7);
    ObjTest_2.Move_Object(-10, -5, 0);
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

void processNormalKeys()
{
    const char keys[] = { 'w', 'a', 's', 'd' };

    for (char key : keys)
    {
        if (Input::GetKey(key))
        {
            switch (key)
            {
            case 'w':
                Vector3 topMove(0.0f, 0.1, 0);
                playerPos += topMove;
                break;
            case 'a':
                Vector3 leftMove(-0.1f, 0, 0);
                playerPos += leftMove;
                break;
            case 's':
                Vector3 downMove(0, -0.1f, 0);
                playerPos += downMove;
                break;
            case 'd':
                Vector3 rightMove(0, 0.1f, 0);
                playerPos += rightMove;
                break;

            }

        }
    }
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