#include "CredentialManager.h"

CredentialManager::CredentialManager(std::shared_ptr<IVaultManager> vault)
    : vault_(std::move(vault)) {
    storage_ = vault_->load();
}

bool CredentialManager::addCredential(const std::string& service, const CredentialData& data) {
    storage_[service] = data;
    return vault_->save(storage_);
}

std::optional<CredentialData> CredentialManager::getCredential(const std::string& service) const {
    auto it = storage_.find(service);
    if (it != storage_.end())
        return it->second;
    return std::nullopt;
}

bool CredentialManager::deleteCredential(const std::string& service) {
    if (storage_.erase(service)) {
        return vault_->save(storage_);
    }
    return false;
}

std::vector<ServiceCredential> CredentialManager::listCredentials() const {
    std::vector<ServiceCredential> list;
    for (const auto& [service, data] : storage_) {
        list.push_back({service, data});
    }
    return list;
}
