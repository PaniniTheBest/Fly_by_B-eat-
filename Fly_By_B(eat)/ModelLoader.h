#pragma once
#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "ModelData.h"
#include "vector3.h"
#include "string"
#include "graphics.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ModelLoader {
private:
	vector<Vector3> Vertices;
	vector<Vector3> Normals;
	vector<Face> Faces;

	// Parse the data from the actual obj file
	void ExtractVertexId(char* Face, char* Target);
	void ExtractNormalId(char* Face, char* Target);
	bool ContainSlash(char* string, int count);

public:
	ModelLoader();
	void LoadOBJ(string filePath);
	void RenderModel();
};
#endif