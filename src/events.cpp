#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "main.h"
#include "scene.h"
#include "events.h"

#ifdef _IRR_ANDROID_PLATFORM_
#include <android/log.h>
#endif

bool EventReceiver::OnEvent(const SEvent& event)
{
	if (currentScene)
		currentScene->getEvent(event);
	switch(event.EventType){
		//
		case irr::EET_KEY_INPUT_EVENT:
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			break;
		//
		case irr::EET_LOG_TEXT_EVENT:
			const char* levelstr;
			switch (event.LogEvent.Level){
				case 0:
					levelstr = "Debug";
					break;
				case 1:
					levelstr = "Info";
					break;
				case 2:
					levelstr = "WARNING";
					break;
				case 3:
					levelstr = "ERROR";
					break;
			}
			#ifdef _IRR_ANDROID_PLATFORM_ // Output to catlog instead of stdout
			__android_log_print(ANDROID_LOG_INFO, "Irrlicht", "%s\n", event.LogEvent.Text);
			#else
			printf("%s: %s\n", levelstr, event.LogEvent.Text);
			#endif
			return true;
		default:
			return true;
	}
}
const bool EventReceiver::IsKeyDown(EKEY_CODE keyCode)
{
    return KeyIsDown[keyCode];
}

EventReceiver::EventReceiver()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

// EventReceiver
EventReceiver eventReceiver;