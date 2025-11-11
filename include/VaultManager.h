#ifndef VAULT_MANAGER_H
#define VAULT_MANAGER_H

#include <string>
#include <unordered_map>
#include "CredentialData.h"

class VaultManager {
private:
    std::string filePath_;

    std::string encrypt(const std::string& input) const;
    std::string decrypt(const std::string& input) const;

public:
    explicit VaultManager(const std::string& filePath);

    bool save(const std::unordered_map<std::string, CredentialData>& storage);
    std::unordered_map<std::string, CredentialData> load();
};

#endif // VAULT_MANAGER_H
