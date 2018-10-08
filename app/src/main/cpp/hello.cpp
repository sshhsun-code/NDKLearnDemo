//
// Created by CM on 2018/10/8.
//

#include "hello.h"

#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_gamemaster_cmcm_com_ndklearndemo_HelloNdk_sayHello(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "This is my Hello";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_gamemaster_cmcm_com_ndklearndemo_HelloNdk_sayok(JNIEnv *env, jclass type) {

    std::string ok = "This is my Ok";

    return env->NewStringUTF(ok.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_gamemaster_cmcm_com_ndklearndemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT void JNICALL
Java_gamemaster_cmcm_com_ndklearndemo_HelloNdk_printLog(JNIEnv *env, jclass type, jstring log_) {
    const char *log = env->GetStringUTFChars(log_, 0);

    // TODO
    const char *tag = "NativeHelper";
    const char* txt = env->GetStringUTFChars(log_, JNI_FALSE);
    //打印log日志
    __android_log_write(ANDROID_LOG_DEBUG, tag, txt);

    env->ReleaseStringUTFChars(log_, log);
}
