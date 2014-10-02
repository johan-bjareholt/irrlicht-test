#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <irrlicht.h>

using namespace irr;
using namespace core;

class Timer {
private:
	ITimer* irrtimer;
	u32 now;
	u32 then;
	long framec;
public:
	Timer();
	void update();
	int getFPS();
	f32 frameDeltaTime();
};

extern Timer* timer;


#endif