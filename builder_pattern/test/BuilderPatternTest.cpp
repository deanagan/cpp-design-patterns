#include "Account.h"
#include "SavingsAccountBuilder.h"

#include "MockAccount.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace BuilderPatternTest
{
    namespace
    {
        static const std::string ACCOUNT_NAME = "John Doe";
        static const int INITAL_AMOUNT = 100;
    }

    using ::testing::NiceMock;

    class BuilderPatternTestShould : public ::testing::Test
    {
    protected:

        std::unique_ptr<NiceMock<MockAccount>> m_pMockAccount;

        void SetUp() override
        {
            m_pMockAccount = std::make_unique<NiceMock<MockAccount>>();
        }

        void TearDown() override
        {

        }
    };


    TEST_F(BuilderPatternTestShould, ExpectInputAccountIsNull_WhenUsingAccountBuilder)
    {
        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.WithName(ACCOUNT_NAME).HavingInitialAmount(INITAL_AMOUNT).Build();

        EXPECT_EQ(nullptr, m_pMockAccount);
    }

    TEST_F(BuilderPatternTestShould, ExpectNameIsSetOnce_WhenUsingAccountBuilder)
    {
        EXPECT_CALL(*m_pMockAccount.get(), Name(ACCOUNT_NAME)).Times(1);

        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.WithName(ACCOUNT_NAME).HavingInitialAmount(INITAL_AMOUNT).Build();
    }

    TEST_F(BuilderPatternTestShould, ExpectInitialAmountSet_WhenUsingAccountBuilder)
    {
        EXPECT_CALL(*m_pMockAccount.get(), InitialAmount(INITAL_AMOUNT)).Times(1);

        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.WithName(ACCOUNT_NAME).HavingInitialAmount(INITAL_AMOUNT).Build();
    }

    TEST_F(BuilderPatternTestShould, ExpectBuildToReturnNull_WhenUsingAccountBuilderWithoutSettingName)
    {
        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.HavingInitialAmount(INITAL_AMOUNT).Build();

        EXPECT_EQ(nullptr, pAccount);
    }

    TEST_F(BuilderPatternTestShould, ExpectBuildToReturnNull_WhenUsingAccountBuilderWithoutInitialAmount)
    {
        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.WithName(ACCOUNT_NAME).Build();

        EXPECT_EQ(nullptr, pAccount);
    }

    TEST_F(BuilderPatternTestShould, ExpectBuildToReturnNull_WhenBuildingWithoutSettingAnything)
    {
        Accounts::SavingsAccountBuilder accountBuilder { std::move(m_pMockAccount) };

        auto pAccount = accountBuilder.Build();

        EXPECT_EQ(nullptr, pAccount);
    }

}
