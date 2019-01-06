#ifndef WINDOW
#define WINDOW


/* FILE: window.h
 * PROJECT: DirectX Programming
 * PROGRAMMER: Cavan Biggs
 * FIRST VERSION: January 5th 2019
 * DESCRIPTION: Following a tutorial found at - https://bell0bytes.eu/a-real-world-windows-application/
 *			    To better understand windows programming, and other low level operations.
 *
 *
 *
 *
 *
*/

// INCLUDES

// windows
#include <Windows.h>

// Utility class
#include "Expected.h"

namespace core
{
	//Class definition
	class DirectXApp; 

	//Classes
	class Window
	{
	private:
		HWND mainWindow;				// handle to the main window 
		DirectXApp* dxApp;				// the core application class

		util::Expected<void> init();	// initializes the window

	public:
		// constructor and destructor
		Window(DirectXApp* dxApp);
		~Window();

		//getters 
		inline HWND getMainWindowHandle() { return mainWindow; };

		// the call back function
		virtual LRESULT CALLBACK msgProc(HWND hWnd, unsigned int msg, WPARAM wParam, LPARAM lParam);
		
		friend class DirectXApp;



	};
}







#endif