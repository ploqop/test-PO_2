#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(rc, zero_line)
{
    text txt = create_text();

    append_line(txt, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    append_line(txt, "Aenean sollicitudin magna in metus convallis, vitae dignissim augue tincidunt.\n");
    append_line(txt, "Duis eleifend diam venenatis, ultrices ligula id, ultrices erat.\n");

    std::string output_text = "";

    output_text += "|Aenean sollicitudin magna in metus convallis, vitae dignissim augue tincidunt.\n";
    output_text += "Duis eleifend diam venenatis, ultrices ligula id, ultrices erat.\n";

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

    append_line(txt, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    append_line(txt, "Aenean sollicitudin magna in metus convallis, vitae dignissim augue tincidunt.\n");
    append_line(txt, "Duis eleifend diam venenatis, ultrices ligula id, ultrices erat.\n");

    std::string output_text = "";

    output_text += "|Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
    output_text += "Duis eleifend diam venenatis, ultrices ligula id, ultrices erat.\n";

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

    append_line(txt, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
    append_line(txt, "Aenean sollicitudin magna in metus convallis, vitae dignissim augue tincidunt.\n");
    append_line(txt, "Duis eleifend diam venenatis, ultrices ligula id, ultrices erat.\n");

    std::string output_text = "";

    output_text += "|Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
    output_text += "Aenean sollicitudin magna in metus convallis, vitae dignissim augue tincidunt.\n";

    testing::internal::CaptureStdout();

    m(txt, 2, 0);
    rc(txt);
    show(txt);

    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}
