#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "main.h"
#include "events.h"

#ifdef _IRR_ANDROID_PLATFORM_
#include <android/log.h>
#endif

bool EventReceiver::OnEvent(const SEvent& event)
{
	switch(event.EventType){
		//
		case irr::EET_KEY_INPUT_EVENT:
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			if (event.KeyInput.PressedDown)
			{
				switch(event.KeyInput.Key)
				{
					case KEY_SPACE:{
						break;
					}
					case KEY_ESCAPE:{
						device->closeDevice();
						break;
					}
				}
				return true;
			}
			break;
		//
		case irr::EET_LOG_TEXT_EVENT:
			char* levelstr;
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
			#ifdef _IRR_ANDROID_PLATFORM_
			__android_log_print(ANDROID_LOG_VERBOSE, "Irrlicht", "%s\n", event.LogEvent.Text);
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