#include "Engine.h"


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
    //"This Linear Interpolation function's goal is to calculate the current distance between an origin object and a destination object.  
    // This returns a Vetor3 with float values for movement. This ensures that movement eases in and out rather than having robotic movements."

	//t represents how close the value is to any given position.
    //Near 0, it is close to currentPos. Near 1, it is close to farawayPos.
    return currentPos + t * (farawayPos - currentPos);
}

Vector3 GetLERPObjects(RenderObjects Origin, RenderObjects Destination, float t)
{
    Vector3 lerpedPosition;
    Vector3 originPos = Origin.GetObjectPosition();
    Vector3 destPos = Destination.GetObjectPosition();

    lerpedPosition.x = LinearInterpolate(originPos.x, destPos.x, t);
    lerpedPosition.y = LinearInterpolate(originPos.y, destPos.y, t);
    lerpedPosition.z = LinearInterpolate(originPos.z, destPos.z, t);

    return lerpedPosition;
}

Vector3 GetLERPPoints(Vector3 Origin, Vector3 Destination, float t)
{
    Vector3 lerpedPosition;
    Vector3 originPos = Origin;
    Vector3 destPos = Destination;

    lerpedPosition.x = LinearInterpolate(originPos.x, destPos.x, t);
    lerpedPosition.y = LinearInterpolate(originPos.y, destPos.y, t);
    lerpedPosition.z = LinearInterpolate(originPos.z, destPos.z, t);

    return lerpedPosition;
}