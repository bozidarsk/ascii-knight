#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>

#include "vectors.h"

int input();
void wait(int ms);
void hidecursor();
void showcursor();
void movecursor(int2 position);
void setbgcolor(uint32_t color); // abgr
void setfgcolor(uint32_t color); // abgr
void clear();
int2 consolesize();

#endif
