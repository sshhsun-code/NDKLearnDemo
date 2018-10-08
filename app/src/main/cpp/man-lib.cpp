//
// Created by CM on 2018/10/8.
//

#include "man-lib.h"
#include <jni.h>
#include <string>

//1.访问属性name
//修改属性key的字符串
extern "C"
JNIEXPORT jstring JNICALL
Java_test_c_use_java_method_Man_accessField(JNIEnv *env, jobject instance) {

    //得到class
    jclass jclazz = env -> GetObjectClass(instance);

    //jfieldID
    //签名：类型的简称
    //属性，方法
    jfieldID fid = env -> GetFieldID(jclazz,"name","Ljava/lang/String;");

    //获取key属性的值
    //注意：key为基本数据类型，规则如下
    //(*env)->GetIntField(); (*env)->Get<Type>Field();
    jstring jstr = (jstring) env->GetObjectField(instance, fid);

    //jstring转为 C/C++字符串
    char * c_str = (char *) env->GetStringUTFChars(jstr, NULL);

    strcat(c_str,"android");

    //拼接完成之后，从C字符串转为jstring
    jstring jstr_new = env->NewStringUTF(c_str);

    //修改key的属性
    //注意规则：Set<Type>Field
    env-> SetObjectField(instance, fid, jstr_new);

    return jstr_new;
}


//2.访问类属性age
//修改属性age的值
extern "C"
JNIEXPORT jstring JNICALL
Java_test_c_use_java_method_Man_stringFromJNI(JNIEnv *env, jobject instance) {

    //获取class
    jclass jclazz = env->GetObjectClass(instance);
    //获取jfieldid
    jfieldID jid = env->GetStaticFieldID(jclazz,"age","I");
    jint jage = env->GetStaticIntField(jclazz,jid);
    jage++;

    env->SetStaticIntField(jclazz, jid, jage);


    return env->NewStringUTF("stringFromJNI");
}