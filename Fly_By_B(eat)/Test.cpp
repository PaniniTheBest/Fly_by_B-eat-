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
//#include "Rope.h"
//
//float value = 0.0f;
//float rotateAngle = 0.0f;
//Vector3 playerPosition(0, 0, 0);
//Vector3 playerRotation(0, 0, 0);
//float playerAngle = 0.0f;
//RenderObjects player;
//RenderObjects otherObject;
//camera cam;
////Enemy Test
//RenderObjects floorz;
////Create game objects with colliders
//RenderObjects player;
//
//void InitiateRender()
//{
//   /* glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_COLOR_MATERIAL);*/
//    _textureId = InitializeTexture("vtr4.bmp");
//}
//
//void Update()
//{
//    //   ObjTest1.TransformObjectPosition(10.0f, 0.0f, 20.0f);
////   ObjTest1.TransformObjectSize(-1.0f, 5.0f, 0.0f);
////   ObjTest1.Apply_Color(255, 0, 0);
////   ObjTest1.Create3DCube(2, 2, 5);
//   //ObjTest1.SetCollider(ObjTest1.GetObjectPosition(), ObjTest1.GetObjectSize());
//
////   //EVERYTHING BELOW HERE IS LERP//
//// /*  ObjTest_2.TransformObjectPosition(-10.0f, 0.01f, 0.0f);*/
////   Vector3 toLERP = GetLERPObjects(ObjTest_2, ObjTest1, 0.1);
////   
////   //glPushMatrix();
////   ObjTest_2.SetCollider(ObjTest_2.GetObjectPosition(), ObjTest_2.GetObjectSize());
////   if (!ObjTest_2.CheckCollision(ObjTest1))
////   {
////       ObjTest_2.TrackPoint(movementSpeed, toLERP, ObjTest_2.GetObjectPosition(), ObjTest1.GetObjectPosition());
////   }
////   
////   ObjTest_2.Apply_Color(0, 255, 0, 100);
////   ObjTest_2.Create3DCylinder(4.0f, 4.0f, 8);
//// 
////if (startHitTimer == true)
////{
////    float Timer = 0;
////    Text HitMarker;
////    Vector3 HitMarkerFadePoint(-35.0f, 0.0f, -21.0f);
////    Vector3 HitMarkerLERP = GetLERPPoints(HitMarker.GetCurrentPosition(), HitMarkerFadePoint, 0.1);
////    HitMarker.ColorText(255.0f, 0.0f, 0.0f);
////    HitMarker.TranslateText(-35.0f, 0.0f, -20.0f);
////    //HitMarker.TranslateText(HitMarkerLERP);
////    HitMarker.RenderText("HIT!!!");
////}
///*glPopMatrix();*/
////Text LERPx, LERPy, LERPz;
////LERPx.ColorText(255.0f, 0.0f, 0.0f);
////LERPx.TranslateText(-4.0f, 10.0f, 0.0f);
////LERPx.RenderVariableAsText(toLERP.x);
//
////LERPy.ColorText(0.0, 255.0f, 0.0f);
////LERPy.TranslateText(-4.0f, 11.0f, 0.0f);
////LERPy.RenderVariableAsText(toLERP.y);
//
////LERPz.ColorText(0.0f, 0.0f, 255.0f);
////LERPz.TranslateText(-4.0f, 12.0f, 0.0f);
////LERPz.RenderVariableAsText(toLERP.z);
//
////==================================================================================
//// 
////  \/  \/ Apply these inside of 3D object functions; \/ \/
//// 
////==================================================================================  
//    //rotateAngle += 1.0f;
//    ////TEXTURE TEST //
//    //StartEnablingTextures();
//    //BindSelectTexture(_textureId);
//
//    ////Bottom
//    //RenderType(true, true);
//    //glColor3f(1.0f, 0.2f, 0.2f);
//    //glBegin(GL_QUADS);
//
//    //glNormal3f(0.0, 1.0f, 0.0f);
//    //glTexCoord2f(0.0f, 0.0f);
//    //glVertex3f(-2.5f, -2.5f, 2.5f);
//    //glTexCoord2f(1.0f, 0.0f);
//    //glVertex3f(2.5f, -2.5f, 2.5f);
//    //glTexCoord2f(1.0f, 1.0f);
//    //glVertex3f(2.5f, -2.5f, -2.5f);
//    //glTexCoord2f(0.0f, 1.0f);
//    //glVertex3f(-2.5f, -2.5f, -2.5f);
//
//    //glEnd();
//
//    ////Back
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    //glColor3f(1.0f, 1.0f, 1.0f);
//    //glBegin(GL_TRIANGLES);
//
//    //glNormal3f(0.0f, 0.0f, 1.0f);
//    //glTexCoord2f(0.0f, 0.0f);
//    //glVertex3f(-2.5f, -2.5f, -2.5f);
//    //glTexCoord2f(5.0f, 5.0f);
//    //glVertex3f(0.0f, 2.5f, -2.5f);
//    //glTexCoord2f(10.0f, 0.0f);
//    //glVertex3f(2.5f, -2.5f, -2.5f);
//
//    //glEnd();
//
//    ////Left
//    //glDisable(GL_TEXTURE_2D);
//    //glColor3f(1.0f, 0.7f, 0.3f);
//    //glBegin(GL_QUADS);
//
//    //glNormal3f(1.0f, 0.0f, 0.0f);
//    //glVertex3f(-2.5f, -2.5f, 2.5f);
//    //glVertex3f(-2.5f, -2.5f, -2.5f);
//    //glVertex3f(-2.5f, 2.5f, -2.5f);
//    //glVertex3f(-2.5f, 2.5f, 2.5f);
//
//    //glEnd();
//}