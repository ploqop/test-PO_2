#include <stdio.h>
#include <assert.h>
#include "common.h"
#include <string.h>
#include "text.h"

static void show_line(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, std::string contents, int cursor, void *data)
{

    UNUSED(index);
    UNUSED(data);


    if(cursor != -1) {
        printf("%.*s|%.*s", cursor, contents.c_str(),(int) contents.length() - cursor, contents.c_str() + cursor);
    } else {
        printf("%s", contents.c_str());
    }
}
