#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{
    text txt;

    if ((txt = (_list *) malloc(sizeof(_list))) == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    txt = new _list;

    if ((txt->cursor = (_crsr *) malloc(sizeof(_crsr))) == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    txt->myList = new std::list<std::string>();


    txt->cursor->line = txt->myList->end();
    txt->cursor->position = 0;

    return txt;
}
