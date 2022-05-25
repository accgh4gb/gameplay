#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)

const unsigned int iScreen_X = 21;
const unsigned int iScreen_Y = 6;
unsigned int iHead_X = 2;
unsigned int iHead_Y = iScreen_Y / 2;


int main()
{
	initscr();
	nodelay(stdscr, true);
	echo();
	char ch;
	while(ch != 27)
	{
		clear();

		for(size_t i = 0; i < iScreen_X; i++)
		{
			printw("#");
		}

		printw("\n");
		if(iHead_Y < 0)
		{
			iHead_Y = iScreen_Y;
		}
		else if(iHead_Y >= iScreen_Y)
		{
			iHead_Y = 0; 
		}
				
		for(size_t j = 0; j < iScreen_Y ; j++)
		{
			for(size_t k = 0; k < iScreen_X; k++)
			{
				if(j == iHead_Y && k == iHead_X)
				{
					printw("@");
				}
				else
				{
					printw(" ");
				}
			
			}
		
			printw("\n");
		
		}

		for(size_t i = 0; i < iScreen_X; i++)
		{
			printw("#");
		}
						
		switch(ch = getch())
		{
			case 'W':
			case 'w':
				iHead_Y -= 1;
				break;
			case 's':
			case 'S':
				iHead_Y += 1;
				break;
		}
		
		if(iHead_X == iScreen_X - 1)
		{
			iHead_X = 0;
		}
		else
		{
			iHead_X++;
		}
		refresh();
		msleep(500);
	}
	
	endwin();
	return 0;
}
