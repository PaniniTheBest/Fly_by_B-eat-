#include "RenderObjects.h"

const float PI = 3.14; // Value of PI  

//Initialized Variables
RenderObjects::RenderObjects()
{
	angle = 0.0f;
	objectColor.SetColor(255.0f, 255.0f, 255.0f, 1.0f);
	setPosition.SetValue(0.0f, 0.0f, 0.0f);
	setRotationValue.SetValue(0.0f, 0.0f, 0.0f);
	setScale.SetValue(1.0f, 1.0f, 1.0f);
};
//COLOR
void RenderObjects::Apply_Color(float r, float g, float b) //RGB values 
{
	this->objectColor.SetColor(r, g, b);
}
void RenderObjects::Apply_Color(float r, float g, float b, float a) //RGB values with Opacity(aka Alpha)
{
	this->objectColor.SetColor(r, g, b, a);
}
void RenderObjects::Apply_Color(Color newColor)//RGBA values that supports Color.h
{
	this->objectColor.SetColor (newColor);
}
//TRANSFORM POSITION
void RenderObjects::TransformObjectPosition(float x, float y, float z) //Sets position of an Object
{
	setPosition.SetValue(x, y, z);
}
void RenderObjects::TransformObjectPosition(Vector3 setNewPosition)//Sets position of an Object with Vector3
{
	setPosition.SetValue(setNewPosition);
}
Vector3 RenderObjects::GetObjectPosition()
{
	return setPosition;
}
//TRANSFORM ROTATION
void RenderObjects::TransformObjectRotation(float shapeAngle, float x, float y, float z)
{
	angle = shapeAngle; 
	setRotationValue.SetValue(x, y, z);	
}
void RenderObjects::TransformObjectRotation(float shapeAngle, Vector3 setNewRotationValue)
{
	angle = shapeAngle;
	setRotationValue.SetValue(setNewRotationValue);
}
Vector3 RenderObjects::GetObjectRotation()
{
	return setRotationValue;
}
//TRANSFORM SIZE
void RenderObjects::TransformObjectSize(float x, float y, float z)
{
	setRotationValue.SetValue(x, y, z);
}
void RenderObjects::TransformObjectSize(Vector3 setNewScale)
{
	setScale.SetValue(setNewScale);
}
Vector3 RenderObjects::GetObjectSize()
{
	return setScale;
}
//Types of shapes
void RenderObjects::Create3DCube(float x, float y, float z)
{   
    glPushMatrix();
    glColor4f(objectColor.red, objectColor.green, objectColor.blue, objectColor.alpha);
    glTranslatef(setPosition.x, setPosition.y, setPosition.z);
    glRotatef(angle, setRotationValue.x, setRotationValue.y, setRotationValue.z);
    glScalef(setScale.x, setScale.y, setScale.z);

    glBegin(GL_QUADS);// Face 1 X-axis
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 2 X-axis
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 3 Y-axis 
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 4 Y-axis 
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glEnd(); 
    
    glBegin(GL_QUADS);// Face 5 Z-axis
    glVertex3f(-0.5f * x, -0.5f * y, -0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, -0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, -0.5f * z);
    glEnd();

    glBegin(GL_QUADS);// Face 6 Z-axis
    glVertex3f(-0.5f * x, -0.5f * y, 0.5f * z);
    glVertex3f(-0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, 0.5f * y, 0.5f * z);
    glVertex3f(0.5f * x, -0.5f * y, 0.5f * z);
    glEnd();
    glPopMatrix();
}
void RenderObjects::Create3DCube(Vector3 boxScale)
{
	glPushMatrix();
	glColor4f(objectColor.red, objectColor.green, objectColor.blue, objectColor.alpha);
	glTranslatef(setPosition.x, setPosition.y, setPosition.z);
	glRotatef(angle, setRotationValue.x, setRotationValue.y, setRotationValue.z);
	glScalef(setScale.x, setScale.y, setScale.z);

	glBegin(GL_QUADS);// Face 1 X-axis
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glEnd();

	glBegin(GL_QUADS);// Face 2 X-axis
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glEnd();

	glBegin(GL_QUADS);// Face 3 Y-axis 
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glEnd();

	glBegin(GL_QUADS);// Face 4 Y-axis 
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glEnd();

	glBegin(GL_QUADS);// Face 5 Z-axis
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, -0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, -0.5f * boxScale.z);
	glEnd();

	glBegin(GL_QUADS);// Face 6 Z-axis
	glVertex3f(-0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(-0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, 0.5f * boxScale.y, 0.5f * boxScale.z);
	glVertex3f(0.5f * boxScale.x, -0.5f * boxScale.y, 0.5f * boxScale.z);
	glEnd();
	glPopMatrix();
}
void RenderObjects::Create3DSphere(double radius, double slices, double stacks)
{
	glPushMatrix();
	ApplyParentTransform();
	glColor4f(objectColor.red, objectColor.green, objectColor.blue, objectColor.alpha);
	glTranslatef(setPosition.x, setPosition.y, setPosition.z);
	glRotatef(angle, setRotationValue.x, setRotationValue.y, setRotationValue.z);
	glScalef(setScale.x, setScale.y, setScale.z);
	glutSolidSphere(radius, (int)slices, (int)stacks);

	glPopMatrix();
}
void RenderObjects::Create3DCone(float radius, float height, int slices)
{   
	/*
	* Credits to "Jiew Meng" & "Nobody moving away from SE" for the Cone function
	* https://stackoverflow.com/questions/19245363/opengl-glut-surface-normals-of-cone
	*/
    float angleIncrement = (2.0f * PI) / slices;// Calculate angle increment based on number of slices
    float renderAngle = 0.0f;
    glPushMatrix(); 
    glColor4f(objectColor.red, objectColor.green, objectColor.blue, objectColor.alpha);
    glTranslatef(setPosition.x, setPosition.y, setPosition.z);   
    glRotatef(angle, setRotationValue.x, setRotationValue.y, setRotationValue.z);
    glScalef(setScale.x, setScale.y, setScale.z);

    // Draws the sides of the cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  // Tip
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();

    // Draws the base of the cone
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  // Center of base
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, -1, 0);  // Normal pointing down for base
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();
    glPopMatrix(); 
}
void RenderObjects::Create3DCylinder(float radius, float height, int slices)
{   
    float angleIncrement = (2.0f * PI) / slices;// Calculate angle increment based on number of slices
    float renderAngle = 0.0f;
    glPushMatrix();
	
    glColor4f(objectColor.red, objectColor.green, objectColor.blue, objectColor.alpha);
    glTranslatef(setPosition.x, setPosition.y, setPosition.z); 
	glRotatef(angle, setRotationValue.x, setRotationValue.y, setRotationValue.z);
    glScalef(setScale.x, setScale.y, setScale.z);

    // Draws top side of Cylinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);  // Center of top cap
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, 1, 0);  // top side
        glVertex3f(cos(renderAngle) * radius, height, sin(renderAngle) * radius);
    }
    glEnd();
    // Draws bottom side of Cylinder
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);  // Center of base
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(0, -1, 0);  //bottom side
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
    }
    glEnd();
    // Draws sides of Cylinder
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        renderAngle = i * angleIncrement;
        glNormal3f(cos(renderAngle), 0, sin(renderAngle));  // Outward normal
        glVertex3f(cos(renderAngle) * radius, 0, sin(renderAngle) * radius);
        glVertex3f(cos(renderAngle) * radius, height, sin(renderAngle) * radius);
    }

    glEnd();
    glPopMatrix();
}
//Collider for Objects
void RenderObjects::SetCollider(Vector3 position, Vector3 scale)
{
	collider.SetDimension(position, scale);
}
bool RenderObjects::CheckCollision(RenderObjects other)
{
	return collider.CheckCollision(other.collider);
}
Vector3 RenderObjects::GetColliderScale()
{
	return setScale;
}
Vector3 RenderObjects::GetColliderPosition()
{
	return setPosition;
}
Collider RenderObjects::GetCollider()
{
	return collider;
}
//LERP aka Object tracking
void RenderObjects::TrackPoint(float MoveSpeed, Vector3 LERP, Vector3 Point1, Vector3 Point2) //Moves object towards a point using LERP values
{
	setPosition.x += LERP.x * MoveSpeed;
	setPosition.y += LERP.y * MoveSpeed;
	setPosition.z += LERP.z * MoveSpeed;
}
//GROUPING || PARENTS
void RenderObjects::SetParent(RenderObjects* newParent)
{
	
	if (newParent == this) {
		parent = nullptr;
		return;
	}

	RenderObjects* p = newParent;
	while (p != nullptr) {
		if (p == this) { 
			parent = nullptr;
			return;
		}
		p = p->parent;
	}
	parent = newParent;
}
void RenderObjects::ApplyParentTransform() const
{
	if (parent == nullptr) return;


	parent->ApplyParentTransform();


	glTranslatef(parent->setPosition.x, parent->setPosition.y, parent->setPosition.z);
	glRotatef(parent->angle,
		parent->setRotationValue.x,
		parent->setRotationValue.y,
		parent->setRotationValue.z);
	glScalef(parent->setScale.x, parent->setScale.y, parent->setScale.z);
}
//to be removed
//void RenderObjects::AddForce(float x, float y, float z)
//{
//	physics.AddForce(x, y, z);
//}
//void RenderObjects::AddForce(Vector3 newForce)
//{
//	physics.AddForce(newForce.x, newForce.y, newForce.z);
//}

