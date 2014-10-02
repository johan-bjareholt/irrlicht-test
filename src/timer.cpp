#include <irrlicht.h>

#include "main.h"
#include "timer.h"

using namespace irr;
using namespace core;


Timer::Timer() {
	framec = 0;
	update();
}
void Timer::update(){
	this->then = now;
	this->now = device->getTimer()->getTime();
	framec++;
}
int Timer::getFPS(){
	return driver->getFPS();
}
f32 Timer::frameDeltaTime() {
	return (f32)(this->now - this->then) / 1000.f;
}