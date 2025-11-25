#include "Engine.h"
#include "Graphics.h"
#include "Input.h"

void PrepEngine(int argc, char** argv)
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
    glutKeyboardFunc(&keyPressed);
    glutKeyboardUpFunc(&keyPressedUp);
    glutSpecialFunc(&specialkeyPressed);
    glutSpecialUpFunc(&specialkeyPressedUp);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();
}
