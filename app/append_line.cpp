#include "_text.h"

void append_line(text txt, std::string contents)
{
    /* Добавляем в конец листа новую строку */ 
    txt->myList->push_back(contents);

    // Указатель курсора ставим на последнюю строку  
    txt->cursor->line = txt->myList->end();
    /* Ставим курсор на последнюю позицию в строке */ 
    txt->cursor->position = contents.length();

    /* Увеличиваем количество строк в листе на единицу */ 
    txt->length++;
}

