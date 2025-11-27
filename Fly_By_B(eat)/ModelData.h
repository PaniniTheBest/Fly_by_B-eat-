#pragma once
#ifndef MODEL_DATA_H
#define MODEL_DATA_H

#include "vector"
using namespace std;

// the pairing of vertex and normals
struct Face {
	vector<int> VertexIndex;
	vector<int> NormalIndex;
};
#endif