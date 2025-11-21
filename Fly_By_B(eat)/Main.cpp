#include "_3D_Shapes.h"
#include "Player.h"
#include "CollisionSystem.h"
float rotateAngle = 0.0f;



GameObject1 player;
GameObject1 wall;
Ray testRay;


void initGameObjects()
{
    player.position = { 0, 0, 0 };
    player.size = { 2, 2, 2 };
    player.radius = 1.0f;

    wall.position = { 5, 0, 0 };
    wall.size = { 3, 3, 3 };
    wall.radius = 1.5f;

    testRay.origin = { 0, 0, 0 };
    testRay.direction = { 1, 0, 0 }; 
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(  0.0f, 0.0f, 80.0f,
                0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f);

    glTranslatef(0.0f, 5.0f, 0.0f);
    glRotatef(rotateAngle, 3.0f, 4.0f, 2.0f);
    //==============================================
    //Render 3D objects here \/ \/ \/
    /*
    _3D_Shapes Cube_test;
    Cube_test.Move_Object(0.0f, -4.0f, 0);
    //Cube_test.Apply_Color(1.0f, 0.0f, 0.0f);
    Cube_test.Create_3D_Cube(5.0f,10.0f,20.0f);

    _3D_Shapes Sphere_test;
    Sphere_test.Move_Object(0.0f, -20.0f, 0);
    Sphere_test.Apply_Color(255, 67, 80);
    Sphere_test.Create_3D_Sphere(5.0f, 10.0f, 20.0f);

    _3D_Shapes Sphere_test2;
    Sphere_test2.Move_Object(20.0f, -20.0f, 0);
    Sphere_test2.Apply_Color(67, 67.0f, 80.0f);
    Sphere_test2.Create_3D_Sphere(5.0f, 10.0f, 20.0f);
    //==============================================
    rotateAngle += 1.0f;
     */

    ////=======Collision stuff========================NONE OF THIS WORKS YET====================
    //bool aabbHit = CoordinateOverlap(player, wall);
    //bool sphereHit = SphereCollision(player, wall);
    //bool rayHit = RaycastCollision(wall, testRay, 20.0f);

    //if (aabbHit)
    //    glColor3f(1, 0, 0); //TURN RED PLEASE
    //else
    //    glColor3f(0, 1, 0); //BE GREEN RAHHHHH

    //glPushMatrix();
    //glTranslatef(player.position.x, player.position.y, player.position.z);
    //glBegin(GL_QUADS);
    ////Copy of Nick's cube code========
    //_3D_Shapes Cube_test;
    //Cube_test.Move_Object(0.0f, -4.0f, 0);
    ////Cube_test.Apply_Color(1.0f, 0.0f, 0.0f);
    //Cube_test.Create_3D_Cube(5.0f, 5.0f, 5.0f);

    //glColor3f(0, 0, 1); // blue
    //glPushMatrix();
    //glTranslatef(wall.position.x, wall.position.y, wall.position.z);
    //glBegin(GL_QUADS);
    //Cube_test.Move_Object(0.0f, -14.0f, 0);
    ////Cube_test.Apply_Color(1.0f, 0.0f, 0.0f);
    //Cube_test.Create_3D_Cube(5.0f, 5.0f, 5.0f);
    //glEnd();
    //glPopMatrix();
    ////================================
    //glEnd();
    //glPopMatrix();
    //
    ////===============================================
    glutSwapBuffers();
}

void ChangeSize(int w, int h)
{
    if (h == 0)
        h = 1;

    float ratio = 1.0 * w / h;
    float ratio = 1.0 * w / h;

    //fix the matrixmode to projection 
    glMatrixMode(GL_PROJECTION);
    //Reset the value of matrices
    glLoadIdentity();
    //Set the viewport of the window
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    // Get Back to Model View
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    //init GLUT and create a window
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(320, 320);

    glutCreateWindow("=+= Fly by B(eat) =+=");

    initGameObjects();
    //register callbacks
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}