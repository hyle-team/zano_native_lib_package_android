# PlainWalletApi

The `PlainWalletApi` class provides a Java interface for interacting with wallet functions in an Android application.

## Initialization Functions

### `initWithAddress`
Initializes the wallet using the specified address.

```java
public native String initWithAddress(String address, String workingDir, int logLevel);
```
- **Parameters**:
  - `address`: The address to initialize the wallet with (e.g., `http://127.0.0.1:2222`).
  - `workingDir`: The working directory for the wallet.
  - `logLevel`: The logging level.

### `initWithIp`
Initializes the wallet using the specified IP address and port.

```java
public native String initWithIp(String ip, String port, String workingDir, int logLevel);
```
- **Parameters**:
  - `ip`: The IP address to initialize the wallet with.
  - `port`: The port number.
  - `workingDir`: The working directory for the wallet.
  - `logLevel`: The logging level.

## Utility Functions

### `reset`
Resets the wallet.

```java
public native String reset();
```

### `setLogLevel`
Sets the logging level for the wallet.

```java
public native String setLogLevel(int logLevel);
```
- **Parameters**:
  - `logLevel`: The logging level.

### `getVersion`
Retrieves the version of the wallet API.

```java
public native String getVersion();
```

### `getWalletFiles`
Retrieves information about wallet files.

```java
public native String getWalletFiles();
```

### `getExportPrivateInfo`
Exports private information to the specified directory.

```java
public native String getExportPrivateInfo(String targetDir);
```
- **Parameters**:
  - `targetDir`: The directory to export private information to.

### `deleteWallet`
Deletes the wallet with the specified file name.

```java
public native String deleteWallet(String fileName);
```
- **Parameters**:
  - `fileName`: The name of the wallet file to delete.

### `getAddressInfo`
Retrieves information about a specific address.

```java
public native String getAddressInfo(String addr);
```
- **Parameters**:
  - `addr`: The address to retrieve information for.

## Configuration Functions

### `getAppConfig`
Retrieves the application configuration using the specified encryption key.

```java
public native String getAppConfig(String encryptionKey);
```
- **Parameters**:
  - `encryptionKey`: The encryption key to decrypt the configuration.

### `setAppConfig`
Sets the application configuration using the specified configuration string and encryption key.

```java
public native String setAppConfig(String confStr, String encryptionKey);
```
- **Parameters**:
  - `confStr`: The configuration string.
  - `encryptionKey`: The encryption key to encrypt the configuration.

### `generateRandomKey`
Generates a random key of the specified length.

```java
public native String generateRandomKey(long length);
```
- **Parameters**:
  - `length`: The length of the random key.

### `getLogsBuffer`
Retrieves the logs buffer for debugging.

```java
public native String getLogsBuffer();
```

### `truncateLog`
Truncates the log.

```java
public native String truncateLog();
```

### `getConnectivityStatus`
Retrieves the connectivity status.

```java
public native String getConnectivityStatus();
```

## Wallet Management Functions

### `open`
Opens a wallet from the specified path using the provided password.

```java
public native String open(String path, String password);
```
- **Parameters**:
  - `path`: The path to the wallet file.
  - `password`: The password to open the wallet.

### `restore`
Restores a wallet using the provided seed, path, password, and optional seed password.

```java
public native String restore(String seed, String path, String password, String seedPassword);
```
- **Parameters**:
  - `seed`: The seed for the wallet.
  - `path`: The path to restore the wallet to.
  - `password`: The password for the wallet.
  - `seedPassword`: The optional seed password.

### `generate`
Generates a new wallet at the specified path with the provided password.

```java
public native String generate(String path, String password);
```
- **Parameters**:
  - `path`: The path to generate the wallet.
  - `password`: The password for the wallet.

### `getOpenedWallets`
Retrieves information about opened wallets.

```java
public native String getOpenedWallets();
```

## Wallet Operations

### `getWalletStatus`
Retrieves the status of the wallet with the specified handle.

```java
public native String getWalletStatus(long h);
```
- **Parameters**:
  - `h`: The handle of the wallet.

### `closeWallet`
Closes the wallet with the specified handle.

```java
public native String closeWallet(long h);
```
- **Parameters**:
  - `h`: The handle of the wallet.

### `invoke`
Invokes a JSON RPC on the wallet with the specified handle and parameters.

```java
public native String invoke(long h, String params);
```
- **Parameters**:
  - `h`: The handle of the wallet.
  - `params`: The parameters for the JSON RPC.

## Asynchronous API Functions

### `asyncCall`
Initiates an asynchronous RPC call to a method with the specified name, instance ID, and parameters.

```java
public native String asyncCall(String methodName, long instanceId, String params);
```
- **Parameters**:
  - `methodName`: The name of the method.
  - `instanceId`: The instance ID.
  - `params`: The parameters for the method.

### `tryPullResult`
Tries to pull the result of a previous asynchronous call.

```java
public native String tryPullResult(long instanceId);
```
- **Parameters**:
  - `instanceId`: The instance ID.

### `syncCall`
Initiates a synchronous RPC call to a method with the specified name, instance ID, and parameters.

```java
public native String syncCall(String methodName, long instanceId, String params);
```
- **Parameters**:
  - `methodName`: The name of the method.
  - `instanceId`: The instance ID.
  - `params`: The parameters for the method.

## Cake Wallet API Extension

### `isWalletExist`
Checks if a wallet exists at the specified path.

```java
public native boolean isWalletExist(String path);
```
- **Parameters**:
  - `path`: The path to the wallet file.

### `getWalletInfo`
Retrieves information about the wallet with the specified handle.

```java
public native String getWalletInfo(long h);
```
- **Parameters**:
  - `h`: The handle of the wallet.

### `resetWalletPassword`
Resets the password of the wallet with the specified handle.

```java
public native String resetWalletPassword(long h, String password);
```
- **Parameters**:
  - `h`: The handle of the wallet.
  - `password`: The new password for the wallet.

### `getCurrentTxFee`
Retrieves the current transaction fee based on priority.

```java
public native long getCurrentTxFee(long priority);
```
- **Parameters**:
  - `priority`: The priority of the transaction fee.

---
