#include "_3D_Shapes.h"
#include "GameObject.h"
#include "Input.h"
#include "libs.h"
#include "Camera.h"
#include "Engine.h"

float rotateAngle = 0.0f;
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

void Update()
{
    Vector3 colliderScale(1, 1, 1);
    //player.SetCollider(player.GetPosition(), colliderScale)

    //void processNormalKeys();
    //player.SetPosition(playerPos)
}

int main(int argc, char** argv)
{
    PrepEngine(argc, argv);
}

//IDK WHY MY SHIT ISN'T WORKING
