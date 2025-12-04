#include "RenderObjects.h"
#include "Input.h"
#include "libs.h"
#include "Camera2.h"
#include "Text.h"
#include "Engine.h"
#include "AudioManager.h"
#include "Collider.h"
#include "ImageLoader.h"

GLuint _textureId;

camera2 cam2;
float lastTime = 0.0f;
bool onGround = false;

// Game objects
RenderObjects player;
RenderObjects ground;
RenderObjects obstacle1;
RenderObjects obstacle2;
RenderObjects movingPlatform;
Vector3 playerPos (0.0f, 50.0f, 0.0f);
void InitiateRender()
{
        /*glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);*/

		_textureId = InitializeTexture("vtr4.bmp");
}
void Initialize()
{
    // Setup Player with physics
    player.TransformObjectPosition(playerPos);
    player.Apply_Color(0, 255, 0);  // Green
    player.SetMass(1.0f);
    player.SetUseGravity(true);
    player.SetDrag(0.98f);
    player.SetCollider(Vector3(0.0f, 10.0f, 0.0f), Vector3(2.0f, 2.0f, 2.0f));

    // Setup Ground (static)
    ground.TransformObjectPosition(0.0f, -1.0f, 0.0f);
    ground.Apply_Color(100, 100, 100);  // Gray
    ground.SetUseGravity(false);
    ground.SetCollider(Vector3(0.0f, -1.0f, 0.0f), Vector3(20.0f, 1.0f, 20.0f));

    // Setup Obstacle 1
    obstacle1.TransformObjectPosition(5.0f, 1.0f, 0.0f);
    obstacle1.Apply_Color(255, 0, 0);  // Red
    obstacle1.SetUseGravity(false);
    obstacle1.SetCollider(Vector3(5.0f, 1.0f, 0.0f), Vector3(2.0f, 2.0f, 2.0f));

    // Setup Obstacle 2
    obstacle2.TransformObjectPosition(-5.0f, 2.0f, 0.0f);
    obstacle2.Apply_Color(255, 255, 0);  // Yellow
    obstacle2.SetUseGravity(false);
    obstacle2.SetCollider(Vector3(-5.0f, 2.0f, 0.0f), Vector3(2.0f, 2.0f, 2.0f));

    // Setup Moving Platform
    movingPlatform.TransformObjectPosition(0.0f, 5.0f, -5.0f);
    movingPlatform.Apply_Color(0, 0, 255);  // Blue
    movingPlatform.SetUseGravity(false);
    movingPlatform.SetCollider(Vector3(0.0f, 5.0f, -5.0f), Vector3(4.0f, 0.5f, 2.0f));
}

void UpdateColliders()
{
    // Update all collider positions to match object positions
    Vector3 pos;

    player.GetCurrentPosition(pos);
    player.SetCollider(pos, Vector3(2.0f, 2.0f, 2.0f));

    obstacle1.GetCurrentPosition(pos);
    obstacle1.SetCollider(pos, Vector3(2.0f, 2.0f, 2.0f));

    obstacle2.GetCurrentPosition(pos);
    obstacle2.SetCollider(pos, Vector3(2.0f, 2.0f, 2.0f));

    movingPlatform.GetCurrentPosition(pos);
    movingPlatform.SetCollider(pos, Vector3(4.0f, 0.5f, 2.0f));
}

void HandleCollisions()
{
    //Vector3 playerPos;
    player.GetCurrentPosition(playerPos);

    // Player vs Ground collision
    if (player.CheckCollision(ground))
    {
        player.TransformObjectPosition(playerPos.x, 0.0f, playerPos.z);
        player.SetVelocity(0, 0, 0);
        onGround = true;
    }
    else
        onGround = false;

    // Player vs Obstacle1 collision
    if (player.CheckCollision(obstacle1))
    {
        player.Apply_Color(255, 0, 255);  // Magenta on collision

        // Push player back
        Vector3 obs1Pos;
        obstacle1.GetCurrentPosition(obs1Pos);

        if (playerPos.x < obs1Pos.x)
            player.TransformObjectPosition(playerPos.x - 0.05f, playerPos.y, playerPos.z);
        else
            player.TransformObjectPosition(playerPos.x + 0.05f, playerPos.y, playerPos.z);
    }

    // Player vs Obstacle2 collision
    if (player.CheckCollision(obstacle2))
    {
        player.Apply_Color(255, 128, 0);  // Orange on collision

        Vector3 obs2Pos;
        obstacle2.GetCurrentPosition(obs2Pos);

        if (playerPos.x < obs2Pos.x)
            player.TransformObjectPosition(playerPos.x - 0.05f, playerPos.y, playerPos.z);
        else
            player.TransformObjectPosition(playerPos.x + 0.05f, playerPos.y, playerPos.z);
    }

    // Player vs Moving Platform collision
    if (player.CheckCollision(movingPlatform))
    {
        Vector3 platformPos;
        movingPlatform.GetCurrentPosition(platformPos);

        // Land on top of platform
        if (playerPos.y > platformPos.y)
        {
            player.TransformObjectPosition(playerPos.x, platformPos.y + 0.75f, playerPos.z);
            player.SetVelocity(0, 0, 0);
            onGround = true;
        }
    }

    // Reset player color if no collisions
    if (!player.CheckCollision(obstacle1) && !player.CheckCollision(obstacle2))
    {
        player.Apply_Color(0, 255, 0);  // Green
    }
}

