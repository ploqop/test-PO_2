/*Программа, удаляющая строчку до той, на которой стоит курсор. Дима Курочкин*/

#include <stdio.h>
#include <string.h>
#include "_text.h"


void rp(text txt) {
    std::list<std::string>::iterator it = txt->myList->begin();
    int i, line = 0;
    std::list<std::string>::iterator current = txt->myList->begin();
/*ищем номер строки, в которой находится курсор*/
    while(current != txt->cursor->line) {
        current++;
        line++;
        it++;
    }
/*Если курсор на первой (нулевой) строке, завершаем работу функции*/
    if (line == 0)
        return;

    it--;
    txt->myList->erase(it--);

    if (line == 1) {
        current = current++;
        txt->myList->begin() = current;
//        it--;
//        txt->myList->erase(it);
        return;
    }
    for (i = 0; i < line-1; i++) {
        if (i == line-2) {
            current++ = (current++)++;
            current = current++;
            current-- = (current--)--;
            return;
        }
        current = current++;
    }
    return;
}
