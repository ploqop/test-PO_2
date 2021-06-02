#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(m, normal)
{
    text txt = create_text();

    txt->myList->push_back("test line 1\n");
    txt->myList->push_back("test line 2\n");
    txt->myList->push_back("test line 3\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 0);
    EXPECT_EQ(txt->cursor->line, txt->myList->begin());
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 2, 5);
    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 5);

    free(txt);
}


TEST(m, non_existent)
{
    text txt = create_text();

    txt->myList->push_back("test line 1\n");
    txt->myList->push_back("test line 2\n");
    txt->myList->push_back("test line 3\n");

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;


    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 0, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 12);

    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 12);

    free(txt);
}
