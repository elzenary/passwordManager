#include "CLI.h"
#include "CredentialManager.h"
#include "VaultManager.h"
#include <memory>

int main() {
    auto vault = std::make_shared<VaultManager>("vault.dat");
    auto manager = std::make_shared<CredentialManager>(vault);
    CLI cli(manager);
    cli.run();
    return 0;
}
