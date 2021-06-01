/* Клюшов Никита, 4 вариант*/
/* для удаления текущей строки rc */

#include <iostream>
#include <cstdio>
#include "text.h"
#include "_text.h"


void rc(text txt)
{
  /*передаем итератору адрес строки с курсором*/
  std::list<std::string>::iterator current = txt->cursor->line;

  /*удаляем строку*/
  txt->myList->erase(current);

  m(txt, 0, 0);
}