void UpdateMovingPlatform(float deltaTime)
{
    static float platformDirection = 1.0f;
    Vector3 platformPos;
    movingPlatform.GetCurrentPosition(platformPos);

    // Move platform back and forth
    platformPos.x += platformDirection * 2.0f * deltaTime;

    // Reverse direction at boundaries
    if (platformPos.x > 8.0f || platformPos.x < -8.0f)
        platformDirection *= -1.0f;

    movingPlatform.TransformObjectPosition(platformPos);
}

void HandleInput()
{
    //Vector3 playerPos;
    Vector3 north(0.0f,0.0f,-0.2f), 
            west(-0.2f, 0.0f, 0.0f), 
            south(0.0f, 0.0f,0.2f ),
            east(0.2f, 0.0f, 0.0f),
            jump(0.0f, 10.0f, 0.0f);
    player.GetCurrentPosition(playerPos);
    // Jump
    // Movement
    if (Input::GetKey(' ')&& onGround)
        player.TransformObjectPosition(playerPos+jump);
    if (Input::GetKey('a'))
    {
        player.TransformObjectPosition(playerPos+=west);
    }
    if (Input::GetKey('d'))
    {
        player.TransformObjectPosition(playerPos+=east);
    }
    if (Input::GetKey('w'))
    {
        player.TransformObjectPosition(playerPos+=north);
    }
    if (Input::GetKey('s'))
    {
        player.TransformObjectPosition(playerPos+=south);
    }

    // Reset
    if (Input::GetKey('r'))
    {
        player.TransformObjectPosition(0.0f, 10.0f, 0.0f);
        player.SetVelocity(0, 0, 0);
    }

    // Toggle wireframe
    if (Input::GetKey('x'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (Input::GetKey('z'))
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

void Update()
{
    // Calculate delta time
    float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float deltaTime = currentTime - lastTime;
    if (deltaTime > 0.1f) deltaTime = 0.1f;  // Cap delta time
    lastTime = currentTime;

    // Handle input
    HandleInput();

    // Update physics
    player.UpdatePhysics(deltaTime);

    // Update moving platform
    UpdateMovingPlatform(deltaTime);

    // Update all colliders
    UpdateColliders();

    // Handle collisions
    HandleCollisions();

    // Camera follows player
    //Vector3 playerPos;
    player.GetCurrentPosition(playerPos);
    cam2.targetX = playerPos.x;
    cam2.targetY = playerPos.y + 5.0f;
    cam2.targetZ = playerPos.z + 15.0f;

    glutMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });
    glutPassiveMotionFunc([](int x, int y) { cam2.HandleMouseMotion(x, y); });
    cam2.ApplyCamera();

    // Draw all objects
    player.Create3DCube(2, 2, 2);
    ground.Create3DCube(20, 1, 20);
    obstacle1.Create3DCube(2, 2, 2);
    obstacle2.Create3DCube(2, 2, 2);
    movingPlatform.Create3DCube(4, 0.5, 2);

    // Display info text
    Text infoText;
    infoText.ColorText(255, 255, 0);
    infoText.TranslateText(4.0f, 10.0f, 10.0f);

    Vector3 vel;
    player.GetVelocity(vel);

    if (onGround)
        infoText.RenderText("On Ground - Press SPACE to jump");
    else
        infoText.RenderText("In Air");

    // Display position
    Text posText;
    posText.ColorText(0, 255, 255);
    posText.TranslateText(-4.0f, 9.0f, 0.0f);
    char posBuffer[100];
    sprintf_s(posBuffer, "Position: (%.1f, %.1f, %.1f)", playerPos.x, playerPos.y, playerPos.z);
    posText.RenderText(posBuffer);
}

int main(int argc, char** argv)
{
    PlaySong(L"Majula.wav");
    PrepEngine(argc, argv);
}