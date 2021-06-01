#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>


using namespace std;

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(save, line)
{
    text txt = create_text();

    append_line(txt, "Hello world1");
    append_line(txt, "Hello world2");
    append_line(txt, "Hello world3");

    save(txt, "save.test.txt");

    text txt2 = create_text();

    load(txt2, "save.test.txt");

    EXPECT_EQ(txt->myList->size(), txt2->myList->size());

    string* txt_arr = new string[txt->myList->size()];
    string* txt2_arr = new string[txt2->myList->size()] ;

    copy(txt->myList->begin(), txt->myList->end(), txt_arr);
    copy(txt2->myList->begin(), txt2->myList->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->myList->size(); i++)
    EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

