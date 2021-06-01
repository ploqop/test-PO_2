
#ifndef COMMON_H
#define COMMON_H

#include "text.h"
#include "_text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);



/**

 * Сохраняем содержимое в указанный файл
 */
void save(text txt, char *filename);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

void showlenght(text txt);

#endif
