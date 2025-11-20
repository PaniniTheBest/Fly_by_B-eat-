#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>

using namespace std;

#pragma comment(lib, "winmm.lib")

void playSongz(string songName)
{
	cout << "Playing " << songName << " ...";
	//PlaySound(songName.c_str(), NULL, SND_FILENAME | SND_SYNC);
	cout << "\n\n" << songName << " has finished!!!";
}

int main()
{
	/*playSongz("song1.wav");*/
	cout << "Playing " << "Otsukare Summer" << " ...";
	PlaySound(TEXT("song1"), NULL, SND_FILENAME | SND_SYNC);
	cout << "\n\n" << "Otsukare Summer" << " has finished!!!";
}