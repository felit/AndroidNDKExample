#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_livedrof_ndkexample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++ Example";
    return env->NewStringUTF(hello.c_str());
}