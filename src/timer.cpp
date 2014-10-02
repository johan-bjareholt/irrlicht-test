#include <irrlicht.h>

#include "main.h"
#include "timer.h"

using namespace irr;
using namespace core;

// Global timer variable
Timer* timer;

Timer::Timer() {
	irrtimer = device->getTimer();
	framec = 0;
	update();
}
void Timer::update(){
	then = now;
	irrtimer->tick();
	now = irrtimer->getTime();
	framec++;
}
int Timer::getFPS(){
	return driver->getFPS();
}
f32 Timer::frameDeltaTime() {
	return (f32)(now - then) / 1000.f;
}