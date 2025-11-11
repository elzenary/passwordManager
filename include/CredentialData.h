#ifndef CREDENTIAL_DATA_H
#define CREDENTIAL_DATA_H

#include <string>

struct CredentialData {
    std::string username;
    std::string password;
};


struct ServiceCredential {
    std::string service;
    CredentialData data;
};

#endif // CREDENTIAL_DATA_H
