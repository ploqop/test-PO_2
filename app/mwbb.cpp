/* Клюшов Никита, 4 вариант*/
/* для перемещения курсора в начало текущего слова, если это возможно mwbb */

#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include "text.h"
#include "_text.h"


void mwbb(text txt)
{
  /*передаем итератору адрес строки с курсором*/
  std::list<std::string>::iterator h = txt->cursor->line;

  /*передаем в s содержимое строки с курсором*/
  std::string s(*h);

  /*выделяем память под массив типа char a*/
  char * a = new char [s.length()];

  /*копируем в а значение строки в типе char*/
  strcpy(a, s.c_str());
  int pos = txt->cursor->position;

  if (pos == 0)
    goto mwbb_exit;

  /* Проверяем, что у нас курсор изначально стоит на каком-то слове */
  if ((isspace(a[pos])) || (a[pos] == '.') || (a[pos] == ',') || (a[pos] == '!') || (a[pos] == '?') )
    goto mwbb_exit;

  /* Ищем в строке букву, перед которой идёт не буква; это и есть наше начало слова */
  for(int i = pos; i > 0; i--)
    {
		if (isspace(a[i-1]))
		  {
		    txt->cursor->position = i;
		    goto mwbb_exit;
		  }
    }

  /* Если мы не нашли начало слова, дойдя до начала строки, то начало строки и есть начало слова */
  txt->cursor->position = 0;
  mwbb_exit:
  delete[] a;
  return;
}
