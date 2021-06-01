#include "_text.h"

void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }

    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        return;
    }

//    /* Текст ненулевой длины должен содержать хотя бы одну строку */
//    assert(!txt->myList->empty());

    /* Очищаем лист */
    txt->myList->clear();
}
