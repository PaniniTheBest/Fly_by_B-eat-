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
#include "ImageLoader.h"

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
	void Apply_Color(float r, float g, float b, float a);
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
	Collider GetCollider();
	//LERP	
	void TrackPoint(float MoveSpeed, Vector3 LERP, Vector3 Point1, Vector3 Point2);
	//PARENTS || GROUPING 
	void SetParent(RenderObjects* newParent);
	void ApplyParentTransform() const;
	Vector3 GetWorldPosition();
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
#endif

