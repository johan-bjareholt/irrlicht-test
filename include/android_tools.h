// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef ANDROID_TOOLS_H_INCLUDED
#define ANDROID_TOOLS_H_INCLUDED

#include <irrlicht.h>
#include <android_native_app_glue.h>

namespace irr 
{
namespace android
{

struct SDisplayMetrics
{
	irr::s32 widthPixels;
	irr::s32 heightPixels;
	irr::f32 density;
	irr::s32 densityDpi;
	irr::f32 scaledDensity;
	irr::f32 xdpi;
	irr::f32 ydpi; 
};

//! Access SDisplayMetrics
extern bool getDisplayMetrics(android_app* app, SDisplayMetrics & metrics);

extern void setSoftInputVisibility(android_app* app, bool visible);
}
}

#endif
