#include "CLI.h"
#include <iostream>

CLI::CLI(std::shared_ptr<ICredentialService> service)
    : credentialService_(std::move(service)) {}

void CLI::run() {
    int choice;
    std::string service, username, password;

    do {
        std::cout << "\n--- Password Manager CLI ---\n";
        std::cout << "1. Add Credential\n2. Get Credential\n3. Delete Credential\n4. List Credentials\n0. Exit\n> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Service: ";
                std::cin >> service;
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
                credentialService_->addCredential(service, {username, password});
                break;

            case 2:
                std::cout << "Service: ";
                std::cin >> service;
                if (auto cred = credentialService_->getCredential(service)) {
                    std::cout << "User: " << cred->username << ", Pass: " << cred->password << "\n";
                } else {
                    std::cout << "Not found.\n";
                }
                break;

            case 3:
                std::cout << "Service: ";
                std::cin >> service;
                credentialService_->deleteCredential(service);
                break;

            case 4:
                for (auto& c : credentialService_->listCredentials()) {
                    std::cout << c.service << ": " << c.data.username << "\n";
                }
                break;
        }
    } while (choice != 0);
}
