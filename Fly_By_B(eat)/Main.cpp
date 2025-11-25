#include "Render_3D_Shapes.h"
#include "GameObject.h"
#include "Input.h"
#include "libs.h"
#include "Camera.h"
#include "Text.h"
#include "Engine.h"
#include <windows.h>
#include <mmsystem.h>


//Vector3 playerPos;
//GameObject player;
//camera cam;


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

//void processSpecialKeys(int key, int x, int y)
//{
//    switch (key)
//    {
//        case GLUT_KEY_UP:
//            Vector3 topMove(0.0f, 0.1f, 0.0f);
//            playerPos += topMove;
//        case GLUT_KEY_DOWN:
//            Vector3 downMove(0.0f, -0.1f, 0.0f);
//            playerPos += downMove;
//        case GLUT_KEY_LEFT:
//            Vector3 leftMove(-0.1f, 0.0f, 0.0f);
//            playerPos += leftMove;
//        case GLUT_KEY_RIGHT:
//            Vector3 rightMove(0.1f, 0.0f, 0.0f);
//            playerPos += rightMove;
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
    PlaySound(TEXT ("Majula.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    //GLFWwindow* window = glfwCreateWindow();
    //init GLUT and create a window
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(320, 320);

    glutCreateWindow("=+= Fly by B(eat) =+=");
    //register callbacks
    Update();
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);
    glutKeyboardFunc(&keyPressed);
    glutKeyboardUpFunc(&keyPressedUp);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;

   // PrepEngine(argc, argv);
}

//IDK WHY MY SHIT ISN'T WORKING
