#include "AccountBuilder.h"
#include "Account.h"

namespace Accounts
{

AccountBuilder::AccountBuilder(std::unique_ptr<Account> account)
    : m_pAccount(std::move(account))
{

}

AccountBuilder::~AccountBuilder()
{

}

AccountBuilder& AccountBuilder::WithName(std::string name)
{
    if (m_isNameSet)
    {
        m_hasBuildErrors = true;
    }
    else
    {
        m_pAccount->Name(std::move(name));
        m_isNameSet = true;
    }

    return *this;
}

AccountBuilder& AccountBuilder::HavingInitialAmount(int amount)
{
    if (m_isInitialAmountSet)
    {
        m_hasBuildErrors = true;
    }
    else
    {
        m_pAccount->InitialAmount(amount);
        m_isInitialAmountSet = true;
    }

    return *this;
}

std::unique_ptr<Account> AccountBuilder::Build()
{
    if (m_hasBuildErrors || !(m_isNameSet && m_isInitialAmountSet))
    {
        return nullptr;
    }

    return std::move(m_pAccount);
}

}
