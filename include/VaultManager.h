#ifndef VAULT_MANAGER_H
#define VAULT_MANAGER_H

#include <string>
#include <unordered_map>
#include "CredentialData.h"
#include "IVaultManager.h"

class VaultManager : public IVaultManager  {
private:
    std::string filePath_;

    std::string encrypt(const std::string& input) const;
    std::string decrypt(const std::string& input) const;

public:
    explicit VaultManager(const std::string& filePath);
    bool save(const std::unordered_map<std::string, CredentialData>& storage) override;
    std::unordered_map<std::string, CredentialData> load() override;
};

#endif // VAULT_MANAGER_H
