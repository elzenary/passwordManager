#ifndef CREDENTIAL_MANAGER_H
#define CREDENTIAL_MANAGER_H

#include "ICredentialService.h"
#include "VaultManager.h"
#include <unordered_map>
#include <memory>

class CredentialManager : public ICredentialService {
private:
    std::unordered_map<std::string, CredentialData> storage_;
    std::shared_ptr<IVaultManager> vault_;

public:
    explicit CredentialManager(std::shared_ptr<IVaultManager> vault);

    bool addCredential(const std::string& service, const CredentialData& data) override;
    std::optional<CredentialData> getCredential(const std::string& service) const override;
    bool deleteCredential(const std::string& service) override;
    std::vector<ServiceCredential> listCredentials() const override;
};

#endif // CREDENTIAL_MANAGER_H
