#pragma once
#include <optional>
#include<vector>
#include<string>
#include<optional>


class VaultManager {
public:
VaultManager();
bool createVault(const std::string& filePath, const std::string& masterPassword);
bool openVault(const std::string& filePath, const std::string& masterPassword);
bool saveVault(const std::string& filePath);


std::optional<std::string> getDecryptedData();


private:
std::string masterKey_;
std::vector<unsigned char> encryptedData_;
};