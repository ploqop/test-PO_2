#ifndef TEXT_H
#define TEXT_H

#include <string>

#define MAXLINE 255


typedef struct _list *text;


typedef struct _crsr *cursor;


text create_text();


void append_line(text txt, std::string contents);



void process_forward(
    text txt,
    void (*process)(int index, std::string contents, int cursor_position, void *data),
    void *data
);


void remove_all(text txt);


int m(text txt, int line_num, int cursor_pos);
void mnwbf(text txt);
void rp(text txt);

#endif
