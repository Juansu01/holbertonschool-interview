#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

int slide_line(int *line, size_t size, int direction);
void slide(int *line, int index, int placeholder);

#endif
