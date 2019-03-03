#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
int main()
{
	for( int a = 0;a<10;a++)
	{
		PlaySound((LPCWSTR)"tone.wav", 0, SND_LOOP|SND_ASYNC|[B]SND_FILENAME[/B]);
		Sleep(1000);
	}
	return 0;
}