void RenderObjects::UpdatePhysics(float deltaTime)
{
	physics.UpdatePhysics(deltaTime, setPosition.x, setPosition.y, setPosition.z);
}
void RenderObjects::SetMass(float m)
{
	physics.SetMass(m);
}
void RenderObjects::SetDrag(float d)
{
	physics.SetDrag(d);
}
void RenderObjects::SetUseGravity(bool enabled)
{
	physics.UseGravity(enabled);
}
//following is to be removed:
void RenderObjects::GetCurrentPosition(float& x, float& y, float& z)
{
	x = setPosition.x;
	y = setPosition.y;
	z = setPosition.z;
}
void RenderObjects::GetCurrentPosition(Vector3& currentPosition)
{
	currentPosition.x = setPosition.x;
	currentPosition.y = setPosition.y;
	currentPosition.z = setPosition.z;
}
void RenderObjects::SetVelocity(float x, float y, float z)
{
	physics.SetVelocity(x, y, z);
}
void RenderObjects::SetVelocity(Vector3 newVelocity)
{
	physics.SetVelocity(newVelocity.x, newVelocity.y, newVelocity.z);
}
void RenderObjects::GetVelocity(float& x, float& y, float& z)
{
	physics.GetVelocity(x, y, z);
}
void RenderObjects::GetVelocity(Vector3& currentVelocity)
{
	physics.GetVelocity(currentVelocity.x, currentVelocity.y, currentVelocity.z);
}
//==============================================================================
//				\/ \/	Make this its own Header file	\/  \/
//==============================================================================

