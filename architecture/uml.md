                <<interface>>
           +-----------------------------+
           |     ICredentialService     |
           +-----------------------------+
           | + addCredential(service, data) : bool |
           | + getCredential(service) : optional<CredentialData> |
           | + deleteCredential(service) : bool |
           | + listCredentials() : vector<ServiceCredential> |
           +-----------------------------+
                     ▲
                     | <<realizes>>
                     |
           +-----------------------------+
           |     CredentialManager      |
           +-----------------------------+
           | - storage_: unordered_map<string, CredentialData> |
           | - vault_: shared_ptr<VaultManager>               |
           +-----------------------------+
           | + CredentialManager(vault: shared_ptr<VaultManager>) |
           | + addCredential(service, data) : bool                |
           | + getCredential(service) : optional<CredentialData> |
           | + deleteCredential(service) : bool                   |
           | + listCredentials() : vector<ServiceCredential>     |
           +-----------------------------+
              ▲                    ▲
              | <<composition>>    | <<aggregation>>
              |                    |
     +----------------+           |
     | CredentialData |           |
     +----------------+           |
     | - username     |           |
     | - password     |           |
     +----------------+           |
                                  |
     +---------------------+      |
     | ServiceCredential   |      |
     +---------------------+      |
     | - service: string   |      |
     | - data: CredentialData |    |
     +---------------------+      |
                                  |
           +-----------------------------+
           |            CLI              |
           +-----------------------------+
           | - credentialService_: shared_ptr<ICredentialService> |
           +-----------------------------+
           | + CLI(service: shared_ptr<ICredentialService>) |
           | + run() : void                                  |
           +-----------------------------+
                     ▲
                     | <<aggregation>>
                     |
           +-----------------------------+
           |       VaultManager         |
           +-----------------------------+
           | - filePath_: string        |
           +-----------------------------+
           | + VaultManager(filePath: string) |
           | + save(storage: unordered_map<string, CredentialData>) : bool |
           | + load() : unordered_map<string, CredentialData>             |
           | - encrypt(input: string) : string                             |
           | - decrypt(input: string) : string                             |
           +-----------------------------+
