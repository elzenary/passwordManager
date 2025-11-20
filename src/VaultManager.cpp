// VaultManager.cpp
#include "VaultManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

// Constructor: store file path
VaultManager::VaultManager(const std::string& filePath)
    : filePath_(filePath) {}

// Simple serialization: each element on a new line: service, username, password
std::vector<uint8_t> VaultManager::serialize(
    const std::unordered_map<std::string, CredentialData>& credentials)
{
    std::vector<uint8_t> out;

    for (const auto& [service, data] : credentials) {
        std::string line = service + "\n" + data.username + "\n" + data.password + "\n";
        out.insert(out.end(), line.begin(), line.end());
    }

    return out;
}

// Simple deserialization: read 3 lines per entry: service, username, password
std::unordered_map<std::string, CredentialData> VaultManager::deserialize(
    const std::vector<uint8_t> &plainBytes)
{
    std::unordered_map<std::string, CredentialData> storage;
    std::string content(plainBytes.begin(), plainBytes.end());
    std::istringstream iss(content);
    std::string service, username, password;

    while (std::getline(iss, service) && std::getline(iss, username) && std::getline(iss, password)) {
        storage[service] = {username, password};
    }

    return storage;
}

// Load file content as bytes
const std::vector<uint8_t> VaultManager::load()
{
    std::ifstream file(filePath_);
    if (!file.is_open()) return {};

    std::string line, content;
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    return std::vector<uint8_t>(content.begin(), content.end());
}

// Save bytes to file
bool VaultManager::save(const std::vector<uint8_t> &encryptedPayload)
{
    std::ofstream file(filePath_);
    if (!file.is_open()) return false;

    std::string str(encryptedPayload.begin(), encryptedPayload.end());
    file << str;
    return true;
}