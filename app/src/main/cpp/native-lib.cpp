#include <jni.h>
#include <string>
#include <iostream>
#include <dlfcn.h>


// JNI function implementation
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_nativebridgeproject_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return  env->NewStringUTF(hello.c_str());
}

//void perform_network_request() {
//    CURL *curl;
//    CURLcode res;
//
//    curl = curl_easy_init();
//    if(curl) {
//        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
//        res = curl_easy_perform(curl);
//
//        if(res != CURLE_OK)
//            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//
//        curl_easy_cleanup(curl);
//    }
//}


//extern "C" JNIEXPORT jstring JNICALL_Java_com_example_nativebridgeproject_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}
