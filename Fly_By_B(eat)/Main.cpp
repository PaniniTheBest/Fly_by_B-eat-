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
    tongueEnd.SetCollider(tongueEnd.GetObjectPosition(), Vector3(6, 6, 6));
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
        // Get frog position
        Vector3 frogPos = (frogPart1.GetObjectPosition());
        Vector3 frogPart4Pos = frogPart4.GetObjectPosition();

        // Calculate tongue position in world space
        Vector3 tongueScale(tongueExtension, 5.0f, 1.0f);
        Vector3 tonguePos;
        tonguePos.x = frogPos.x + (tongueExtension / 2);
        tonguePos.y = -10;
        tonguePos.z = frogPos.z + (tongueExtension / 2);

        tongue.TransformObjectPosition(tonguePos);
        tongue.TransformObjectRotation(45.0f, 0.0f, -40.0f, 0.0f);
        tongue.Apply_Color(255.0f, 70.0f, 10.0f);

        // Now collider uses world position
        tongue.SetCollider(tonguePos, tongueScale);
        tongue.Create3DCube(tongueScale);
    }
    Vector3 tongueEndPos(tongueExtension * 0.8f, 0, tongueExtension * 0.8f);

    tongueEnd.Create3DCube(3.0f,3.0f,3.0f);
    tongueEnd.Apply_Color(255.0f, 70.0f, 10.0f);
    tongueEnd.TransformObjectPosition(tongueEndPos);
}
//=======FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===FROG===
void AddScore()
{
    GlobalScore += 10;
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
    bool startHitTimer = false;
    //Don't put 3d objects above "cam.ApplyCamera()"
    cam.ApplyCamera();

    //Collision checks
    bool tongueIsActive = (tongueExtension > 0.1f);   
    bool hitTongueEnd = tongueIsActive && Goober.CheckCollision(tongueEnd);
    
    Color GooberColor(100.0f, 100.0f, 100.0f);
    Color GooberWingColor(205, 205, 205);
    Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.0055f);  // 8% per frame

    Squegee();
    SquegeeTongue();
    tongueEnd.SetCollider(tongueEnd.GetObjectPosition() + Vector3(0.0f, -5.0f, 0.0f), Vector3(10, 10, 10));
    RenderObjects Test;

    /*Test.Create3DCone(5, 2, 10);
    Test.TransformObjectPosition(tongueEnd.GetObjectPosition());*/
    UserInputHandle();

    Goober.TransformObjectPosition(GooberLERP);
    //Goober.TransformObjectPosition(5.0f, 5.0f, 5.0f);
    Goober.TransformObjectSize(2.0f, 2.0f, 2.0f);
    Goober.SetCollider(Goober.GetObjectPosition(), Goober.GetObjectSize());
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

    if (!Goober.CheckCollision(frogPart1) && !hitTongueEnd) //this moves the Gooberfly to Squeegee the Frog
    {
        Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.0055f);  // 8% per frame
        Goober.TransformObjectPosition(GooberLERP);
    }
    if (hitTongueEnd)
    {
        cout << "Adding score" << endl;
        AddScore();
        RespawnGoober();
    }
    else if (Goober.CheckCollision(frogPart1))  // Only if NOT hitting tongue
    {
        cout << "HIT FROG BODY" << endl;
        RespawnGoober();
    }
    //======================================================
    //TEXT TEXT//
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
    InterpolateX.RenderFloatVariableAsText(GooberLERP.x);

    InterpolateY.ColorText(150.0f, 0.0f, 255.0f);
    InterpolateY.TranslateText(-40.0f, 0.0f, 25.0f);
    InterpolateY.RenderFloatVariableAsText(GooberLERP.y);

    InterpolateY.ColorText(150.0f, 150.0f, 255.0f);
    InterpolateY.TranslateText(-45.0f, 0.0f, 30.0f);
    InterpolateY.RenderFloatVariableAsText(GooberLERP.y);

    //======================================================
    RenderObjects xRay;
    if (Input::GetKey('f'))
        xRay.XrayAll(true);
    else
        xRay.XrayAll(false);
    //======================================================
    //   ObjTest1.TransformObjectPosition(10.0f, 0.0f, 20.0f);
    //   ObjTest1.TransformObjectSize(-1.0f, 5.0f, 0.0f);
    //   ObjTest1.Apply_Color(255, 0, 0);
    //   ObjTest1.Create3DCube(2, 2, 5);
       //ObjTest1.SetCollider(ObjTest1.GetObjectPosition(), ObjTest1.GetObjectSize());

    //   //EVERYTHING BELOW HERE IS LERP//
    // /*  ObjTest_2.TransformObjectPosition(-10.0f, 0.01f, 0.0f);*/
    //   Vector3 toLERP = GetLERPObjects(ObjTest_2, ObjTest1, 0.1);
    //   
    //   //glPushMatrix();
    //   ObjTest_2.SetCollider(ObjTest_2.GetObjectPosition(), ObjTest_2.GetObjectSize());
    //   if (!ObjTest_2.CheckCollision(ObjTest1))
    //   {
    //       ObjTest_2.TrackPoint(movementSpeed, toLERP, ObjTest_2.GetObjectPosition(), ObjTest1.GetObjectPosition());
    //   }
    //   
    //   ObjTest_2.Apply_Color(0, 255, 0, 100);
    //   ObjTest_2.Create3DCylinder(4.0f, 4.0f, 8);
    // 
    //if (startHitTimer == true)
    //{
    //    float Timer = 0;
    //    Text HitMarker;
    //    Vector3 HitMarkerFadePoint(-35.0f, 0.0f, -21.0f);
    //    Vector3 HitMarkerLERP = GetLERPPoints(HitMarker.GetCurrentPosition(), HitMarkerFadePoint, 0.1);
    //    HitMarker.ColorText(255.0f, 0.0f, 0.0f);
    //    HitMarker.TranslateText(-35.0f, 0.0f, -20.0f);
    //    //HitMarker.TranslateText(HitMarkerLERP);
    //    HitMarker.RenderText("HIT!!!");
    //}
    /*glPopMatrix();*/
    //Text LERPx, LERPy, LERPz;
    //LERPx.ColorText(255.0f, 0.0f, 0.0f);
    //LERPx.TranslateText(-4.0f, 10.0f, 0.0f);
    //LERPx.RenderVariableAsText(toLERP.x);

    //LERPy.ColorText(0.0, 255.0f, 0.0f);
    //LERPy.TranslateText(-4.0f, 11.0f, 0.0f);
    //LERPy.RenderVariableAsText(toLERP.y);

    //LERPz.ColorText(0.0f, 0.0f, 255.0f);
    //LERPz.TranslateText(-4.0f, 12.0f, 0.0f);
    //LERPz.RenderVariableAsText(toLERP.z);

    //==================================================================================
    // 
    //  \/  \/ Apply these inside of 3D object functions; \/ \/
    // 
    //==================================================================================  
        //rotateAngle += 1.0f;
        ////TEXTURE TEST //
        //StartEnablingTextures();
        //BindSelectTexture(_textureId);

        ////Bottom
        //RenderType(true, true);
        //glColor3f(1.0f, 0.2f, 0.2f);
        //glBegin(GL_QUADS);

        //glNormal3f(0.0, 1.0f, 0.0f);
        //glTexCoord2f(0.0f, 0.0f);
        //glVertex3f(-2.5f, -2.5f, 2.5f);
        //glTexCoord2f(1.0f, 0.0f);
        //glVertex3f(2.5f, -2.5f, 2.5f);
        //glTexCoord2f(1.0f, 1.0f);
        //glVertex3f(2.5f, -2.5f, -2.5f);
        //glTexCoord2f(0.0f, 1.0f);
        //glVertex3f(-2.5f, -2.5f, -2.5f);

        //glEnd();

        ////Back
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glColor3f(1.0f, 1.0f, 1.0f);
        //glBegin(GL_TRIANGLES);

        //glNormal3f(0.0f, 0.0f, 1.0f);
        //glTexCoord2f(0.0f, 0.0f);
        //glVertex3f(-2.5f, -2.5f, -2.5f);
        //glTexCoord2f(5.0f, 5.0f);
        //glVertex3f(0.0f, 2.5f, -2.5f);
        //glTexCoord2f(10.0f, 0.0f);
        //glVertex3f(2.5f, -2.5f, -2.5f);

        //glEnd();

        ////Left
        //glDisable(GL_TEXTURE_2D);
        //glColor3f(1.0f, 0.7f, 0.3f);
        //glBegin(GL_QUADS);

        //glNormal3f(1.0f, 0.0f, 0.0f);
        //glVertex3f(-2.5f, -2.5f, 2.5f);
        //glVertex3f(-2.5f, -2.5f, -2.5f);
        //glVertex3f(-2.5f, 2.5f, -2.5f);
        //glVertex3f(-2.5f, 2.5f, 2.5f);

        //glEnd();
    //=================================================  
}
int main(int argc, char** argv)
{
    PlaySong(L"PlaygroundDayz.wav");
    PrepEngine(argc, argv);
}



