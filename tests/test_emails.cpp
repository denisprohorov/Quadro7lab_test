#include <emails/emails.h>
#include <gtest/gtest.h>

TEST(emails_lib, empty_str) {
    std::string empty_str{};
    EXPECT_STREQ(emails::hide_email(empty_str).c_str(), empty_str.c_str());
}

TEST(emails_lib, two_char_str)
{
    std::string two_char_str {"a@"};
    EXPECT_STREQ(emails::hide_email(two_char_str).c_str(), "**");
}

TEST(emails_lib, three_char_str)
{
    std::string three_char_str{"a@y"};
    EXPECT_STREQ(emails::hide_email(three_char_str).c_str(), "a**");
}
