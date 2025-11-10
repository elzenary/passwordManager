                <<interface>>
           +-------------------------------------------+
           |           ICredentialService             |
           +-------------------------------------------+
           | + bool addCredential(const std::string& service, const CredentialData& data) |
           | + std::optional<CredentialData> getCredential(const std::string& service) const |
           | + bool deleteCredential(const std::string& service) |
           | + std::vector<ServiceCredential> listCredentials() const |
           +-------------------------------------------+
                     ▲
                     | <<realizes>>
                     |
           +-------------------------------------------+
           |           CredentialManager              |
           +-------------------------------------------+
           | - storage_: std::unordered_map<std::string, CredentialData> |
           | - vault_: std::shared_ptr<VaultManager>  |
           +-------------------------------------------+
           | + CredentialManager(std::shared_ptr<VaultManager> vault)   |
           | + bool addCredential(const std::string& service, const CredentialData& data) |
           | + std::optional<CredentialData> getCredential(const std::string& service) const |
           | + bool deleteCredential(const std::string& service) |
           | + std::vector<ServiceCredential> listCredentials() const |
           +-------------------------------------------+
              ▲                     ▲
              |                     |
      <<composition>>          <<aggregation>>
              |                     |
+-----------------------------+      |
|       CredentialData        |      |
+-----------------------------+      |
| - username: std::string     |      |
| - password: std::string     |      |
+-----------------------------+      |
                                     |
+-----------------------------+      |
|    ServiceCredential        |      |
+-----------------------------+      |
| - service: std::string      |      |
| - data: CredentialData      |      |
+-----------------------------+      |
                                     |
                  +-------------------------------------------+
                  |                   CLI                     |
                  +-------------------------------------------+
                  | - credentialService_: std::shared_ptr<ICredentialService> |
                  | - vault_: std::shared_ptr<VaultManager>                   |
                  +-------------------------------------------+
                  | + CLI(std::shared_ptr<ICredentialService> service, std::shared_ptr<VaultManager> vault) |
                  | + void run()                                                   |
                  +-------------------------------------------+
                     ▲
                     │ aggregation
                     │
           +-------------------------------------------+
           |                VaultManager               |
           +-------------------------------------------+
           | - filePath_: std::string                  |
           +-------------------------------------------+
           | + VaultManager(const std::string& filePath) |
           | + bool save(const std::unordered_map<std::string, CredentialData>& storage) |
           | + std::unordered_map<std::string, CredentialData> load() |
           | - std::string encrypt(const std::string& input) const |
           | - std::string decrypt(const std::string& input) const |
           +-------------------------------------------+
