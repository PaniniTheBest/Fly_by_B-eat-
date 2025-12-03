#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <glut.h>
#include <string>
#include "Color.h"
#include "vector3.h"
using namespace std;

class Text {
	private:
		Vector3 Translate;
		Color TextRGB;
	public:
		Text();
		void RenderString(void* font, float x, float y, string message);
		void RenderText(string message);
		void ColorText(float r, float g, float b);
		void ColorText(Color newRGB);
		void TranslateText(float x, float y, float z);
		void TranslateText(Vector3 newTranslate);
		void RenderVariableAsText(float variable);
		void RenderVariableAsText2(float variable, float r, float g, float b); //If you wanna declare
};


#endif

