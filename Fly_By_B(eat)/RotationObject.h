#ifndef ROTATIONOBJECT_H
#define ROTATIONOBJECT_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <glut.h>
#include <cmath>

class Rotation {
public:
    // Make these static so they can be used as GLUT callbacks
    static float camYaw;
    static int lastMouseX;
    static float moveSpeed;
    static float mouseSensitivity;
    static bool firstMouse;

    static void mouseMotion(int x, int y)
    {
        if (firstMouse)
        {
            lastMouseX = x;
            firstMouse = false;
        }
        int deltaX = x - lastMouseX;
        lastMouseX = x;

        // Horizontal rotation (yaw) only
        camYaw -= deltaX * mouseSensitivity;

        // Keep yaw in 0-360 range
        if (camYaw > 360.0f)
            camYaw -= 360.0f;
        if (camYaw < 0.0f)
            camYaw += 360.0f;
    }

    // Passive mouse motion callback
    static void mousePassiveMotion(int x, int y)
    {
        mouseMotion(x, y);
    }
};

#endif