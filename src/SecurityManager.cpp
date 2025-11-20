#include "securityManager.h"
#include <stdexcept>
#include <algorithm>    // for std::transform

// -------------------------------------------------------------
// Constructor
// -------------------------------------------------------------
SecurityManager::SecurityManager(std::vector<uint8_t> masterKey)
    : m_masterKey(std::move(masterKey))
{
    if (m_masterKey.empty()) {
        throw std::runtime_error("SecurityManager: master key must not be empty");
    }
}

// -------------------------------------------------------------
// Dummy encryption: XOR plaintext with key
// (Only for demonstration! Not secure.)
// -------------------------------------------------------------
std::vector<uint8_t> SecurityManager::encrypt(const std::vector<uint8_t>& plaintext)
{
    std::vector<uint8_t> ciphertext;

    if (m_masterKey.empty()) {
        throw std::runtime_error("SecurityManager: master key is not set");
    }

    ciphertext.resize(plaintext.size());

    for (size_t i = 0; i < plaintext.size(); i++) {
        ciphertext[i] = plaintext[i] ^ m_masterKey[i % m_masterKey.size()];
    }

    return ciphertext;
}

// -------------------------------------------------------------
// Dummy decryption: same XOR again
// -------------------------------------------------------------
std::vector<uint8_t> SecurityManager::decrypt(const std::vector<uint8_t>& ciphertext)
{
    std::vector<uint8_t> plaintext;

    if (m_masterKey.empty()) {
        throw std::runtime_error("SecurityManager: master key is not set");
    }

    plaintext.resize(ciphertext.size());

    for (size_t i = 0; i < ciphertext.size(); i++) {
        plaintext[i] = ciphertext[i] ^ m_masterKey[i % m_masterKey.size()];
    }

    return plaintext;
}


void SecurityManager::setMasterKey(const std::vector<uint8_t>& key)
{
    if (key.empty()) {
        throw std::runtime_error("SecurityManager: master key must not be empty");
    }

    m_masterKey = key;
}
