#pragma once
#include <vector>
#include <cstdint>

class Crypto {
public:
    Crypto(); // Initialize libsodium

    // Encrypt plaintext using a key (returns nonce + ciphertext)
    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext,
                                 const std::vector<uint8_t>& key);

    // Decrypt nonce + ciphertext using the key
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& ciphertext_with_nonce,
                                 const std::vector<uint8_t>& key);

    // Generate random key
    std::vector<uint8_t> generateKey();

    // Compute SHA-256 hash of input
    std::vector<uint8_t> hash(const std::vector<uint8_t>& input);
};
