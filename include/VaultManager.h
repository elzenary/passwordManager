#ifndef VAULT_MANAGER_H
#define VAULT_MANAGER_H

#include <string>
#include <cstdint>
#include <unordered_map>
#include "CredentialData.h"
#include "IVaultManager.h"

class VaultManager : public IVaultManager  {
private:
    std::string filePath_;

public:
    explicit VaultManager(const std::string& filePath);

     std::vector<uint8_t> serialize(
        const std::unordered_map<std::string, CredentialData>& credentials) override;

     std::unordered_map<std::string, CredentialData> deserialize(
        const std::vector<uint8_t> &plainBytes) override;

     const std::vector<uint8_t>  load() override;
     bool save(const std::vector<uint8_t>& encryptedPayload) override;

private:
        std::string  fileHeader_;
};

#endif // VAULT_MANAGER_H
