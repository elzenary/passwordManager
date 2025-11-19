#ifndef I_CREDENTIAL_SERVICE_H
#define I_CREDENTIAL_SERVICE_H

#include <string>
#include <vector>
#include <optional>

#include "CredentialData.h"

class ICredentialService {
public:
    virtual ~ICredentialService() = default;

    virtual bool addCredential(const std::string& service, const CredentialData& data) = 0;
    virtual std::optional<CredentialData> getCredential(const std::string& service) const = 0;
    virtual bool deleteCredential(const std::string& service) = 0;
    virtual std::vector<ServiceCredential> listCredentials() const = 0;
    virtual bool activate(const std::vector<uint8_t>& masterKey) = 0;
    virtual void deactivate() = 0;
};

#endif // I_CREDENTIAL_SERVICE_H
