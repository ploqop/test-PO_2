#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(rc, zero_line)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "|test line 2\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    rc(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rc, first_line)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "|test line 1\n";
    output_text += "test line 3\n";

    testing::internal::CaptureStdout();

    m(txt, 1, 0);
    rc(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rc, second_line)
{
    text txt = create_text();

    append_line(txt, "test line 1\n");
    append_line(txt, "test line 2\n");
    append_line(txt, "test line 3\n");

    std::string output_text = "";

    output_text += "|test line 1\n";
    output_text += "test line 2\n";

    testing::internal::CaptureStdout();

    m(txt, 2, 0);
    rc(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
