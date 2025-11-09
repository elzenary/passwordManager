#include<iostream>
#include"CLI.h"
#include "VaultManager.h"
#include "CredentialManager.h"

int main(){
    CLIInterface cli_{};
    cli_.run();
  std::cout<<"Hello password manager";
  return 0;
}