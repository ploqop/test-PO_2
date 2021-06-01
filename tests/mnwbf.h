#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(mnwbf, norm)
{
    text txt = create_text();

    append_line(txt, "line 0\n");
    append_line(txt, "line 1\n");
    append_line(txt, "line 2\n");

    std::string output_text = "";

    output_text += "line |0\n";
    output_text += "line 1\n";
    output_text += "line 2\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 1);
    mnwbf(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mnwbf, next_line)
{
    text txt = create_text();

    append_line(txt, "line 0\n");
    append_line(txt, "line 1\n");
    append_line(txt, "line 2\n");

    std::string output_text = "";

    output_text += "line 0\n";
    output_text += "|line 1\n";
    output_text += "line 2\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 5);
    mnwbf(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}


