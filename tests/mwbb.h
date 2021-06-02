#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(mwbb, on_word_1)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "|test line 1\n";
    output_text += "test line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 3);
    mwbb(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mwbb, on_word_2)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "test line 1\n";
    output_text += "test |line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 1, 6);
    mwbb(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mwbb, on_the_word_beginning)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "test line 1\n";
    output_text += "test |line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 1, 5);
    mwbb(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mwbb, on_comma)
{
    text txt = create_text();

    append_line(txt, "test, line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "test|, line 1\n";
    output_text += "test line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 4);
    mwbb(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mwbb, on_point)
{
    text txt = create_text();

    append_line(txt, "test line. 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "test line|. 1\n";
    output_text += "test line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 9);
    mwbb(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
