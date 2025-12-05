#ifndef RENDEROBJECTS_H
#define RENDEROBJECTS_H
#include "glut.h"
#include <cmath>
#include "RenderObjects.h" 
#include "Collider.h"
#include "vector3.h"
#include <string>
#include "Color.h"
#include "Physics.h"

using namespace std;
class RenderObjects
{
	private:
		float angle;//Rotation	
		//Vector3
		Vector3 setPosition;
		Vector3 setRotationValue;
		Vector3 setScale;

		Collider collider;
		Color objectColor;

		Physics physics;
	public:
		RenderObjects* parent = nullptr;
		RenderObjects();
		//COLOR
		void Apply_Color(float r, float g, float b);
		void Apply_Color(float r, float g, float b ,float a);
		void Apply_Color(Color newColor);
		//POSITION
		void TransformObjectPosition(float x, float y, float z);
		void TransformObjectPosition(Vector3 setPosition);
		Vector3 GetObjectPosition();
		//ROTATION
		void TransformObjectRotation(float angle, float x, float y, float z);
		void TransformObjectRotation(float angle, Vector3 setRotationValue);
		Vector3 GetObjectRotation();
		//SCALE || SIZE
		void TransformObjectSize(float x, float y, float z);
		void TransformObjectSize(Vector3 setScale);
		Vector3 GetObjectSize();
		//SHAPE TYPES
		void Create3DCube(float x, float y, float z);
		void Create3DCube(Vector3 boxScale);
		void Create3DSphere(double radius, double slices, double stacks);
		void Create3DCone(float radius, float height, int slices);
		void Create3DCylinder(float radius, float height, int slices);
		//COLLISION 
		void SetCollider(Vector3 position, Vector3 scale);
		bool CheckCollision(RenderObjects other);			
		Vector3 GetColliderScale();
		Vector3 GetColliderPosition();
		Collider GetCollider();
		//LERP	
		void TrackPoint(float MoveSpeed, Vector3 LERP, Vector3 Point1, Vector3 Point2);
		//PARENTS || GROUPING 
		void SetParent(RenderObjects* newParent);
		void ApplyParentTransform() const;
		//PHYSICS
		void AddForce(float x, float y, float z);
		void AddForce(Vector3 newForce);
		void UpdatePhysics(float deltaTime);
		void SetMass(float m);
		void SetDrag(float d);
		void SetUseGravity(bool enabled);

		void SetVelocity(float x, float y, float z);
		void SetVelocity(Vector3 newVelocity);
		void GetVelocity(float& x, float& y, float& z);
		void GetVelocity(Vector3& newVelocity);
		void XrayAll(bool xray);
};
//==============================================================================
//				\/ \/	Make this its own Header file	\/  \/
//==============================================================================

//Initializes 3D text.  Must be called before other functions in this header.
void t3dInit();
//Frees memory allocated for 3D text.  No other functions in this header may be
//called after this one.
void t3dCleanup();
/* Draws the specified string, using OpenGL, as a set of polygons in the x-y
 * plane, with the top of the letters having the greatest y coordinate.  The
 * normals point in the positive z direction.  (If you need the normals to point
 * in the positive z direction on one side of the characters and the negative z
 * direction on the other, call t3dDraw3D with a very small depth.)
 *
 * The string is drawn left-aligned if hAlign is negative, right-aligned if it
 * is positive, and centered horizontally if it is 0.  The string is drawn top-
 * aligned if vAlign is negative, bottom-aligned if it is positive, and centered
 * vertically if it is 0.
 *
 * The string may have newline characters, in which case the string will be
 * drawn on multiple lines as one would expect.  The lines are drawn lineHeight
 * times the height of the font apart.  The height of the font is the "normal"
 * height of capital letters, rather than the distance from the top of "normal"
 * capital letters to the bottom of lowercase letters like "p".
 *
 * All unprintable ASCII characters (other than '\n') are drawn as spaces.
 */
void t3dDraw2D(std::string str,
	int hAlign, int vAlign,
	float lineHeight = 1.5f);
/* Draws the specified string, using OpenGL, using polygons as a right prism,
 * where the parallel faces are letters parallel to the x-y plane, with the top
 * of the letters having the greatest y coordinate.
 *
 * The string is drawn left-aligned if hAlign is negative, right-aligned if it
 * is positive, and centered horizontally if it is 0.  The string is drawn top-
 * aligned if vAlign is negative, bottom-aligned if it is positive, and centered
 * vertically if it is 0.
 *
 * The string may have newline characters, in which case the string will be
 * drawn on multiple lines as one would expect.  The lines are drawn lineHeight
 * times the height of the font apart.  The height of the font is the "normal"
 * height of capital letters, rather than the distance from the top of "normal"
 * capital letters to the bottom of lowercase letters like "p".
 *
 * The depth of the characters is depth times the height of the font.  The
 * characters are centered at z = 0.
 *
 * All unprintable ASCII characters (other than '\n') are drawn as spaces.
 */
void t3dDraw3D(std::string str,
	int hAlign, int vAlign,
	float depth,
	float lineHeight = 1.5f);
/* Returns the draw width of the specified string, as a multiple of the height
 * of the font.  The height of the font is the "normal" height of capital
 * letters, rather than the distance from the top of "normal" capital letters to
 * the bottom of lowercase letters like "p".  The width is the same as the width
 * of the longest line.
 */
float t3dDrawWidth(std::string str);
/* Returns the draw height of the specified string, as a multiple of the height
 * of the font.  The height of the font is the "normal" height of capital
 * letters, rather than the distance from the top of "normal" capital letters to
 * the bottom of lowercase letters like "p".  The draw is lineHeight times one
 * fewer than the number of lines in the string, plus 1.
 */
float t3dDrawHeight(std::string str, float lineHeight = 1.5f);

//Indicates that an exception occurred when setting up 3D text
class T3DLoadException {
private:
	std::string message0;
public:
	T3DLoadException(std::string message1);
	std::string message() const;
};

#endif

