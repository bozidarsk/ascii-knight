#include <stdio.h>

#include "console.h"

#ifdef linux

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>

int input() 
{
	struct termios oldt, newt;
	int flags, x;

	tcgetattr(0, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &newt);

	flags = fcntl(0, F_GETFL, 0);
	fcntl(0, F_SETFL, flags | O_NONBLOCK);

	x = getchar();

	tcsetattr(0, TCSANOW, &oldt);
	fcntl(0, F_SETFL, flags);

	return (x != EOF) ? x : 0;
}

void wait(int ms) { usleep(ms * 1000); }

int2 consolesize() 
{
	struct winsize ws;

	if (ioctl(1, TIOCGWINSZ, &ws))
		fprintf(stderr, "consolesize: ioctl: %i - %s", errno, strerror(errno));

	return i2new(ws.ws_col, ws.ws_row);
}



#elifdef _WIN32

#include <windows.h>

int input() { return _kbhit() ? _getch() : 0; }
void wait(int ms) { Sleep(ms); }

int2 consolesize() 
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	return i2new(
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	);
}


#else
#error "Unsuported platform."
#endif


void hidecursor() { printf("\x1b[?25l"); }
void showcursor() { printf("\x1b[?25h"); }

void movecursor(int2 position) { printf("\x1b[%u;%uH\x1b[%u;%uf", position.y, position.x, position.y, position.x); }

// abgr
void setbgcolor(uint32_t color) { printf("\x1b[48;2;%u;%u;%um", (color >> 0) & 0xff, (color >> 8) & 0xff, (color >> 16) & 0xff); }

// abgr
void setfgcolor(uint32_t color) { printf("\x1b[38;2;%u;%u;%um", (color >> 0) & 0xff, (color >> 8) & 0xff, (color >> 16) & 0xff); }

void clear() { printf("\x1b[H\x1b[2J\x1b[3J"); }
