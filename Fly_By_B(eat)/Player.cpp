#include "Player.h"
#include <glut.h>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

float posX = 0.0f, posY = 0.0f, posZ = 0.0f;
float velX = 0.0f, velY = 0.0f, velZ = 0.0f;
float accX = 0.1f, accY = 0.0f, accZ = 0.0f;

int prevTime = 0;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (currentTime - prevTime) / 1000.0f;
	prevTime = currentTime;

	velX += accX * deltaTime;


	velX += accX * deltaTime;
	velY += accY * deltaTime;
	velZ += accZ * deltaTime;

	posX += velX * deltaTime;
	posY += velY * deltaTime;
	posZ += velZ * deltaTime;

	if (posY <= 0.0f)
	{
		accY = 0.0f;
		velY = 0.0f;
	}
	else
	{
		accY = -2.0f;
	}

	glTranslatef(posX, posY, posZ);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
			if (posY == 0.0f)
				velX = 5.0f;
			break;
		case 'a':
		case 'A':
			if (velX > 0.0f)
				velX -= 0.5f;
			else if (velX < 0.0f)
				velX += 0.5f;
	}
}
