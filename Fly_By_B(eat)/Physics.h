#ifndef PHYSICS_H
#define PHYSICS_H
#include "vector3.h"
#include <cmath>
#pragma once
class Physics
{
private:
    Vector3 velocity;
    Vector3 addForce;
    float mass;
    float drag;
    bool booleanGravity;
public:
    Physics();
    Physics(float m, float d, bool toggleGravity);
    void AddForce(float& x, float& y, float& z);
    void AddForce(Vector3& addForce);
    void UpdatePhysics(float deltaTime, float& positionX, float& positionY, float& positionZ);
    void UpdatePhysics(float deltaTime, Vector3& position);
    void SetMass(float m);
    void SetDrag(float d);
    //following is to be removed:
    void SetVelocity(float x, float y, float z); 
    void SetVelocity(Vector3 newVelocity);
    void GetVelocity(float& x, float& y, float& z);
    void GetVelocity(Vector3& newVelocity);
    //These are chill to keep:
    void UseGravity(bool toggle);
    bool ToggleGravity();
};
#endif
