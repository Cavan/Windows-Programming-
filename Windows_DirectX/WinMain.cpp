// INCLUDES /////////////////////////////////////////////////////////////////////////////

// windows includes
#include <windows.h>

// exceptions
#include <exception>
#include <stdexcept>

// bell0ybtes util
#include "expected.h"							// error handling with "expected"
#include "serviceLocator.h"					// enables global access to services

// FUNCTIONS ////////////////////////////////////////////////////////////////////////////

// services
void startLoggingService();

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// WinMain //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// try to start the logging service; if this fails, abort the application!
	try { startLoggingService(); }
	catch (std::runtime_error)
	{
		// show error message on a message box
		MessageBox(NULL, (LPCSTR)"Unable to start logging service!", (LPCSTR)"Critical Error!", MB_ICONEXCLAMATION | MB_OK);

		// humbly return with error code
		return -1;
	}

	// run the game

	// gracefully return
	getchar();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Services /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void startLoggingService()
{
	// create file logger
	std::shared_ptr<util::Logger<util::FileLogPolicy> > engineLogger(new util::Logger<util::FileLogPolicy>(L"bell0engine.log"));

	// set name of current thread
	engineLogger->setThreadName("mainThread");

	// register the logging service
	util::ServiceLocator::provideFileLoggingService(engineLogger);

#ifndef NDEBUG
	// print starting message
	util::ServiceLocator::getFileLogger()->print<util::SeverityType::info>("The file logger was created successfully.");
#endif
}


