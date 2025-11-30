#include <sodium.h>
#include <string>
#include <vector>

std::vector<unsigned char> hash_password(const std::string &password) {
    std::vector<unsigned char> hash(crypto_pwhash_STRBYTES);

    if (crypto_pwhash_str(
            reinterpret_cast<char*>(hash.data()),
            password.c_str(),
            password.size(),
            crypto_pwhash_OPSLIMIT_INTERACTIVE,
            crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0) {
        //throw std::runtime_error("Out of memory or internal failure");
    }

    return hash;
}

bool verify_password(const std::string &password, const std::vector<unsigned char>& hash) {
    return crypto_pwhash_str_verify(
        reinterpret_cast<const char*>(hash.data()),
        password.c_str(),
        password.size()
    ) == 0;
}
