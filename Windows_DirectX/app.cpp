/* FILE: app.cpp
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


#include "app.h"
#include "serviceLocator.h"


//Class implementation
namespace core
{

	//Constructors
	DirectXApp::DirectXApp(HINSTANCE hInstance) : appInstance(hInstance), appWindow(NULL) {}
	DirectXApp::~DirectXApp()
	{
		shutdown();
	}

	// Create core app components
	util::Expected<void> DirectXApp::init()
	{
		// create the application window
		try { appWindow = new Window(this); }
		catch (std::runtime_error)
		{
			return std::runtime_error("DirectXApp was unable to create the main window!");
		}
		// log and return success
		util::ServiceLocator::getFileLogger()->print<util::SeverityType::info>("The DirectX application initialization was successful.");
		return {};
	}

	void DirectXApp::shutdown(util::Expected<void>* expected)
	{
		if (appWindow)
		{
			delete appWindow;
		}
		if (appInstance)
		{
			appInstance = NULL;
		}

		util::ServiceLocator::getFileLogger()->print<util::SeverityType::info>("The DirectX application was shutdown successfully.");

	}

	// Main Event Loop
	util::Expected<int> DirectXApp::run()
	{
		bool continueRunning = true;
		MSG msg = { 0 };

		// enter main event loop
		while (continueRunning)
		{
			// peek for messages
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
				{
					continueRunning = false;
				}
			}
			// run the game logic
		}
		return (int)msg.wParam;
	}

}