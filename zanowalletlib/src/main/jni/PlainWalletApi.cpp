#include <jni.h>
#include <string>
#include "com_dowell_zanowalletlib_PlainWalletApi.h"
#include "plain_wallet_api.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_dowell_zanowalletlib_PlainWalletApi_init
        (JNIEnv *env, jobject obj, jstring jaddress, jstring jworkingDir, jint jlogLevel) {
    const char *address = env->GetStringUTFChars(jaddress, 0);
    const char *workingDir = env->GetStringUTFChars(jworkingDir, 0);
    int logLevel = jlogLevel;

    std::string result = plain_wallet::init(address, workingDir, logLevel);

    env->ReleaseStringUTFChars(jaddress, address);
    env->ReleaseStringUTFChars(jworkingDir, workingDir);

    return env->NewStringUTF("");
}