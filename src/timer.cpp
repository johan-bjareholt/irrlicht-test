#include <irrlicht.h>

#include "main.h"
#include "timer.h"

using namespace irr;
using namespace core;

// Global timer variable
Timer* timer;

Timer::Timer() {
	framec = 0;
	update();
}
void Timer::update(){
	then = now;
	now = device->getTimer()->getTime();
	framec++;
}
int Timer::getFPS(){
	return driver->getFPS();
}
f32 Timer::frameDeltaTime() {
	return (f32)(now - then) / 1000.f;
}