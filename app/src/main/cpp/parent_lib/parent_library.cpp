#include "parent_library.h"
#include <dlfcn.h>
#include <iostream>
#include <jni.h>
#include <android/asset_manager.h>
#include <fstream>
#include <zlib.h>

char* ParentLibrary::loadChildLibrary(const std::string& libPath) {
    handle = dlopen(libPath.c_str(), RTLD_LAZY);  // Dynamically load the child library
    if (!handle) {
        std::cerr << "Failed to load child library: " << dlerror() << std::endl;
        return "Failed TO Load Child Library";
    }
    dlerror();  // Clear any existing error

    // Load the function from the child library
    // Get the symbol (function pointer) from the child library
    typedef const char* (*GetStringFunction)();
    GetStringFunction getStringFromChildLib = (GetStringFunction)dlsym(handle, "getStringFromChildLib");
    const char* error = dlerror();
    if (error != NULL) {
        std::cerr << "Failed to find symbol: " << error << std::endl;
        dlclose(handle);
        return "Failed to find symbol in child library";
    }

    // Call the function in the child library
    const char* result = getStringFromChildLib();

    // Close the child library when done
    dlclose(handle);

    // Return the result back to Java/Kotlin as a jstring
    return const_cast<char *>(result);
}


std::basic_string<char> ParentLibrary::executeChildFunction() {
    if (childFunction) {
      childFunction();  // Call the loaded function
    } else {
        std::cerr << "Child function not loaded." << std::endl;
        std::string errorx = "Hello from C++";
        return errorx;
    }
}

//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_example_nativebridgeproject_NativeInterface_loadChildLibrary(JNIEnv *env, jobject thiz,
//                                                                      jstring lib_path) {
//    const char *path = env->GetStringUTFChars(lib_path, nullptr);
//    ParentLibrary parentLib;
//    char* success = parentLib.loadChildLibrary(path);
//    env->ReleaseStringUTFChars(lib_path, path);
//    return env->NewStringUTF(success);
//
//}
//extern "C"
//JNIEXPORT jstring  JNICALL
//Java_com_example_nativebridgeproject_NativeInterface_executeChildFunction(JNIEnv *env,
//                                                                          jobject thiz) {
//
//    ParentLibrary parentLib= ParentLibrary();
//
//    return env->NewStringUTF(parentLib.executeChildFunction().c_str());
//
//
//}
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_example_nativebridgeproject_NativeInterface_loadAndCallChildLibrary(JNIEnv *env,
//                                                                             jobject thiz, jstring lib_path) {
//    const char *path = env->GetStringUTFChars(lib_path, nullptr);
//    const char* childLibPath = path;
//
//    // Load the child library
//    void* handle = dlopen(childLibPath, RTLD_NOW);
//    if (!handle) {
//        const char* error = dlerror();
//        std::cerr << "Failed to load child library: " << error << std::endl;
//        return env->NewStringUTF("Failed to load child library");
//    }
//
//    // Reset dlerror
//    dlerror();
//
//    // Get the symbol (function pointer) from the child library
//    typedef const char* (*GetStringFunction)();
//    GetStringFunction getStringFromChildLib = (GetStringFunction)dlsym(handle, "getStringFromChildLib");
//    const char* error = dlerror();
//    if (error != NULL) {
//        std::cerr << "Failed to find symbol: " << error << std::endl;
//        dlclose(handle);
//        return env->NewStringUTF("Failed to find symbol in child library");
//    }
//
//    // Call the function in the child library
//    const char* result = getStringFromChildLib();
//
//    // Close the child library when done
//    dlclose(handle);
//
//    // Return the result back to Java/Kotlin as a jstring
//    return env->NewStringUTF(result);
//}

//
//void extractZipFromAssets(AAssetManager* assetManager, const char* assetName, const char* destPath) {
//
//
//    AAsset* asset =    AAssetManager_open(assetManager,assetName,AASSET_MODE_STREAMING);
//    if (!asset) {
//        std::cerr << "Failed to open asset: " << assetName << std::endl;
//        return;
//    }
//
//    // Extract to the destination path (could be app's internal storage)
//    std::ofstream destFile(destPath, std::ios::binary);
//    char buffer[1024];
//    int bytesRead;
//
//    while ((bytesRead = AAsset_read(asset, buffer, sizeof(buffer))) > 0) {
//        destFile.write(buffer, bytesRead);
//    }
//
//    destFile.close();
//    AAsset_close(asset);
//
//    std::cout << "Extraction complete to " << destPath << std::endl;
//}

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

//void downloadZipFromServer(const char* url, const char* outputPath) {
//    CURL* curl;
//    FILE* fp;
//    CURLcode res;
//
//    curl = curl_easy_init();
//    if (curl) {
//        fp = fopen(outputPath, "wb");
//        curl_easy_setopt(curl, CURLOPT_URL, url);
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
//        res = curl_easy_perform(curl);
//        curl_easy_cleanup(curl);
//        fclose(fp);
//    }
//}