#ifndef CLI_H
#define CLI_H

#include <memory>
#include "ICredentialService.h"

class CLI {
private:
    std::shared_ptr<ICredentialService> credentialService_;

public:
    explicit CLI(std::shared_ptr<ICredentialService> service);
    void run();
};

#endif // CLI_H
