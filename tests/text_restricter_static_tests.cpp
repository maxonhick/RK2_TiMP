#include <gtest/gtest.h>
#include "../strategies/TextRestricterStatic.h"
#include "../strategies/CurseRestrictionStrategy.h"
#include "../strategies/LengthRestrictionStrategy.h"
#include "../strategies/NoRestrictionStrategy.h"
#include "../strategies/TextRestrictionStrategy.h"

template <typename TextRestrictionStrategy>
auto MakeTextRestrictor(TextRestrictionStrategy&& strategy)
    -> TextRestricter<TextRestrictionStrategy>
{
    return TextRestricter<TextRestrictionStrategy>(std::move(strategy));
}

// Тест для NoRestrictionStrategy
TEST(TextRestricterStaticTest, NoRestriction) {
    auto restricter = MakeTextRestrictor(NoRestrictionStrategy());
    std::string concatedText;

    EXPECT_TRUE(restricter.ConcatText("hello", "world", concatedText));
    EXPECT_EQ(concatedText, "helloworld");

    // Проверка текста с ограничением
    restricter.PrintText("fuck");
    restricter.PrintText("looooooooooooooooooooooooooong text");
}

// Тест для CurseRestrictionStrategy
TEST(TextRestricterStaticTest, CurseRestriction) {
    auto restricter = MakeTextRestrictor(CurseRestrictionStrategy());
    std::string concatedText;

    EXPECT_FALSE(restricter.ConcatText("fuck", "world", concatedText));
    EXPECT_TRUE(concatedText.empty());

    // Проверка текста с ограничением
    restricter.PrintText("hello");
    restricter.PrintText("shit");
}

// Тест для LengthRestrictionStrategy
TEST(TextRestricterStaticTest, LengthRestriction) {
    auto restricter = MakeTextRestrictor(LengthRestrictionStrategy(1, 10));
    std::string concatedText;

    EXPECT_TRUE(restricter.ConcatText("hi", "world", concatedText));
    EXPECT_FALSE(restricter.ConcatText("hello", " world", concatedText));

    // Проверка текста с ограничением
    restricter.PrintText("short");
    restricter.PrintText("looooooooooooooooooooooooooong text");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
