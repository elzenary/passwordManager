#include "CredentialManager.h"


CredentialManager::CredentialManager(
std::shared_ptr<IVaultManager> vault,
std::shared_ptr<SecurityManager> securityManager)
: vault_(std::move(vault)), securityManager_(std::move(securityManager)), activate_{false} {}


bool CredentialManager::addCredential(const std::string& service, const CredentialData& data) {
    if (!activate_) return false;
    
    storage_[service] = data;
    return saveVault();
}


std::optional<CredentialData> CredentialManager::getCredential(const std::string& service) const {
    if (!activate_) return std::nullopt;
    
    auto it = storage_.find(service);
    if (it != storage_.end())
        return it->second;
    return std::nullopt;
}


bool CredentialManager::deleteCredential(const std::string& service) {
    if (!activate_) return false;

    if (storage_.erase(service)) {
        return saveVault();
    }
    return false;
}

std::vector<ServiceCredential> CredentialManager::listCredentials() const {
    std::vector<ServiceCredential> list;

    if (!activate_) return list;

    for (const auto& [service, data] : storage_) {
        list.push_back({service, data});
    }

    return list;
}


bool CredentialManager::activate(const std::vector<uint8_t>& masterKey)
{
    securityManager_->setMasterKey(masterKey);
    activate_ = true;
    return loadVault();
}


void CredentialManager::deactivate()
{
    activate_ = false;
    storage_.clear();
}


bool CredentialManager::loadVault()
{
    auto ciphertext = vault_->load();
    if (ciphertext.empty()) return true;
    auto plaintext = securityManager_->decrypt(ciphertext);
    storage_ = vault_->deserialize(plaintext);
    return true;
}


bool CredentialManager::saveVault()
{
    auto plain = vault_->serialize(storage_);
    auto encrypted = securityManager_->encrypt(plain);
    return vault_->save(encrypted);
}
