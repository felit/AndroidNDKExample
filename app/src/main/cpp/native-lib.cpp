#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_livedrof_ndkexample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++ Example";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_livedrof_ndkexample_MainActivity_string2FromJNI(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("hello.c_str()");
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_livedrof_ndkexample_MainActivity_dtoFromJNI(JNIEnv *env, jobject thiz, jbyte byte_val,
                                                     jchar char_val, jint int_val, jlong l_val,
                                                     jboolean b_val, jfloat f_val, jdouble d_val,
                                                     jobject date, jobject dto) {
    std::string returnVal = "hello example from C++";
//    returnVal.append( ",thiz:");
//    returnVal.append(thiz);
//    returnVal.append(",jbyte:");
//    returnVal.append(byte_val);
//    returnVal.append(",jchar:");
//    returnVal.append(char_val);
//    returnVal.append(",jint:");
//    returnVal.append(int_val);
//    returnVal.append(",jlong:");
//    returnVal.append(l_val);
//    returnVal.append(",jboolean:");
//    returnVal.append(b_val);
//    returnVal.append(",jfloat:");
//    returnVal.append(f_val);
//    returnVal.append(",jdouble:");
//    returnVal.append(d_val);
//    returnVal.append(",jobject date:");
//    returnVal.append(date);
//    returnVal.append(",jobject SystemInfoDTO:");
//    returnVal.append(dto);
    return env->NewStringUTF(returnVal.c_str());
}