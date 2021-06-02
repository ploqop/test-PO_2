#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(showlenght, normal)
{
    text txt = create_text();

    append_line(txt, "5555\n");
    append_line(txt, "777777\n");
    append_line(txt, "99999999\n");

    std::string output_text = "";

    output_text += "5";
    output_text += "7";
    output_text += "9";

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    showlenght(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(showlenght, empty)
{
     text txt = create_text();

     append_line(txt, "\n");
     append_line(txt, "\n");
     append_line(txt, "\n");

     std::string output_text = "";

     output_text += "1";
     output_text += "1";
     output_text += "1";

     testing::internal::CaptureStdout();

     m(txt, 0, 0);
     showlenght(txt);

     std::string text = testing::internal::GetCapturedStdout();

     EXPECT_STREQ(text.c_str(), output_text.c_str());
}
