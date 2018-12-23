


#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	LPCSTR greeting = "Hello World!";
	LPCSTR description = "Windows Progrmming API";

	MessageBox(NULL, greeting, description, MB_ICONHAND | MB_OK);


	return 0;
}

