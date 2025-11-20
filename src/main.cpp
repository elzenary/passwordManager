#include "CLI.h"
#include "CredentialManager.h"
#include "VaultManager.h"
#include "SecurityManager.h"
#include <memory>
#include <vector>
#include <cstdint>

int main() {
    // Create vault manager
    auto vault = std::make_shared<VaultManager>("vault.dat");

    // Create empty master key (will be overwritten during activation)
    std::vector<uint8_t> dummyKey = { 0x01, 0x02, 0x03, 0x04 };;  

    // Create security manager with empty key for now
    auto securityManager = std::make_shared<SecurityManager>(dummyKey);

    // Create credential manager with both dependencies
    auto manager = std::make_shared<CredentialManager>(vault, securityManager);

    // Start CLI (CLI asks user for master key and activates manager)
    CLI cli(manager);
    cli.run();

    return 0;
}