#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <irrlicht.h>

using namespace irr;
using namespace core;

class Timer {
private:
	u32 now, then;
	ITimer* irrtimer;
	long framec;
public:
	Timer();
	void update();
	int getFPS();
	f32 frameDeltaTime();
};

extern Timer* timer;


#endif