#pragma once

/****************************************************************************************
* Author:	Gilles Bellot
* Date:		08/03/2016 - Dortmund - Germany
*
* Desc:		main class to bring together all the core components of a game
*
****************************************************************************************/

// INCLUDES /////////////////////////////////////////////////////////////////////////////

// windows
#include <Windows.h>

// bell0bytes core
#include "window.h"

// bell0bytes util
#include "expected.h"


// CLASSES //////////////////////////////////////////////////////////////////////////////
namespace core
{
	class DirectXApp
	{
	protected:
		// application window
		HINSTANCE appInstance;					// handle to an instance of the application
		Window* appWindow;						// the application window (i.e. game window)

		// logger state
		bool activeLogger;						// true if the logging service was successfully registered

		// folder paths
		std::wstring pathToMyDocuments;			// path to the My Documents folder
		std::wstring pathToLogFiles;			// path to the folder containing log files
		std::wstring pathToConfigurationFiles;	// path to the folder containing the configuration files
		bool validConfigurationFile;			// true if there was a valid configuration file at startup

		// game state
		bool isPaused;							// true if the game is paused 

		// constructor and destructor
		DirectXApp(HINSTANCE hInstance);
		~DirectXApp();

		// game loop
		util::Expected<int> run();				// enters the main event loop
		
		// virtual methods, must be overridden
		virtual util::Expected<void> init();								// initializes the DirectX application
		virtual void shutdown(util::Expected<void>* expected = NULL);		// clean up and shutdown the DirectX application

		// resize functions
		void onResize();						// resize game graphics

		// helper functions
		bool getPathToMyDocuments();			// stores the path to the My Documents folder in the appropriate member variable
		void createLoggingService();			// creates the file logger and registers it as a service
		bool checkConfigurationFile();			// checks for valid configuration file

	public:
		friend class Window;
	};
}