package com.dowell.zanowalletlib;

public class PlainWalletApi {
    static {
        System.loadLibrary("walletapi"); // Ensure this matches your native library name
    }

    public native String initWithAddress(String address, String workingDir, int logLevel);
    public native String initWithIp(String ip, String port, String workingDir, int logLevel);
    public native String reset();
    public native String setLogLevel(int logLevel);
    public native String getVersion();
    public native String getWalletFiles();
    public native String getExportPrivateInfo(String targetDir);
    public native String deleteWallet(String fileName);
    public native String getAddressInfo(String addr);
    public native String getAppConfig(String encryptionKey);
    public native String setAppConfig(String confStr, String encryptionKey);
    public native String generateRandomKey(long length);
    public native String getLogsBuffer();
    public native String truncateLog();
    public native String getConnectivityStatus();
    public native String open(String path, String password);
    public native String restore(String seed, String path, String password, String seedPassword);
    public native String generate(String path, String password);
    public native String getOpenedWallets();
    public native String getWalletStatus(long h);
    public native String closeWallet(long h);
    public native String invoke(long h, String params);
    public native String asyncCall(String methodName, long instanceId, String params);
    public native String tryPullResult(long instanceId);
    public native String syncCall(String methodName, long instanceId, String params);
    public native boolean isWalletExist(String path);
    public native String getWalletInfo(long h);
    public native String resetWalletPassword(long h, String password);
    public native long getCurrentTxFee(long priority);
}
