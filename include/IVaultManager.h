#ifndef I_VAULT_MANAGER_H
#define I_VAULT_MANAGER_H

#include <unordered_map>
#include "CredentialData.h"

class IVaultManager {
public:
    virtual ~IVaultManager() = default;

    virtual std::vector<uint8_t> serialize(
        const std::unordered_map<std::string, CredentialData>& credentials) = 0;

    virtual std::unordered_map<std::string, CredentialData> deserialize(
        const std::vector<uint8_t>& plainBytes) = 0;

    virtual bool save(const std::vector<uint8_t>& encryptedPayload) = 0;
    virtual const std::vector<uint8_t>  load() = 0;

};

#endif
