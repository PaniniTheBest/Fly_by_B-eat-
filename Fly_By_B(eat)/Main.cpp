#include "RenderObjects.h"
#include "Input.h"
#include "Camera.h"
#include "Camera2.h"
#include "Text.h"
#include "Engine.h"
#include <windows.h>
#include <mmsystem.h>
#include "ImageLoader.h"
#include "AudioManager.h"
#include "Collider.h"
#include <thread>
#include <atomic>
#include <mutex>
#include "Rope.h"

//float value = 0.0f;
//float rotateAngle = 0.0f;
//Vector3 playerPosition(0, 0, 0);
//Vector3 playerRotation(0, 0, 0);
//float playerAngle = 0.0f;
//RenderObjects player;
//RenderObjects otherObject;
//Enemy Test
//RenderObjects floorz;
//Create game objects with colliders
//RenderObjects player;
camera cam;
int GlobalScore = 0;
//GLuint loadTexture(Image* image) {
//    GLuint textureId;
//    glGenTextures(1, &textureId); //Make room for our texture
//    glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
//    //Map the image to the texture
//    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
//        0,                            //0 for now
//        GL_RGB,                       //Format OpenGL uses for image
//        image->width, image->height,  //Width and height
//        0,                            //The border of the image
//        GL_RGB, //GL_RGB, because pixels are stored in RGB format
//        GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
//        //as unsigned numbers
//        image->pixels);               //The actual pixel data
//    return textureId; //Returns the id of the texture
//}
GLuint _textureId; //The id of the texture

RenderObjects ObjTest1, ObjTest_2;
RenderObjects Goober, GooberWing1, GooberWing2;
float movementSpeed = 0.01f;

Vector3 FloorcolliderScale(20.0f, 0.5f, 20.0f);
RenderObjects frogPart1, frogPart2, frogPart3, frogPart4, frogEye1, frogEye2, frogEye3, frogEye4;
RenderObjects tongue, tongueEnd;

float frogRotation = 0.0f;
float tongueExtension = 0.0f;
bool tongueIsExtending = false;


