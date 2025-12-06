#include "RenderObjects.h"
const float PI = 3.14159f; // Value of PI  

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
	this->objectColor.SetColor(newColor);
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
	ApplyParentTransform();
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
	ApplyParentTransform();
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
	ApplyParentTransform();
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
	ApplyParentTransform();
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
Vector3 RenderObjects::GetWorldPosition()
{
	// Start with local position
	Vector3 worldPos = setPosition;
	// If no parent, just return local position
	if (parent == nullptr) {
		return worldPos;
	}
	// Apply transformations from ALL parents recursively
	const RenderObjects* currentParent = parent;
	while (currentParent != nullptr)
	{
		// Apply parent's rotation to current world position
		if (currentParent->angle != 0.0f && currentParent->setRotationValue.y != 0.0f)
		{
			float angleRad = currentParent->angle * (PI / 180.0f);
			float cosA = cos(angleRad);
			float sinA = sin(angleRad);
			// Rotate around Y-axis
			float newX = worldPos.x * cosA - worldPos.z * sinA;
			float newZ = worldPos.x * sinA + worldPos.z * cosA;
			worldPos.x = newX;
			worldPos.z = newZ;
		}
		// Apply parent's scale
		worldPos.x *= currentParent->setScale.x;
		worldPos.y *= currentParent->setScale.y;
		worldPos.z *= currentParent->setScale.z;
		// Add parent's position
		worldPos.x += currentParent->setPosition.x;
		worldPos.y += currentParent->setPosition.y;
		worldPos.z += currentParent->setPosition.z;
		// Move up the hierarchy
		currentParent = currentParent->parent;
	}
	return worldPos;
}
//AddForce might be removed
void RenderObjects::AddForce(float x, float y, float z)
{
	physics.AddForce(x, y, z);
}
void RenderObjects::AddForce(Vector3 newForce)
{
	physics.AddForce(newForce.x, newForce.y, newForce.z);
}

void RenderObjects::UpdatePhysics(float deltaTime)
{
	physics.UpdatePhysics(deltaTime, setPosition.x, setPosition.y, setPosition.z);
}
void RenderObjects::SetMass(float m) { physics.SetMass(m); }
void RenderObjects::SetDrag(float d) { physics.SetDrag(d); }
void RenderObjects::SetUseGravity(bool enabled) { physics.UseGravity(enabled); }
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
void RenderObjects::XrayAll(bool xray)
{
	xray ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