#include <fstream>
#include <math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif

#include "RenderObjects.h"

using namespace std;

T3DLoadException::T3DLoadException(string message1) : message0(message1) {}

string T3DLoadException::message() const {
	return message0;
}

namespace {
	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes) {
		return int(((unsigned char)bytes[3] << 24) |
			((unsigned char)bytes[2] << 16) |
			((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Converts a five-character array to a float, as indicated in the comment at
	//the top of this file
	float toFloat(const char* buffer) {
		char exp = buffer[0];
		int mant = toInt(buffer + 1);
		bool isNegative;
		if (mant < 0) {
			isNegative = true;
			mant = ~mant;
		}
		else
			isNegative = false;
		float a = (2147483648u + (unsigned int)mant) *
			pow(2.0f, exp) / 2147483648.0;
		return isNegative ? -a : a;
	}

	//Converts a two-character array to an unsigned short, using little-endian
	//form
	unsigned short toUShort(const char* buffer) {
		return (((unsigned short)((unsigned char)buffer[1])) << 8) +
			(unsigned short)((unsigned char)buffer[0]);
	}

	//Just like auto_ptr, but for arrays
	template<class T>
	class auto_array {
	private:
		T* array;
		mutable bool isReleased;
	public:
		explicit auto_array(T* array_ = NULL) :
			array(array_), isReleased(false) {
		}

		auto_array(const auto_array<T>& aarray) {
			array = aarray.array;
			isReleased = aarray.isReleased;
			aarray.isReleased = true;
		}

		~auto_array() {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
		}

		T* get() const {
			return array;
		}

		T& operator*() const {
			return *array;
		}

		void operator=(const auto_array<T>& aarray) {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
			array = aarray.array;
			isReleased = aarray.isReleased;
			aarray.isReleased = true;
		}

		T* operator->() const {
			return array;
		}

		T* release() {
			isReleased = true;
			return array;
		}

		void reset(T* array_ = NULL) {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
			array = array_;
		}

		T* operator+(int i) {
			return array + i;
		}

		T& operator[](int i) {
			return array[i];
		}
	};

	enum Opcodes {
		OP_NORMAL = 65532,
		OP_TRIANGLE_STRIP,
		OP_TRIANGLES,
		OP_END_PART
	};

	const float PI_TIMES_2_OVER_65536 = 2 * 3.1415926535f / 65536.0f;

	class T3DFont {
	private:
		float spaceWidth;
		float widths[94];
		GLuint displayListId2D;
		GLuint displayListId3D;
	public:
		//Loads the specified font file into a new T3DFont object
		T3DFont(ifstream& input) {
			char buffer[8];
			input.read(buffer, 8);
			if (input.fail()) {
				throw T3DLoadException("Invalid font file");
			}

			const char header[9] = "VTR\0FNT\0";
			for (int i = 0; i < 8; i++) {
				if (buffer[i] != header[i]) {
					throw T3DLoadException("Invalid font file");
				}
			}

			input.read(buffer, 5);
			spaceWidth = toFloat(buffer);

			displayListId2D = glGenLists(94);
			displayListId3D = glGenLists(94);
			for (int i = 0; i < 94; i++) {
				input.read(buffer, 5);
				float scale = toFloat(buffer) / 65536;
				input.read(buffer, 2);
				float width = scale * toUShort(buffer);
				input.read(buffer, 2);
				float height = scale * toUShort(buffer);
				scale /= height;
				widths[i] = width / height;
				input.read(buffer, 2);
				unsigned short numVerts = toUShort(buffer);
				auto_array<float> verts(new float[2 * numVerts]);
				float* verts2 = verts.get();
				for (int j = 0; j < numVerts; j++) {
					input.read(buffer, 2);
					verts2[2 * j] = scale * ((int)toUShort(buffer) - 32768);
					input.read(buffer, 2);
					verts2[2 * j + 1] =
						scale * ((int)toUShort(buffer) - 32768);
				}

				//Face part of the model
				glNewList(displayListId2D + i, GL_COMPILE);

				glNormal3f(0, 0, 1);

				input.read(buffer, 2);
				unsigned short opcode = toUShort(buffer);
				switch (opcode) {
				case OP_TRIANGLES:
					glBegin(GL_TRIANGLES);
					break;
				case OP_TRIANGLE_STRIP:
					glBegin(GL_TRIANGLE_STRIP);
					break;
				default:
					throw T3DLoadException("Invalid font file");
				}

				//Prevents excessive iteration or infinite loops on invalid
				//font files
				int limit = 10000;

				while (true) {
					input.read(buffer, 2);
					opcode = toUShort(buffer);
					switch (opcode) {
					case OP_TRIANGLES:
						glEnd();
						glBegin(GL_TRIANGLES);
						break;
					case OP_TRIANGLE_STRIP:
						glEnd();
						glBegin(GL_TRIANGLE_STRIP);
						break;
					case OP_END_PART:
						goto BreakOuter;
					default:
						glVertex3f(verts2[2 * opcode],
							verts2[2 * opcode + 1],
							0);
						break;
					}

					if (--limit == 0) {
						glEndList();
						throw T3DLoadException("Invalid font file");
					}
				}
			BreakOuter:
				glEnd();
				glEndList();

				//3D part of the model
				glNewList(displayListId3D + i, GL_COMPILE);
				glPushMatrix();
				glTranslatef(0, 0, 0.5f);
				glFrontFace(GL_CW);
				glCallList(displayListId2D + i);
				glTranslatef(0, 0, -1);
				glScalef(1, 1, -1);
				glFrontFace(GL_CCW);
				glCallList(displayListId2D + i);
				glFrontFace(GL_CW);

				input.read(buffer, 2);
				opcode = toUShort(buffer);
				switch (opcode) {
				case OP_TRIANGLES:
					glBegin(GL_TRIANGLES);
					break;
				case OP_TRIANGLE_STRIP:
					glBegin(GL_TRIANGLE_STRIP);
					break;
				default:
					throw T3DLoadException("Invalid font file");
				}

				limit = 10000;
				while (true) {
					input.read(buffer, 2);
					opcode = toUShort(buffer);
					switch (opcode) {
					case OP_TRIANGLES:
						glEnd();
						glBegin(GL_TRIANGLES);
						break;
					case OP_TRIANGLE_STRIP:
						glEnd();
						glBegin(GL_TRIANGLE_STRIP);
						break;
					case OP_NORMAL:
						input.read(buffer, 2);
						float angle;
						angle = toUShort(buffer) *
							PI_TIMES_2_OVER_65536;
						float x, y;
						x = cos(angle);
						y = sin(angle);
						glNormal3f(x, y, 0);
						break;
					case OP_END_PART:
						goto BreakOuter2;
					default:
						if (opcode < numVerts) {
							glVertex3f(verts2[2 * opcode],
								verts2[2 * opcode + 1],
								0);
						}
						else {
							glVertex3f(verts2[2 * (opcode - numVerts)],
								verts2[2 * (opcode - numVerts) +
								1],
								-1);
						}
						break;
					}

					if (--limit == 0) {
						glEndList();
						throw T3DLoadException("Invalid font file");
					}
				}
			BreakOuter2:
				glEnd();
				glPopMatrix();
				glEndList();
			}

			if (input.fail()) {
				throw T3DLoadException("Invalid font file");
			}
			input.read(buffer, 1);
			if (!input.eof()) {
				throw T3DLoadException("Invalid font file");
			}
		}

		void draw2D(char c) {
			if (c >= 33 && c <= 126) {
				glCallList(displayListId2D + c - '!');
			}
		}

		void draw3D(char c) {
			if (c >= 33 && c <= 126) {
				glCallList(displayListId3D + c - '!');
			}
		}

		float width(char c) {
			if (c >= 33 && c <= 126) {
				return widths[c - 33];
			}
			else {
				return spaceWidth;
			}
		}
	};

	T3DFont* font = NULL; //The font used to draw 2D and 3D characters

	void draw2D(char c) {
		font->draw2D(c);
	}

	void draw3D(char c) {
		font->draw3D(c);
	}

	void drawLine(const char* str, int hAlign, void (*drawFunc)(char)) {
		glPushMatrix();
		if (hAlign >= 0) {
			float width = 0;
			for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
				width += font->width(str[i]);
			}
			glTranslatef(hAlign > 0 ? -width : -width / 2, 0, 0);
		}

		for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
			float width = font->width(str[i]);
			glTranslatef(width / 2, 0, 0);
			drawFunc(str[i]);
			glTranslatef(width / 2, 0, 0);
		}

		glPopMatrix();
	}

	void draw(const char* str,
		int hAlign, int vAlign,
		float lineHeight,
		void (*drawFunc)(char)) {
		GLint shadeModel;
		glGetIntegerv(GL_SHADE_MODEL, &shadeModel);
		glShadeModel(GL_SMOOTH);
		GLboolean lightsEnabled;
		glGetBooleanv(GL_LIGHTING, &lightsEnabled);
		GLboolean normalsWereNormalized;
		glGetBooleanv(GL_NORMALIZE, &normalsWereNormalized);
		if (lightsEnabled) {
			glEnable(GL_NORMALIZE);
		}
		else {
			glDisable(GL_NORMALIZE);
		}

		glPushMatrix();
		if (vAlign >= 0) {
			int numLines = 1;
			for (int i = 0; str[i] != '\0'; i++) {
				if (str[i] == '\n') {
					numLines++;
				}
			}

			float height = lineHeight * (numLines - 1) + 1;
			glTranslatef(0, vAlign > 0 ? height : height / 2, 0);
		}

		glTranslatef(0, -0.5f, 0);
		drawLine(str, hAlign, drawFunc);
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '\n') {
				glTranslatef(0, -lineHeight, 0);
				drawLine(str + i + 1, hAlign, drawFunc);
			}
		}

		glPopMatrix();

		glShadeModel(shadeModel);
		if (normalsWereNormalized) {
			glEnable(GL_NORMALIZE);
		}
		else {
			glDisable(GL_NORMALIZE);
		}
	}
}

