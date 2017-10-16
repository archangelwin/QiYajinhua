#include "ExternFunc.h"
USING_NS_CC;
void WxLogin()
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo minfo;
	const char * jniClass = "org/cocos2dx/cpp/AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(minfo,
		"org/cocos2dx/cpp/AppActivity",
		"WxLogin", "()V");
	//if (!isHave)
	//	CCLog("jni->%s/callJni:�˺���������", jniClass);
	//else
	//	CCLog("jni->%s/callJni:�˺�������", jniClass);
	minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
#elif(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
#endif
}
