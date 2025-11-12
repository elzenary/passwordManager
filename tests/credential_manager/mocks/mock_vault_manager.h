#ifndef MOCK_VAULT_MANAGER_H
#define MOCK_VAULT_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "IVaultManager.h"
#include "CredentialData.h"

class MockVaultManager : public IVaultManager {
public:
    MockVaultManager() = default;
    ~MockVaultManager() override = default;
    bool save(const std::unordered_map<std::string, CredentialData>& storage) override;
    std::unordered_map<std::string, CredentialData> load() override;

    std::unordered_map<std::string, CredentialData> storedData;
};

#endif // MOCK_VAULT_MANAGER_H
