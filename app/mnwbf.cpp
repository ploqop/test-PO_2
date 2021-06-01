/*Программа, переставляющая крсор в начало следующего слова. Дима Курочкин*/

#include <stdio.h>
#include <string.h>
#include "_text.h"


void mnwbf(text txt){
    std::string line = *(txt->cursor->line);
    std::list<std::string>::iterator current = txt->cursor->line;
    int lenght, pos = txt->cursor->position;
/*Ищем место в строке, где после пробела идёт не пробел*/
    while(line[0] != '\0') {
        lenght = line.length();
        for(int i = pos; i <= lenght; i++){
            if ((line[i] == ' ') && (line[i+1] != ' ') && (line[i+1] != '\0')){
                txt->cursor->position = i+1;
                txt->cursor->line = current;
                return;
            }
        }
/*Если в этой строке такого не было, то идём к следующей*/
        current++;
        line = *(current);
        pos = 0;
        if (line[0] != '\0')
            if ((line[0] != ' ') && (line[0] != '\0')){
                txt->cursor->position = 0;
                txt->cursor->line = current;
                return;
            }
    }
    return;
}
