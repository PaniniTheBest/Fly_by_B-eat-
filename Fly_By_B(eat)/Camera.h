#ifndef CAMERA_H
#define CAMERA_H

#include <glut.h>

class camera {
private:
    int currentView;
    float distance;
public:
    static const int TOP_VIEW = 0;
    static const int BOTTOM_VIEW = 1;
    static const int PERSPECTIVE_VIEW = 2;

    camera()
    {
        currentView = 0; // you can change the number to change the perspective
        distance = 90.0f;
    }

    void SetView(int view)
    {
        currentView = view;
    }

    void SetDistance(float dist)
    {
        distance = dist;
    }

    void ApplyCamera()
    {
        switch (currentView)
        {
        case 0:
            gluLookAt(0.0f, distance, 0.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, -1.0f);
            break;

        case 1:
            gluLookAt(0.0f, -distance, 0.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f);
            break;
        case 2:
        default:
            gluLookAt(0.0f, 0.0f, distance,
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f);
            break;
        }
    }
};

#endif
