#ifndef ENGINE_H
#define ENGINE_H

// Include all the libraries and header files used here
#include "Input.h"
#include "Graphics.h"
#include "Render_3D_Objects.h"
#include <vector>

void InitiateRender();

void Initialize();
void Update();
void PrepEngine(int argc, char** argv);
float FindDeltaTime();

#endif
//test