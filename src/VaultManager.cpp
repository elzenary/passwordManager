#include "VaultManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

VaultManager::VaultManager(const std::string& filePath)
    : filePath_(filePath) {}

bool VaultManager::save(const std::unordered_map<std::string, CredentialData>& storage) {
    std::ofstream file(filePath_);
    if (!file.is_open()) return false;

    for (const auto& [service, data] : storage) {
        file << encrypt(service) << "," 
             << encrypt(data.username) << "," 
             << encrypt(data.password) << "\n";
    }
    return true;
}

std::unordered_map<std::string, CredentialData> VaultManager::load() {
    std::unordered_map<std::string, CredentialData> storage;
    std::ifstream file(filePath_);
    if (!file.is_open()) return storage;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string service, user, pass;
        if (std::getline(ss, service, ',') &&
            std::getline(ss, user, ',') &&
            std::getline(ss, pass)) {
            storage[decrypt(service)] = {decrypt(user), decrypt(pass)};
        }
    }
    return storage;
}

std::string VaultManager::encrypt(const std::string& input) const {
    std::string output = input;
    for (char& c : output) c += 1; // simple shift encryption
    return output;
}

std::string VaultManager::decrypt(const std::string& input) const {
    std::string output = input;
    for (char& c : output) c -= 1;
    return output;
}
