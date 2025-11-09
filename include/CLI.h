#pragma once
#include <string>
#include "VaultManager.h"
#include "CredentialManager.h"


class CLIInterface {
public:
CLIInterface();
void run();


private:
CredentialManager creds_;
void showMenu();
void handleCommand(const std::string& cmd);
};