#include "CLI.h"
#include <iostream>


CLIInterface::CLIInterface() {
std::cout << "CLI Interface initialized." << std::endl;
}

void CLIInterface::run() {
std::cout << "Welcome to Dummy Password Manager!\n";
std::string cmd;
while (true) {
showMenu();
std::getline(std::cin, cmd);
if (cmd == "exit") break;
handleCommand(cmd);
}
}

void CLIInterface::showMenu() {
std::cout << "\nCommands: add | list | get | delete | exit\n> ";
}

void CLIInterface::handleCommand(const std::string& cmd) {
if (cmd == "add") {
creds_.addCredential({"example.com", "user", "pass"});
} else if (cmd == "list") {
creds_.listCredentials();
} else if (cmd == "get") {
//auto c = creds_.getCredential("example.com");
//if (c) std::cout << "Username: " << c->username << ", Password: " << c->password << std::endl;
} else if (cmd == "delete") {
//creds_.deleteCredential("example.com");
} else {
std::cout << "Unknown command." << std::endl;
}
}