#include <jni.h>
#include <string>
#include "com_dowell_zanowalletlib_PlainWalletApi.h"
#include "plain_wallet_api.h"
#include <regex>

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_initWithAddress(JNIEnv *env, jobject, jstring address, jstring working_dir, jint log_level) {
    const char* address_cstr = env->GetStringUTFChars(address, 0);
    const char* working_dir_cstr = env->GetStringUTFChars(working_dir, 0);
    std::string result = plain_wallet::init(address_cstr, working_dir_cstr, log_level);
    env->ReleaseStringUTFChars(address, address_cstr);
    env->ReleaseStringUTFChars(working_dir, working_dir_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_initWithIp(JNIEnv *env, jobject, jstring ip, jstring port, jstring working_dir, jint log_level) {
    const char* ip_cstr = env->GetStringUTFChars(ip, 0);
    const char* port_cstr = env->GetStringUTFChars(port, 0);
    const char* working_dir_cstr = env->GetStringUTFChars(working_dir, 0);
    std::string result = plain_wallet::init(ip_cstr, port_cstr, working_dir_cstr, log_level);
    env->ReleaseStringUTFChars(ip, ip_cstr);
    env->ReleaseStringUTFChars(port, port_cstr);
    env->ReleaseStringUTFChars(working_dir, working_dir_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_reset(JNIEnv *env, jobject) {
    std::string result = plain_wallet::reset();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_setLogLevel(JNIEnv *env, jobject, jint log_level) {
    std::string result = plain_wallet::set_log_level(log_level);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getVersion(JNIEnv *env, jobject) {
    std::string result = plain_wallet::get_version();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getWalletFiles(JNIEnv *env, jobject) {
    std::string result = plain_wallet::get_wallet_files();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getExportPrivateInfo(JNIEnv *env, jobject, jstring target_dir) {
    const char* target_dir_cstr = env->GetStringUTFChars(target_dir, 0);
    std::string result = plain_wallet::get_export_private_info(target_dir_cstr);
    env->ReleaseStringUTFChars(target_dir, target_dir_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_deleteWallet(JNIEnv *env, jobject, jstring file_name) {
    const char* file_name_cstr = env->GetStringUTFChars(file_name, 0);
    std::string result = plain_wallet::delete_wallet(file_name_cstr);
    env->ReleaseStringUTFChars(file_name, file_name_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getAddressInfo(JNIEnv *env, jobject, jstring addr) {
    const char* addr_cstr = env->GetStringUTFChars(addr, 0);
    std::string result = plain_wallet::get_address_info(addr_cstr);
    env->ReleaseStringUTFChars(addr, addr_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getAppConfig(JNIEnv *env, jobject, jstring encryption_key) {
    const char* encryption_key_cstr = env->GetStringUTFChars(encryption_key, 0);
    std::string result = plain_wallet::get_appconfig(encryption_key_cstr);
    env->ReleaseStringUTFChars(encryption_key, encryption_key_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_setAppConfig(JNIEnv *env, jobject, jstring conf_str, jstring encryption_key) {
    const char* conf_str_cstr = env->GetStringUTFChars(conf_str, 0);
    const char* encryption_key_cstr = env->GetStringUTFChars(encryption_key, 0);
    std::string result = plain_wallet::set_appconfig(conf_str_cstr, encryption_key_cstr);
    env->ReleaseStringUTFChars(conf_str, conf_str_cstr);
    env->ReleaseStringUTFChars(encryption_key, encryption_key_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_generateRandomKey(JNIEnv *env, jobject, jlong length) {
    std::string result = plain_wallet::generate_random_key(length);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getLogsBuffer(JNIEnv *env, jobject) {
    std::string result = plain_wallet::get_logs_buffer();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_truncateLog(JNIEnv *env, jobject) {
    std::string result = plain_wallet::truncate_log();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getConnectivityStatus(JNIEnv *env, jobject) {
    std::string result = plain_wallet::get_connectivity_status();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_open(JNIEnv *env, jobject, jstring path, jstring password) {
    const char* path_cstr = env->GetStringUTFChars(path, 0);
    const char* password_cstr = env->GetStringUTFChars(password, 0);
    std::string result = plain_wallet::open(path_cstr, password_cstr);
    env->ReleaseStringUTFChars(path, path_cstr);
    env->ReleaseStringUTFChars(password, password_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_restore(JNIEnv *env, jobject, jstring seed, jstring path, jstring password, jstring seed_password) {
    const char* seed_cstr = env->GetStringUTFChars(seed, 0);
    const char* path_cstr = env->GetStringUTFChars(path, 0);
    const char* password_cstr = env->GetStringUTFChars(password, 0);
    const char* seed_password_cstr = env->GetStringUTFChars(seed_password, 0);
    std::string result = plain_wallet::restore(seed_cstr, path_cstr, password_cstr, seed_password_cstr);
    env->ReleaseStringUTFChars(seed, seed_cstr);
    env->ReleaseStringUTFChars(path, path_cstr);
    env->ReleaseStringUTFChars(password, password_cstr);
    env->ReleaseStringUTFChars(seed_password, seed_password_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_generate(JNIEnv *env, jobject, jstring path, jstring password) {
    const char* path_cstr = env->GetStringUTFChars(path, 0);
    const char* password_cstr = env->GetStringUTFChars(password, 0);
    std::string result = plain_wallet::generate(path_cstr, password_cstr);
    env->ReleaseStringUTFChars(path, path_cstr);
    env->ReleaseStringUTFChars(password, password_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getOpenedWallets(JNIEnv *env, jobject) {
    std::string result = plain_wallet::get_opened_wallets();
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getWalletStatus(JNIEnv *env, jobject, jlong h) {
    std::string result = plain_wallet::get_wallet_status(h);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_closeWallet(JNIEnv *env, jobject, jlong h) {
    std::string result = plain_wallet::close_wallet(h);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_invoke(JNIEnv *env, jobject, jlong h, jstring params) {
    const char* params_cstr = env->GetStringUTFChars(params, 0);
    std::string result = plain_wallet::invoke(h, params_cstr);
    env->ReleaseStringUTFChars(params, params_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_asyncCall(JNIEnv *env, jobject, jstring method_name, jlong instance_id, jstring params) {
    const char* method_name_cstr = env->GetStringUTFChars(method_name, 0);
    const char* params_cstr = env->GetStringUTFChars(params, 0);
    std::string result = plain_wallet::async_call(method_name_cstr, instance_id, params_cstr);
    env->ReleaseStringUTFChars(method_name, method_name_cstr);
    env->ReleaseStringUTFChars(params, params_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_tryPullResult(JNIEnv *env, jobject, jlong instance_id) {
    try {
        std::string result = plain_wallet::try_pull_result(instance_id);

        // Debug: Check if result is empty
        if (result.empty()) {
            return env->NewStringUTF("{}");
        }

        // Try the most aggressive cleaning
        std::string cleaned;
        for (char c: result) {
            if (c >= 32 && c <= 126) { // Only printable ASCII
                cleaned += c;
            } else if (c == '\n' || c == '\r' || c == '\t') {
                cleaned += c; // Keep basic whitespace
            }
            // Skip everything else (including invalid UTF-8)
        }

        return env->NewStringUTF(cleaned.c_str());

    } catch (...) {
        // If anything fails, return empty JSON
        return env->NewStringUTF("{}");
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_syncCall(JNIEnv *env, jobject, jstring method_name, jlong instance_id, jstring params) {
    const char* method_name_cstr = env->GetStringUTFChars(method_name, 0);
    const char* params_cstr = env->GetStringUTFChars(params, 0);
    std::string result = plain_wallet::sync_call(method_name_cstr, instance_id, params_cstr);
    env->ReleaseStringUTFChars(method_name, method_name_cstr);
    env->ReleaseStringUTFChars(params, params_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_isWalletExist(JNIEnv *env, jobject, jstring path) {
    const char* path_cstr = env->GetStringUTFChars(path, 0);
    bool result = plain_wallet::is_wallet_exist(path_cstr);
    env->ReleaseStringUTFChars(path, path_cstr);
    return result ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getWalletInfo(JNIEnv *env, jobject, jlong h) {
    std::string result = plain_wallet::get_wallet_info(h);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_resetWalletPassword(JNIEnv *env, jobject, jlong h, jstring password) {
    const char* password_cstr = env->GetStringUTFChars(password, 0);
    std::string result = plain_wallet::reset_wallet_password(h, password_cstr);
    env->ReleaseStringUTFChars(password, password_cstr);
    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_dowell_zanowalletlib_PlainWalletApi_getCurrentTxFee(JNIEnv *env, jobject, jlong priority) {
    uint64_t result = plain_wallet::get_current_tx_fee(priority);
    return static_cast<jlong>(result);
}
