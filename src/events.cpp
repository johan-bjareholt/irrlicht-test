#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#include "main.h"
#include "events.h"

bool EventReceiver::OnEvent(const SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		if (event.KeyInput.PressedDown)
		{
			switch(event.KeyInput.Key){
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