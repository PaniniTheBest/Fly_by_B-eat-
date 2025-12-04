#include "Physics.h"
const float GRAVITY = -0.98f;
Physics::Physics()
{
    velocity.SetValue(0.0f, 0.0f, 0.0f);
    addForce.SetValue(0.0f, 0.0f, 0.0f);
    mass = 1.0f;
    drag = 0.98f;
    booleanGravity = true;
}

Physics::Physics(float m, float d, bool toggleGravity)
{
    velocity.SetValue(0.0f, 0.0f, 0.0f);  // Added - initialize velocity
    addForce.SetValue(0.0f, 0.0f, 0.0f);
    mass = m;
    drag = d;
    booleanGravity = toggleGravity;
}
//Addforce ... to be removed
void Physics::AddForce(float& x, float& y, float& z)
{
    this -> addForce.x = x;
    this -> addForce.y = y;
    this -> addForce.z = z;
}
void Physics::AddForce(Vector3& addForce)
{
    this->addForce.x = addForce.x;
    this->addForce.y = addForce.y;
    this->addForce.z = addForce.z;
}

void Physics::UpdatePhysics(float deltaTime, float& positionX, float& positionY, float& positionZ)
{
    // Apply gravity automatically if enabled
    if (booleanGravity)
        velocity.y += GRAVITY * mass;
    //Acceleration
    float accelerationX = velocity.x / mass;
    float accelerationY = velocity.y / mass;
    float accelerationZ = velocity.z / mass;

    // Update velocity
    velocity.x += accelerationX * deltaTime;
    velocity.y += accelerationY * deltaTime;
    velocity.z += accelerationZ * deltaTime;

    // Apply drag
    velocity.x *= drag;
    velocity.y *= drag;
    velocity.z *= drag;

    // Update position
    positionX += velocity.x * deltaTime;
    positionY += velocity.y * deltaTime;
    positionZ += velocity.z * deltaTime;

    // Reset forces for next frame
    addForce.x = addForce.y = addForce.z = 0.0f;
}
void Physics::UpdatePhysics(float deltaTime, Vector3& position)
{
    // Apply gravity automatically if enabled
    if (booleanGravity)
        velocity.y += GRAVITY * mass;
    // Acceleration
    float accelerationX = velocity.x / mass;
    float accelerationY = velocity.y / mass;
    float accelerationZ = velocity.z / mass;

    // Update velocity
    velocity.x += accelerationX * deltaTime;
    velocity.y += accelerationY * deltaTime;
    velocity.z += accelerationZ * deltaTime;

    // Apply drag 
    velocity.x *= drag;
    velocity.y *= drag;
    velocity.z *= drag;

    // Update position
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
    position.z += velocity.z * deltaTime;

    // Reset forces for next frame
    addForce.x = addForce.y = addForce.z = 0.0f;
}
void Physics::SetMass(float m)
{
    mass = m;
}
void Physics::SetDrag(float d)
{
    drag = d;
}
//following is to be removed:
void Physics::SetVelocity(float x, float y, float z)
{
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}
void Physics::SetVelocity(Vector3 newVelocity)
{
    velocity.x = newVelocity.x;
    velocity.y = newVelocity.y;
    velocity.z = newVelocity.z;
}
void Physics::GetVelocity(float& x, float& y, float& z)
{
    x = velocity.x;
    y = velocity.y;
    z = velocity.z;
}
void Physics::GetVelocity(Vector3& currentVelocity)
{
    currentVelocity.x = velocity.x;
    currentVelocity.y = velocity.y;
    currentVelocity.z = velocity.z;
}
//These are chill to keep:
void Physics::UseGravity(bool toggle)
{
    booleanGravity = toggle;
}
bool Physics::ToggleGravity()
{
    return booleanGravity;
}
