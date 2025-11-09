#pragma once
#include <string>
#include <vector>


struct Credential {
std::string service;
std::string username;
std::string password;
};


class CredentialManager {
public:
CredentialManager():credentials_{}{};
bool addCredential(const Credential& cred);
bool deleteCredential(const Credential& cred);
void listCredentials() const;


private:
std::vector<Credential> credentials_;
};