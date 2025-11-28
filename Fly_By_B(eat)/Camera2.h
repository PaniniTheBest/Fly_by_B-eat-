#ifndef CAMERA2_H
#define CAMERA2_H

#include <glut.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class camera2 {
public:
    float yaw = 0.0f;          // Horizontal rotation (left/right)
    float pitch = 30.0f;       // Vertical rotation (up/down)
    float distance = 10.0f;    // How far camera is from target
    float height = 6.0f;      // Camera height offset
    float sensitivity = 0.2f;  // Mouse sensitivity

    float targetX = 0.0f;      // Target position (object to look at)
    float targetY = 0.0f;
    float targetZ = 0.0f;

private:
    int lastMouseX = 0, lastMouseY = 0;
    bool firstMouse = true;

public:
    camera2() = default;

    // Call this in your render/update loop before drawing objects
    void ApplyCamera() const {
        // Convert yaw/pitch to radians
        float yawRad = yaw * M_PI / 180.0f;
        float pitchRad = pitch * M_PI / 180.0f;

        // Compute camera position relative to target
        float camX = targetX + distance * cos(pitchRad) * sin(yawRad);
        float camY = targetY + distance * sin(pitchRad);
        float camZ = targetZ + distance * cos(pitchRad) * cos(yawRad);

        gluLookAt(  camX, camY, camZ,
                    targetX, targetY, targetZ,
                    0.0f, 1.0f, 0.0f);
    }


    // Mouse motion (for rotation)
    void HandleMouseMotion(int x, int y) {
        if (firstMouse) {
            lastMouseX = x;
            lastMouseY = y;
            firstMouse = false;
        }

        int deltaX = x - lastMouseX;
        int deltaY = y - lastMouseY;
        lastMouseX = x;
        lastMouseY = y;

        // Horizontal movement → yaw (turn left/right)
        yaw += deltaX * sensitivity;

        // Vertical movement → pitch (look up/down)
        pitch -= deltaY * sensitivity;

        // Clamp pitch so camera doesn’t flip upside down
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;

        // Keep yaw within 0–360 for convenience
        if (yaw > 360.0f) yaw -= 360.0f;
        if (yaw < 0.0f)   yaw += 360.0f;

        glutPostRedisplay();
    }

};

#endif // CAMERA_H
