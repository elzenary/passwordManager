#include <unordered_map>
#include "IVaultManager.h"
#include"mock_vault_manager.h"


    bool MockVaultManager::save(const std::unordered_map<std::string, CredentialData>& storage)  {
        return true; // no-op
    }
    std::unordered_map<std::string, CredentialData> MockVaultManager::load()  {
        return {}; // return empty mock data
    }
