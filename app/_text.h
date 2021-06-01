#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <list>

#include "text.h"

typedef struct _node {
    char contents[MAXLINE + 1]; /**< содержимое строки текста */
    struct _node *previous;     /**< указатель на предыдущую строку */
    struct _node *next;         /**< указатель на следующую строку */
} node;


typedef struct _crsr {
    std::list<std::string>::iterator line;         /**< указатель на строку с курсором */
    int line_num;
    int position;               /**< позиция курсора в строке */
} crsr;


typedef struct _list {
    size_t length;              /**< число строк текста */
    std::list<std::string> *myList;
    struct _crsr *cursor;       /**< позиция в тексте, курсор */
} list;

typedef struct _list *text;

#endif
