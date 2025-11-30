#include "crypto.h"
#include <sodium.h>
#include <stdexcept>

Crypto::Crypto() {
    if (sodium_init() < 0) {
        throw std::runtime_error("Failed to initialize libsodium");
    }
}

std::vector<uint8_t> Crypto::generateKey() {
    std::vector<uint8_t> key(crypto_secretbox_KEYBYTES);
    randombytes_buf(key.data(), crypto_secretbox_KEYBYTES);
    return key;
}

std::vector<uint8_t> Crypto::encrypt(const std::vector<uint8_t>& plaintext,
                                     const std::vector<uint8_t>& key) 
{
    if (key.size() != crypto_secretbox_KEYBYTES)
        throw std::runtime_error("Invalid key size");

    std::vector<uint8_t> nonce(crypto_secretbox_NONCEBYTES);
    randombytes_buf(nonce.data(), crypto_secretbox_NONCEBYTES);

    std::vector<uint8_t> ciphertext(plaintext.size() + crypto_secretbox_MACBYTES);
    crypto_secretbox_easy(ciphertext.data(),
                          plaintext.data(),
                          plaintext.size(),
                          nonce.data(),
                          key.data());

    // Prepend nonce
    std::vector<uint8_t> result;
    result.reserve(nonce.size() + ciphertext.size());
    result.insert(result.end(), nonce.begin(), nonce.end());
    result.insert(result.end(), ciphertext.begin(), ciphertext.end());

    return result;
}

std::vector<uint8_t> Crypto::decrypt(const std::vector<uint8_t>& ciphertext_with_nonce,
                                     const std::vector<uint8_t>& key) 
{
    if (key.size() != crypto_secretbox_KEYBYTES)
        throw std::runtime_error("Invalid key size");

    if (ciphertext_with_nonce.size() < crypto_secretbox_NONCEBYTES + crypto_secretbox_MACBYTES)
        throw std::runtime_error("Ciphertext too short");

    const uint8_t* nonce = ciphertext_with_nonce.data();
    const uint8_t* ciphertext = ciphertext_with_nonce.data() + crypto_secretbox_NONCEBYTES;
    size_t ciphertext_len = ciphertext_with_nonce.size() - crypto_secretbox_NONCEBYTES;

    std::vector<uint8_t> plaintext(ciphertext_len - crypto_secretbox_MACBYTES);
    if (crypto_secretbox_open_easy(plaintext.data(), ciphertext, ciphertext_len, nonce, key.data()) != 0)
        throw std::runtime_error("Decryption failed");

    return plaintext;
}

std::vector<uint8_t> Crypto::hash(const std::vector<uint8_t>& input) {
    std::vector<uint8_t> digest(crypto_hash_sha256_BYTES);
    crypto_hash_sha256(digest.data(), input.data(), input.size());
    return digest;
}
