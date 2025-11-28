#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
#include "AudioManager.h"

using namespace std;
#pragma comment(lib, "winmm.lib")

void PlaySong(wstring string)
{
	PlaySound(string.c_str(), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}