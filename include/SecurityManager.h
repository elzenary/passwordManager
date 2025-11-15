#pragma once
#include <vector>
#include <cstdint>

class SecurityManager {
public:
    explicit SecurityManager(std::vector<uint8_t> masterKey);

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext);
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& ciphertext);

private:
    std::vector<uint8_t> m_masterKey;
};
