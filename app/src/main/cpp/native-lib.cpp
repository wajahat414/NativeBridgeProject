#include <jni.h>
#include <string>
#include <iostream>
#include <dlfcn.h>


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativebridgeproject_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}