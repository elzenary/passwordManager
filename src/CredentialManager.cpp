#include "CredentialManager.h"
#include <iostream>

bool CredentialManager::addCredential(const Credential& cred) {
std::cout << "[Dummy] Added credential for service: " << cred.service << std::endl;
credentials_.push_back(cred);
return true;
}

bool CredentialManager::deleteCredential(const Credential& cred){
std::cout << "[Dummy] Deleting credential for service: " << cred.service << std::endl;
return true;
}


void CredentialManager::listCredentials() const {
std::cout << "[Dummy] Listing credentials (" << credentials_.size() << ")\n";
}