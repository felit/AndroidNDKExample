#include <jni.h>
#include <string>
#include "HelloCPP.h"
/**
 * 方法命名规范：
 * extern
 * "C"
 * JNIEXPORT
 * <返回值>
 * JNICALL
 * <方法命名>:Java_包名_类名_方法名
 * 参数：
 *    JNIEnv
 *    jobject
 *    JavaVM
 *    Java线程
 *
 *
 * System.loadLibrary()的加载类库; 加载已经适配的类库？
 * System.load 和 System.loadLibrary详解: https://blog.csdn.net/nico0423/article/details/9733633
 * 在Linux 平台上，遵循JN!规范的动态链接库 文件名必须以“lib” 开头
 * javah生成Java Native对应的.h的文件
 * 编写Makefile 文件如 下，JDK安装的位置请读者自行调整: libtestini.so:testini.o
 * Makefile:
 * libtestini.so:testini.o
 * gcc -rdynamic -shared -o libtestjni.so testjni.o
 * testini.o:testini.c TestJNI.h
        gcc -rdynamic -shared o- libtestjni.so testjni.o testini.o:testini.c TestJNI.h
        gcc -c  -testjni.c -I. -I/usr/java/jdk1.6.000/include -I /usr/java/jdk1.6.000/include/linux
动态链接库文件放置在LD_LIBRARY_PATH环境变量所指向的路径下
 从动态链接库中搜索JNI规定的类方法或者类？，并调用
 */
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
                                                     jchar char_val, jshort short_val,jint int_val, jlong l_val,
                                                     jboolean b_val, jfloat f_val, jdouble d_val,
                                                     jobject date, jobject dto,jstring hello) {
//    std::string returnVal = "hello example from C++";


/*
 *
 * 1、jboolean可以与bool互换使用？
 * 2、
 */
    bool  cc = b_val;
//    b_val = 1==1;
    std::string returnVal = "";
    char str[20];
    sprintf(str, "version: %d %s",env->GetVersion(), b_val?"是":"否");
    returnVal.append(str);
    //Java->C
    char byte=byte_val;
    char char_=char_val;
    short short_ = short_val;
    int in_ = int_val;
    long long long_ = l_val;
    float float_ = f_val;
    double double_ = d_val;
    // C->Java
    byte_val = 0x1;
    char_val = '2';
    short_val=111;
    int_val = 23;
    l_val = 22L;
    f_val = 21.0;
    d_val = 33435.4;
    //sprintf将其他类型转换成char*

    JavaVM *javaVm;
    env->GetJavaVM(&javaVm);
    jboolean btn = false;
    const char *str2;
    str2 = (*env).GetStringUTFChars(hello, &btn);

    char strs[300];
    sprintf(strs,"string from java arguments: %s", str2);
    returnVal.append(strs);
    livedrof::HelloCPP *h = new livedrof::HelloCPP();
    /**
     * typedef uint8_t  jboolean;
        typedef int8_t   jbyte;
        typedef uint16_t jchar;
        typedef int16_t  jshort;
        typedef int32_t  jint;
        typedef int64_t  jlong;
        typedef float    jfloat;
        typedef double   jdouble;
     */
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