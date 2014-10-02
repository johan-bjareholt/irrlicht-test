LOCAL_PATH := $(call my-dir)/..
PROJECT_PATH := $(LOCAL_PATH)/..
SOURCE_PATH	 := $(PROJECT_PATH)/src
ANDROID_PROJECT_PATH := $(LOCAL_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE := Irrlicht
LOCAL_SRC_FILES := $(PROJECT_PATH)/libs/irrlicht-gles/libIrrlicht.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

cmd-strip	:= 
CMD_STRIP	:=
CMD-STRIP	:=

LOCAL_MODULE := HelloWorldMobile

LOCAL_CFLAGS := -D_IRR_ANDROID_PLATFORM_ -pipe -fno-exceptions -fno-rtti -fstrict-aliasing

ifndef NDEBUG
LOCAL_CFLAGS += -g -D_DEBUG
else
LOCAL_CFLAGS += -fexpensive-optimizations -O3
endif

ifeq ($(TARGET_ARCH_ABI),x86)
LOCAL_CFLAGS += -fno-stack-protector
endif

LOCAL_C_INCLUDES := $(PROJECT_PATH)/libs/irrlicht-gles/include \
					$(PROJECT_PATH)/include

LOCAL_SRC_FILES :=	$(SOURCE_PATH)/main.cpp \
					$(SOURCE_PATH)/android_tools.cpp \
					$(SOURCE_PATH)/events.cpp \
					$(SOURCE_PATH)/mesh.cpp \
					$(SOURCE_PATH)/timer.cpp \
					$(SOURCE_PATH)/scene.cpp \
					$(SOURCE_PATH)/scenes/mainmenu.cpp

LOCAL_LDLIBS := -lEGL -llog -lGLESv1_CM -lGLESv2 -lz -landroid

LOCAL_STATIC_LIBRARIES := Irrlicht android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)

# copy Irrlicht data to assets

$(shell cp -r $(PROJECT_PATH)/assets/ $(ANDROID_PROJECT_PATH))
