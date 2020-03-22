#pragma once

#include "AccountBuilder.h"

namespace Accounts
{
    class SavingsAccountBuilder : public AccountBuilder
    {
    public:
        explicit SavingsAccountBuilder(std::unique_ptr<Account> account) : AccountBuilder(std::move(account))
        {}
    };
}
