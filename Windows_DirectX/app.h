#ifndef APP
#define APP

/* FILE: app.h
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

//Windows 
#include <Windows.h>

// display window
#include "window.h"

// Utilities
#include "Expected.h"

//Class definition
namespace core
{
	class DirectXApp
	{
	protected:
		// application window
		HINSTANCE appInstance;						// handle to an instance of the application
		Window* appWindow;							// the application window (i.e. game window)

		// constructor and destructor 
		DirectXApp(HINSTANCE hInstance);
		~DirectXApp();

		util::Expected<int> run();					// enters the main event loop

		// virtual methods, must be overridden 
		virtual util::Expected<void> init();							// initializes the DirectX application
		virtual void shutdown(util::Expected<void>* expected = NULL);	// clean up and shutdown the DirectX application
	public:
		friend class Window;

	};
}




#endif