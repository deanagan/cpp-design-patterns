#pragma once

#include <string>

namespace Accounts
{
    class Account
    {
    public:
        virtual void Name(std::string name) = 0;
        virtual void InitialAmount(int amount) = 0;

        virtual std::string Name() const = 0;
        virtual int CurrentAmount() const = 0;

        virtual ~Account() {}
    
    };

}
