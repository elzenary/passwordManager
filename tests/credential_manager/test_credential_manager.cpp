#include <catch2/catch_test_macros.hpp>
#include "CredentialManager.h"
#include "mock_vault_manager.h"
#include"IVaultManager.h"
class MockVaultManager;
TEST_CASE("CredentialManager adds and retrieves credentials", "[CredentialManager]") {
    //auto mockVault = std::make_shared<VaultManager>("vault.dat");
    auto mockVault = std::make_shared<MockVaultManager>();
    CredentialManager manager(mockVault);

    CredentialData data{"user", "pass"};
    REQUIRE(manager.addCredential("gmail", data));

    auto retrieved = manager.getCredential("gmail");
    REQUIRE(retrieved.has_value());
    REQUIRE(retrieved->username == "user");
    REQUIRE(retrieved->password == "pass");
}