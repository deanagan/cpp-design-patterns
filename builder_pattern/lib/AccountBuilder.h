#pragma once

#include <memory>
#include <string>

namespace Accounts
{
    class Account;
    class AccountBuilder
    {
    public:
        explicit AccountBuilder(std::unique_ptr<Account> account);
        AccountBuilder& WithName(std::string name);
        AccountBuilder& HavingInitialAmount(int amount);

        std::unique_ptr<Account> Build();

        virtual ~AccountBuilder() = 0;    

    private:
        bool m_hasBuildErrors { false };
        bool m_isNameSet { false };
        bool m_isInitialAmountSet { false };
        std::unique_ptr<Account> m_pAccount;
    };
}