void InitiateRender()
{
    /*glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);*/
    _textureId = InitializeTexture("vtr4.bmp");
}
void UserInputHandle()
{
    if (Input::GetKey('w'))
    {
        if (frogRotation != 135) {
            if (frogRotation < 135) {
                frogRotation += 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
            else if (frogRotation > 135) {
                frogRotation -= 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }

        }
        if (frogRotation == 405) {
            frogRotation = 45;
        }

    }
    if (Input::GetKey('a'))
    {
        if (frogRotation != 225) {
            if (frogRotation < 225) {
                frogRotation += 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
            else {
                frogRotation -= 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
        }
    }
    if (Input::GetKey('s'))
    {
        if (frogRotation == 45) {
            frogRotation = 405;
        }
        if (frogRotation != 315) {
            if (frogRotation < 315) {
                frogRotation += 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
            else {
                frogRotation -= 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
        }
    }
    if (Input::GetKey('d'))
    {
        if (frogRotation == 405) {
            frogRotation = 45;
        }
        if (frogRotation != 405 && frogRotation != 45) {
            if (frogRotation < 405) {
                frogRotation += 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
            else {
                frogRotation -= 5;
                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
            }
        }

    }

}
void Squegee()
{
    Color frogGreen(0, 255, 100);
    Color frogEyeGreen(0, 255, 150);
    Color WhiteEyes(255, 255, 255);
    Color BlackEyes(0, 0, 0);
    frogPart1.TransformObjectPosition(0, 10, 0);
    frogPart1.SetCollider(frogPart1.GetObjectPosition(), Vector3(3, 3, 3));
    //frogPart1.TransformObjectRotation(Rotation::camYaw, 0, 1, 0);
    frogPart1.Apply_Color(frogGreen);
    frogPart1.Create3DSphere(5, 15, 15);

    frogPart2.TransformObjectPosition(3.5f, 3, 0);
    frogPart2.Apply_Color(frogEyeGreen);
    frogPart2.Create3DSphere(2, 15, 15);

    frogPart3.TransformObjectPosition(0, 3, 3.5f);
    frogPart3.Apply_Color(frogEyeGreen);
    frogPart3.Create3DSphere(2, 15, 15);

    frogPart4.TransformObjectPosition(2, 1, 2);
    frogPart4.Apply_Color(frogGreen);
    frogPart4.Create3DSphere(4, 15, 15);

    frogEye1.TransformObjectPosition(4.5f, 3, 0);
    frogEye1.Apply_Color(WhiteEyes);
    frogEye1.Create3DSphere(1.5, 15, 15);

    frogEye2.TransformObjectPosition(5, 3, 0.3);
    frogEye2.Apply_Color(BlackEyes);
    frogEye2.Create3DSphere(1.3, 15, 15);

    frogEye3.TransformObjectPosition(0, 3, 4.5f);
    frogEye3.Apply_Color(WhiteEyes);
    frogEye3.Create3DSphere(1.5, 15, 15);

    frogEye4.TransformObjectPosition(0.3, 3, 5);
    frogEye4.Apply_Color(BlackEyes);
    frogEye4.Create3DSphere(1.3, 15, 15);

    frogPart2.SetParent(&frogPart1);
    frogPart3.SetParent(&frogPart1);
    frogPart4.SetParent(&frogPart1);
    frogEye1.SetParent(&frogPart1);
    frogEye2.SetParent(&frogPart1);
    frogEye3.SetParent(&frogPart1);
    frogEye4.SetParent(&frogPart1);

    tongue.SetParent(&frogPart4);
    tongueEnd.SetParent(&frogPart4);
}
void SquegeeTongue()
{
    if (Input::GetKey(' '))
    {
        if (tongueExtension < 16.0f)
            tongueExtension += 0.5f;
    }
    else
    {
        if (tongueExtension > 0.0f)
            tongueExtension -= 1.0f;
    }

    if (tongueExtension > 0.1f)
    {
        // Tongue extends in local space
        Vector3 tongueScale(tongueExtension, 5.0f, 1.0f);
        Vector3 tongueLocalPos(tongueExtension / 2, -10, tongueExtension / 2);

        tongue.TransformObjectPosition(tongueLocalPos);
        tongue.TransformObjectRotation(45.0f, 0.0f, -40.0f, 0.0f);
        tongue.Apply_Color(255.0f, 70.0f, 10.0f);
        tongue.Create3DCube(tongueScale);
    }

    // TongueEnd position - at the tip of the tongue
    Vector3 tongueEndPos(tongueExtension * 0.8f, 0, tongueExtension * 0.8f);
    tongueEnd.TransformObjectPosition(tongueEndPos);
    tongueEnd.Apply_Color(255.0f, 70.0f, 10.0f);
    tongueEnd.Create3DCube(3.0f, 3.0f, 3.0f);
}
//=======FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===
void AddScore(bool hit)
{
    hit == true ? GlobalScore += 10 : GlobalScore -= 10;
}
void RespawnGoober()
{
    srand(time(NULL));
    int d4Dice = rand() % 4;
    float spawnDistance = 100.0f;
    if (d4Dice == 0)
        Goober.TransformObjectPosition(spawnDistance, 0, 0);
    else if (d4Dice == 1)
        Goober.TransformObjectPosition(-spawnDistance, 0, 0);
    else if (d4Dice == 2)
        Goober.TransformObjectPosition(0, 0, spawnDistance);
    else  // d4Dice == 3
        Goober.TransformObjectPosition(0, 0, -spawnDistance);
}
void Initialize()
{

}
void Update()
{
    cam.ApplyCamera();

    UserInputHandle();
    Squegee();
    SquegeeTongue();

    // === SETUP GOOBER FIRST ===
    Color GooberColor(100.0f, 100.0f, 100.0f);
    Color GooberWingColor(205, 205, 205);

    Goober.TransformObjectSize(2.0f, 2.0f, 2.0f);
    Goober.Apply_Color(GooberColor);
    Goober.Create3DSphere(0.8f, 20.0f, 10.0f);

    GooberWing1.Apply_Color(GooberWingColor);
    GooberWing2.Apply_Color(GooberWingColor);
    GooberWing1.TransformObjectPosition(-1, -0.5f, -1);
    GooberWing2.TransformObjectPosition(1, -0.5f, -1);
    GooberWing1.Create3DSphere(1, 20.0f, 10.0f);
    GooberWing2.Create3DSphere(1, 20.0f, 10.0f);
    GooberWing1.SetParent(&Goober);
    GooberWing2.SetParent(&Goober);

    //COLLIDERS OF OBJECTS
    tongueEnd.SetCollider(tongueEnd.GetWorldPosition(), Vector3(8, 8, 8));
    Goober.SetCollider(Goober.GetObjectPosition(), Goober.GetObjectSize());
    frogPart1.SetCollider(frogPart1.GetObjectPosition(), Vector3(5, 5, 5));

    RenderObjects Test;
    Test.Create3DCylinder(10, 5, 8);
    Test.Apply_Color(255, 255, 255);
    Test.TransformObjectPosition(tongueEnd.GetWorldPosition());

    //COLLISION CHECKS
    bool tongueIsActive = (tongueExtension > 0.1f);
    bool hitTongueEnd = tongueIsActive && Goober.CheckCollision(tongueEnd);
    // === DEBUG OUTPUT ===
    if (tongueIsActive) {
        Vector3 gooberPos = Goober.GetObjectPosition();
        float dx = tongueEnd.GetWorldPosition().x - gooberPos.x;
        float dy = tongueEnd.GetWorldPosition().y - gooberPos.y;
        float dz = tongueEnd.GetWorldPosition().z - gooberPos.z;
        float distance = sqrt(dx * dx + dy * dy + dz * dz);

        if (distance < 15.0f) { // Only print when close
            cout << "Distance: " << distance
                << " | TongueWorld(" << tongueEnd.GetWorldPosition().x << "," << tongueEnd.GetWorldPosition().y << "," << tongueEnd.GetWorldPosition().z << ")"
                << " | Goober(" << gooberPos.x << "," << gooberPos.y << "," << gooberPos.z << ")"
                << " | Hit: " << (hitTongueEnd ? "YES" : "NO") << endl;
        }
    }

    // === MOVEMENT AND SCORING ===
    if (!Goober.CheckCollision(frogPart1) && !hitTongueEnd)
    {
        Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.0055f);
        Goober.TransformObjectPosition(GooberLERP);
    }
    if (hitTongueEnd)
    {        
        AddScore(true);
        RespawnGoober();
    }
    else if (Goober.CheckCollision(frogPart1))
    {
        AddScore(false);
        RespawnGoober();
    }

    //TEXT DISPLAY
    Text ScoreWord, ScoreVariable;
    Text InterpolateX, InterpolateY, InterpolateZ;

    ScoreWord.ColorText(255.0f, 255.0f, 0.0f);
    ScoreWord.TranslateText(-45.0f, 0.0f, -20.0f);
    ScoreWord.RenderText("SCORE: ");

    ScoreVariable.ColorText(255.0f, 0.0f, 0.0f);
    ScoreVariable.TranslateText(-35.0f, 0.0f, -19.0f);
    ScoreVariable.RenderIntVariableAsText(GlobalScore);

    InterpolateX.ColorText(0.0f, 150.0f, 255.0f);
    InterpolateX.TranslateText(-45.0f, 0.0f, 20.0f);
    InterpolateX.RenderFloatVariableAsText(tongueEnd.GetWorldPosition().x);

    InterpolateY.ColorText(150.0f, 0.0f, 255.0f);
    InterpolateY.TranslateText(-40.0f, 0.0f, 25.0f);
    InterpolateY.RenderFloatVariableAsText(tongueEnd.GetWorldPosition().y);

    InterpolateZ.ColorText(150.0f, 150.0f, 255.0f);
    InterpolateZ.TranslateText(-45.0f, 0.0f, 30.0f);
    InterpolateZ.RenderFloatVariableAsText(tongueEnd.GetWorldPosition().z);
    //XRAY
    RenderObjects xRay;
    if (Input::GetKey('f'))
        xRay.XrayAll(true);
    else
        xRay.XrayAll(false);
}
int main(int argc, char** argv)
{
    PlaySong(L"PlaygroundDayz.wav");
    PrepEngine(argc, argv);
}