void t3dInit() {
	if (font == NULL) {
		ifstream input;
		input.open("charset", istream::binary);
		font = new T3DFont(input);
		input.close();
	}
}

void t3dCleanup() {
	delete font;
}

void t3dDraw2D(string str, int hAlign, int vAlign, float lineHeight) {
	GLboolean wasCulling;
	glGetBooleanv(GL_CULL_FACE, &wasCulling);
	glDisable(GL_CULL_FACE);

	draw(str.c_str(), hAlign, vAlign, lineHeight, draw2D);

	if (wasCulling) {
		glEnable(GL_CULL_FACE);
	}
}

void t3dDraw3D(string str,
	int hAlign, int vAlign,
	float depth,
	float lineHeight) {
	GLboolean wasCulling;
	glGetBooleanv(GL_CULL_FACE, &wasCulling);
	glEnable(GL_CULL_FACE);
	GLint frontFace;
	glGetIntegerv(GL_FRONT_FACE, &frontFace);

	glPushMatrix();
	glScalef(1, 1, depth);
	draw(str.c_str(), hAlign, vAlign, lineHeight, draw3D);
	glPopMatrix();

	if (!wasCulling) {
		glDisable(GL_CULL_FACE);
	}
	glFrontFace(frontFace);
}

float t3dDrawWidth(string str) {
	float bestWidth = 0;
	int i = 0;
	while (str[i] != '\0') {
		float width = 0;
		while (str[i] != '\n' && str[i] != '\0') {
			width += font->width(str[i]);
			i++;
		}
		if (width > bestWidth) {
			bestWidth = width;
		}
		if (str[i] != '\0') {
			i++;
		}
	}
	return bestWidth;
}

float t3dDrawHeight(string str, float lineHeight) {
	int numLines = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n') {
			numLines++;
		}
	}

	return (numLines - 1) * lineHeight + 1;
}