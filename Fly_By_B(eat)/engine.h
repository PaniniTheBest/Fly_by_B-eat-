#ifndef ENGINE_H
#define ENGINE_H

// Include all the libraries and header files used here
#include <vector>
#include "ImageLoader.h"
#include "AudioManager.h"
#include "Text.h"
#include "Camera.h"
#include "Camera2.h"
#include "Input.h"
#include "Graphics.h"

#include "RenderObjects.h"


void InitiateRender();

void Initialize();
void Update();
void PrepEngine(int argc, char** argv);
float FindDeltaTime();
float LinearInterpolate(float currentPos, float farawayPos, float t);
Vector3 GetLERPObjects(RenderObjects Origin, RenderObjects Destination, float t); //This function is specified for objects of the 3D Objects class//
Vector3 GetLERPPoints(Vector3 Origin, Vector3 Destination, float t); //This function is specified for objects of a select Vector3//

#endif
//test