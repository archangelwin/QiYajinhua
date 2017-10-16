#ifndef EXTERNFUNC_H
#define EXTERNFUNC_H

#include "cocos2d.h"


#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif

void WxLogin();
#endif
					  