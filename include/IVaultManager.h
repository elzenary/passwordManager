#ifndef I_VAULT_MANAGER_H
#define I_VAULT_MANAGER_H

#include <unordered_map>
#include "CredentialData.h"

class IVaultManager {
public:
    virtual ~IVaultManager() = default;
    virtual bool save(const std::unordered_map<std::string, CredentialData>& storage) = 0;
    virtual std::unordered_map<std::string, CredentialData> load() = 0;
};

#endif
