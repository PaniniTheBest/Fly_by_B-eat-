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
    //OPPENHEIMER//
    return currentPos + t * (farawayPos - currentPos);
}

Vector3 GetLERPObjects(RenderObjects Origin, RenderObjects Destination)
{
    Vector3 direction;
    Vector3 originPosition = Origin.GetColliderPosition();
    Vector3 destinationPosition = Destination.GetColliderPosition();

    // Calculate direction from Origin to Destination
    direction.x = destinationPosition.x - originPosition.x;
    direction.y = destinationPosition.y - originPosition.y;
    direction.z = destinationPosition.z - originPosition.z;

    /*direction.x = LinearInterpolate(Origin.GetColliderPosition().x, Destination.GetColliderPosition().x, direction.x);
	direction.y = LinearInterpolate(Origin.GetColliderPosition().y, Destination.GetColliderPosition().y, direction.y);
	direction.z = LinearInterpolate(Origin.GetColliderPosition().z, Destination.GetColliderPosition().z, direction.z);*/

    // This normalizes the vector
    float length = sqrt(direction.x * direction.x +
                        direction.y * direction.y +
                        direction.z * direction.z);

    if (length > 0)
    {
        direction.x /= length;
        direction.y /= length;
        direction.z /= length;
    }

    return direction;
}