//#include "RenderObjects.h"
//#include "Input.h"
//#include "Camera.h"
//#include "Camera2.h"
//#include "Text.h"
//#include "Engine.h"
//#include <windows.h>
//#include <mmsystem.h>
//#include "ImageLoader.h"
//#include "AudioManager.h"
//#include "Collider.h"
//#include <thread>
//#include <atomic>
//#include <mutex>
//#include "RotationObject.h"
//#include "Rope.h"
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//// Global variables
//camera cam;
//int GlobalScore = 0;
//GLuint _textureId;
//
//RenderObjects ObjTest1, ObjTest_2;
//RenderObjects Goober, GooberWing1, GooberWing2;
//float movementSpeed = 0.01f;
//Vector3 FloorcolliderScale(20.0f, 0.5f, 20.0f);
//RenderObjects frogPart1, frogPart2, frogPart3, frogPart4, frogEye1, frogEye2, frogEye3, frogEye4;
//RenderObjects tongue, tongueEnd;
//float frogRotation = 45.0f;  // Start at 45 degrees
//float tongueExtension = 0.0f;
//bool tongueIsExtending = false;
//
//void InitiateRender()
//{
//    _textureId = InitializeTexture("vtr4.bmp");
//}
//
//void UserInputHandle()
//{
//    if (Input::GetKey('w'))
//    {
//        if (frogRotation != 135) {
//            if (frogRotation < 135) {
//                frogRotation += 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//            else if (frogRotation > 135) {
//                frogRotation -= 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//        }
//        if (frogRotation == 405) {
//            frogRotation = 45;
//        }
//    }
//    if (Input::GetKey('a'))
//    {
//        if (frogRotation != 225) {
//            if (frogRotation < 225) {
//                frogRotation += 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//            else {
//                frogRotation -= 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//        }
//    }
//    if (Input::GetKey('s'))
//    {
//        if (frogRotation == 45) {
//            frogRotation = 405;
//        }
//        if (frogRotation != 315) {
//            if (frogRotation < 315) {
//                frogRotation += 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//            else {
//                frogRotation -= 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//        }
//    }
//    if (Input::GetKey('d'))
//    {
//        if (frogRotation == 405) {
//            frogRotation = 45;
//        }
//        if (frogRotation != 405 && frogRotation != 45) {
//            if (frogRotation < 405) {
//                frogRotation += 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//            else {
//                frogRotation -= 5;
//                frogPart1.TransformObjectRotation(frogRotation, 0, frogRotation, 0);
//            }
//        }
//    }
//}
//
//void AddScore()
//{
//    GlobalScore += 10;
//    cout << "\n========================================" << endl;
//    cout << "*** SCORE ADDED! Total Score: " << GlobalScore << " ***" << endl;
//    cout << "========================================\n" << endl;
//}
//
//void RespawnGoober()
//{
//    int d4Dice = rand() % 4;
//    float spawnDistance = 80.0f;
//
//    Vector3 newPos;
//    if (d4Dice == 0)
//        newPos = Vector3(spawnDistance, 0, 0);
//    else if (d4Dice == 1)
//        newPos = Vector3(-spawnDistance, 0, 0);
//    else if (d4Dice == 2)
//        newPos = Vector3(0, 0, spawnDistance);
//    else
//        newPos = Vector3(0, 0, -spawnDistance);
//
//    Goober.TransformObjectPosition(newPos);
//    cout << "Goober respawned at: (" << newPos.x << ", " << newPos.y << ", " << newPos.z << ")" << endl;
//}
//
//// Calculate direction vector based on rotation angle
//Vector3 GetDirectionFromAngle(float angle)
//{
//    float radians = angle * (3.14159265f / 180.0f);
//    return Vector3(cos(radians), 0, sin(radians));
//}
//
//void Squegee()
//{
//    Color frogGreen(0, 255, 100);
//    Color frogEyeGreen(0, 255, 150);
//    Color WhiteEyes(255, 255, 255);
//    Color BlackEyes(0, 0, 0);
//
//    frogPart1.TransformObjectPosition(0, 10, 0);
//    frogPart1.SetCollider(frogPart1.GetObjectPosition(), Vector3(6, 6, 6));
//    frogPart1.Apply_Color(frogGreen);
//    frogPart1.Create3DSphere(5, 15, 15);
//
//    frogPart2.TransformObjectPosition(3.5f, 3, 0);
//    frogPart2.Apply_Color(frogEyeGreen);
//    frogPart2.Create3DSphere(2, 15, 15);
//
//    frogPart3.TransformObjectPosition(0, 3, 3.5f);
//    frogPart3.Apply_Color(frogEyeGreen);
//    frogPart3.Create3DSphere(2, 15, 15);
//
//    frogPart4.TransformObjectPosition(2, 1, 2);
//    frogPart4.Apply_Color(frogGreen);
//    frogPart4.Create3DSphere(4, 15, 15);
//
//    frogEye1.TransformObjectPosition(4.5f, 3, 0);
//    frogEye1.Apply_Color(WhiteEyes);
//    frogEye1.Create3DSphere(1.5, 15, 15);
//
//    frogEye2.TransformObjectPosition(5, 3, 0.3);
//    frogEye2.Apply_Color(BlackEyes);
//    frogEye2.Create3DSphere(1.3, 15, 15);
//
//    frogEye3.TransformObjectPosition(0, 3, 4.5f);
//    frogEye3.Apply_Color(WhiteEyes);
//    frogEye3.Create3DSphere(1.5, 15, 15);
//
//    frogEye4.TransformObjectPosition(0.3, 3, 5);
//    frogEye4.Apply_Color(BlackEyes);
//    frogEye4.Create3DSphere(1.3, 15, 15);
//
//    // Set parents
//    frogPart2.SetParent(&frogPart1);
//    frogPart3.SetParent(&frogPart1);
//    frogPart4.SetParent(&frogPart1);
//    frogEye1.SetParent(&frogPart1);
//    frogEye2.SetParent(&frogPart1);
//    frogEye3.SetParent(&frogPart1);
//    frogEye4.SetParent(&frogPart1);
//}
//
//void SquegeeTongue()
//{
//    // Handle tongue extension
//    if (Input::GetKey(' '))
//    {
//        if (tongueExtension < 25.0f)  // Increased max extension
//            tongueExtension += 0.8f;  // Faster extension
//    }
//    else
//    {
//        if (tongueExtension > 0.0f)
//            tongueExtension -= 1.5f;  // Faster retraction
//    }
//
//    // Only render tongue if extended
//    if (tongueExtension > 0.1f)
//    {
//        // Get frog's position and facing direction
//        Vector3 frogPos = frogPart1.GetObjectPosition();
//        Vector3 direction = GetDirectionFromAngle(frogRotation);
//
//        // Calculate tongue tip position in WORLD SPACE
//        Vector3 tongueTipWorldPos = Vector3(
//            frogPos.x + direction.x * tongueExtension,
//            frogPos.y,
//            frogPos.z + direction.z * tongueExtension
//        );
//
//        // ===== TONGUE BASE =====
//        Vector3 tongueScale(tongueExtension * 0.6f, 3.0f, 3.0f);
//        Vector3 tongueMidPoint = Vector3(
//            frogPos.x + direction.x * tongueExtension * 0.5f,
//            frogPos.y,
//            frogPos.z + direction.z * tongueExtension * 0.5f
//        );
//
//        tongue.TransformObjectPosition(tongueMidPoint);
//        tongue.TransformObjectRotation(frogRotation, 0.0f, 0.0f, 0.0f);
//        tongue.Apply_Color(255.0f, 70.0f, 10.0f);
//        tongue.SetCollider(tongueMidPoint, tongueScale);
//        tongue.Create3DCube(tongueScale);
//
//        // ===== TONGUE END (TIP) - DIRECT WORLD POSITION =====
//        tongueEnd.TransformObjectPosition(tongueTipWorldPos);  // Set absolute world position
//        tongueEnd.TransformObjectRotation(0.0f, 0.0f, 0.0f, 0.0f);  // No rotation needed
//        tongueEnd.Apply_Color(255.0f, 120.0f, 120.0f);
//        tongueEnd.Create3DSphere(3.0f, 12, 12);  // Larger sphere
//
//        // ✅ LARGE COLLIDER AT TONGUE TIP
//        Vector3 tongueEndColliderScale(12.0f, 12.0f, 12.0f);  // Big collision sphere
//        tongueEnd.SetCollider(tongueTipWorldPos, tongueEndColliderScale);
//
//        // Debug tongue tip position every frame when extended
//        static int tongueDebugCounter = 0;
//        if (tongueDebugCounter++ % 30 == 0) {
//            cout << "[TONGUE] Extension: " << tongueExtension
//                << " | Tip at: (" << tongueTipWorldPos.x << ", "
//                << tongueTipWorldPos.y << ", " << tongueTipWorldPos.z << ")" << endl;
//        }
//    }
//}
//
//void Initialize()
//{
//    srand(time(NULL));
//    Goober.TransformObjectPosition(80.0f, 0, 0);
//    cout << "Game Initialized! Starting Score: " << GlobalScore << endl;
//}
//
//void Update()
//{
//    cam.ApplyCamera();
//
//    // ===== RENDER FROG & TONGUE =====
//    Squegee();
//    UserInputHandle();
//    SquegeeTongue();
//
//    bool tongueIsActive = (tongueExtension > 0.1f);
//
//    // ===== GOOBER (FLY) =====
//    Color GooberColor(150.0f, 150.0f, 150.0f);
//    Color GooberWingColor(255, 255, 255);
//
//    Vector3 gooberPos = Goober.GetObjectPosition();
//
//    // Render Goober body
//    Goober.TransformObjectSize(2.0f, 2.0f, 2.0f);
//    Goober.SetCollider(gooberPos, Vector3(5.0f, 5.0f, 5.0f));
//    Goober.Apply_Color(GooberColor);
//    Goober.Create3DSphere(1.5f, 20.0f, 10.0f);
//
//    // Wings
//    GooberWing1.Apply_Color(GooberWingColor);
//    GooberWing2.Apply_Color(GooberWingColor);
//    GooberWing1.TransformObjectPosition(-1.5f, -0.5f, -1);
//    GooberWing2.TransformObjectPosition(1.5f, -0.5f, -1);
//    GooberWing1.Create3DSphere(1.2f, 20.0f, 10.0f);
//    GooberWing2.Create3DSphere(1.2f, 20.0f, 10.0f);
//    GooberWing1.SetParent(&Goober);
//    GooberWing2.SetParent(&Goober);
//
//    // ===== COLLISION DETECTION =====
//    bool hitFrog = Goober.CheckCollision(frogPart1);
//    bool hitTongueEnd = false;
//
//    if (tongueIsActive) {
//        hitTongueEnd = Goober.CheckCollision(tongueEnd);
//
//        // Manual distance check as backup
//        Vector3 tonguePos = tongueEnd.GetObjectPosition();
//        float dx = gooberPos.x - tonguePos.x;
//        float dy = gooberPos.y - tonguePos.y;
//        float dz = gooberPos.z - tonguePos.z;
//        float distance = sqrt(dx * dx + dy * dy + dz * dz);
//
//        // If within 15 units, force collision
//        if (distance < 15.0f) {
//            hitTongueEnd = true;
//            cout << "[COLLISION] Manual detection! Distance: " << distance << endl;
//        }
//    }
//
//    // ✅ DEBUG: Check if collision is detected
//    if (hitTongueEnd) {
//        cout << "!!! TONGUE END HIT DETECTED !!!" << endl;
//    }
//
//    // Debug every 60 frames
//    static int frameCount = 0;
//    if (frameCount++ % 120 == 0)
//    {
//        cout << "\n========== Frame " << frameCount << " ==========";
//        cout << "\nGoober Position: (" << gooberPos.x << ", " << gooberPos.y << ", " << gooberPos.z << ")";
//        cout << "\nFrog Rotation: " << frogRotation << " degrees";
//        cout << "\nTongue Extension: " << tongueExtension;
//        cout << "\nTongue Active: " << (tongueIsActive ? "YES" : "NO");
//
//        if (tongueIsActive) {
//            Vector3 tonguePos = tongueEnd.GetObjectPosition();
//            cout << "\nTongue Tip Position: (" << tonguePos.x << ", " << tonguePos.y << ", " << tonguePos.z << ")";
//
//            float dx = gooberPos.x - tonguePos.x;
//            float dy = gooberPos.y - tonguePos.y;
//            float dz = gooberPos.z - tonguePos.z;
//            float distance = sqrt(dx * dx + dy * dy + dz * dz);
//            cout << "\nDistance to Goober: " << distance;
//        }
//
//        cout << "\nCurrent Score: " << GlobalScore;
//        cout << "\n================================\n" << endl;
//    }
//
//    // ===== MOVEMENT (only if not colliding) =====
//    if (!hitFrog && !hitTongueEnd)
//    {
//        Vector3 GooberLERP = GetLERPObjects(Goober, frogPart1, 0.0055f);
//        Goober.TransformObjectPosition(GooberLERP);
//    }
//
//    // ===== COLLISION RESPONSE =====
//    if (hitTongueEnd)
//    {
//        cout << "\n*** CAUGHT FLY WITH TONGUE! ***" << endl;
//        AddScore();
//        RespawnGoober();
//    }
//    else if (hitFrog)
//    {
//        cout << "\n*** Hit frog body (no score) ***" << endl;
//        RespawnGoober();
//    }
//}
//
//int main(int argc, char** argv)
//{
//    PlaySong(L"PlaygroundDayz.wav");
//    PrepEngine(argc, argv);
//    Initialize();
//
//    return 0;
//}