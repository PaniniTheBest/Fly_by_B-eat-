#include "Engine.h"
#include "Graphics.h"
#include "Input.h"

int timeSinceStart = 0, previousTime = 0;

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
    InitiateRender(); //Test Func//

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);
    glutKeyboardFunc(&keyPressed);
    glutKeyboardUpFunc(&keyPressedUp);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    Initialize();

    glutMainLoop();
}

float FindDeltaTime()
{
    timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (timeSinceStart - previousTime) / 1000.0f;
    previousTime = timeSinceStart;
	return deltaTime;
}

float LinearInterpolate(float currentPos, float farawayPos, float t) //Finding the values between coordinates, Also called LERP
{
	//t represents how close the value is to any given position.
    //Near 0, it is close to currentPos. Near 1, it is close to farawayPos.
    return currentPos + t * (farawayPos - currentPos);
}

Vector3 GetLERPObjects(Render_3D_Objects Origin, Render_3D_Objects Destination) //This function is specified for objects of the 3D Objects class//
{
    Vector3 resultingLERP;
    resultingLERP.x = LinearInterpolate(Origin.GetColliderPosition().x, Destination.GetColliderPosition().x, 0.1f);
    resultingLERP.y = LinearInterpolate(Origin.GetColliderPosition().y, Destination.GetColliderPosition().y, 0.1f);
    resultingLERP.z = LinearInterpolate(Origin.GetColliderPosition().z, Destination.GetColliderPosition().z, 0.1f);
    return resultingLERP;
}