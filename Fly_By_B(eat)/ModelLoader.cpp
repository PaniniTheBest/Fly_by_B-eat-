#include "ModelLoader.h"

ModelLoader::ModelLoader() {}

void ModelLoader::ExtractVertexId(char* Face, char* Target)
{
	int i = 0;
	while (Face[i] != '\0')
	{
		if (Face[i] == '/')
		{
			Target[i] = '\0';
			break;
		}
		else
		{
			Target[i] = Face[i];
		}
		i++;
	}
	return;
}

void ModelLoader::ExtractNormalId(char* Face, char* Target)
{
	int sCount = 0;//Slash count
	int i = 0;
	int j = 0;

	while (Face[i] != '\0')
	{
		if (Face[i] == '/')
		{
			sCount++;
		}
		else
		{
			if (sCount == 2)
			{
				Target[j] = Face[i];
				j++;
			}
		}
		i++;
	}
	Target[j] = '\0';
	return;
}

bool ModelLoader::ContainSlash(char* String, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (String[i] == '/')
			return true;
		else if (String[i] == '\0')
			break;
	}
	return false;
}

//reads the obj file in the specified file path
void ModelLoader::LoadOBJ(string filePath)
{
	ifstream ifs(filePath);
	char data[100];
	while (ifs)
	{
		ifs >> data; //Extract 1 word from the file
		if (strcmp(data, "v") == 0)
		{
			float x, y, z; //Vertex data

			//Extract x, y, z components
			ifs >> x;
			ifs >> y;
			ifs >> z;

			Vector3 vert; //Create Vertex3D object
			vert.x = x;
			vert.y = y;
			vert.z = z;

			//Add the vertex into the vector
			Vertices.push_back(vert);
		}
		else if (strcmp(data, "vn") == 0)
		{
			float x, y, z; //Vertex normal

			//Extract vertex normal
			ifs >> x;
			ifs >> y;
			ifs >> z;

			Vector3 norm; //Create Normal3D object
			norm.x = x;
			norm.y = y;
			norm.z = z;

			//Add this normal into the vector
			Normals.push_back(norm);
		}

		else if (strcmp(data, "f") == 0)
		{
			char faceData[100]; //Face data
			Face myFace;
			while (true)
			{
				ifs >> faceData; //Extract next data
				if (ContainSlash(faceData, 100)) //Check if data is valid
				{
					char Vertexindx[15];
					char Normalindx[15];

					ExtractVertexId(faceData, Vertexindx);
					ExtractNormalId(faceData, Normalindx);

					int vIndex = atoi(Vertexindx);
					int nIndex = atoi(Normalindx);

					myFace.VertexIndex.push_back(vIndex);
					myFace.NormalIndex.push_back(nIndex);
				}
				else
				{
					Faces.push_back(myFace); //INVALID face data
					ifs.unget();
					break;
				}
			}
		}
	}
}

//draws the parsed obj data from LoadOBJ using Polygons
void ModelLoader::RenderModel()
{
	glLineWidth(1);
	for (int i = 0; i < Faces.size(); i++)
	{
		glBegin(GL_POLYGON);
		for (int j = 0; j < Faces[i].NormalIndex.size(); j++)
		{
			int Normalindx = Faces[i].NormalIndex[j] - 1; //Get the normal
			float x, y, z;

			x = Normals[Normalindx].x;
			y = Normals[Normalindx].y;
			z = Normals[Normalindx].z;

			glNormal3f(x, y, z);
			//Get the vertex
			int Vertexindx = Faces[i].VertexIndex[j] - 1;

			x = Vertices[Vertexindx].x;
			y = Vertices[Vertexindx].y;
			z = Vertices[Vertexindx].z;

			glVertex3f(x, y, z);
		}
		glEnd();
	}
}