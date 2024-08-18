#include <iostream>
#include "help.h"
#include <fstream>
#include <chrono>
#include <mmsystem.h>
#include<Windows.h>
#include<ctime>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void removeBox(int box_x, int box_y,int a) // function to remove the spaceship.
{
	if (a == 1)
	{
		myRect(box_x, box_y + 35, box_x + 7.7, box_y + 42, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 7.7, box_y + 35, box_x + 15.4, box_y + 42, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 7.7, box_y + 42, box_x + 15.4, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 15.4, box_y + 35, box_x + 23.1, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 23.1, box_y + 28, box_x + 30.8, box_y + 42, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30.8, box_y + 21, box_x + 38.5, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y + 7, box_x + 46.2, box_y + 56, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y, box_x + 46.2, box_y + 7, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 46.2, box_y + 21, box_x + 53.9, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 53.9, box_y + 28, box_x + 61.6, box_y + 42, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 61.6, box_y + 35, box_x + 69.3, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 69.3, box_y + 42, box_x + 77, box_y + 49, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 69.3, box_y + 35, box_x + 77, box_y + 42, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 77, box_y + 35, box_x + 84.7, box_y + 42, 0, 0, 0, 0, 0, 0);


		myRect(box_x + 23.1, box_y + 63, box_x + 30.8, box_y + 70, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30.8, box_y + 63, box_x + 38.5, box_y + 77, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 84, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 70, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 46.2, box_y + 63, box_x + 53.9, box_y + 77, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 53.9, box_y + 63, box_x + 61.6, box_y + 70, 0, 0, 0, 0, 0, 0);

	}
	if (a == 2)
	{
		myEllipse(box_x - 10, box_y + 60, box_x + 5, box_y + 5, 0, 0, 0, 0, 0, 0);
		myRect(box_x, box_y, box_x + 60, box_y + 80, 0, 0, 0);
		myRect(box_x + 20, box_y + 60, box_x + 40, box_y + 80, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30, box_y + 18, box_x + 60, box_y + 40, 0, 0, 0, 0, 0, 0);
	}
	if (a == 3)
	{
		myRect(box_x, box_y + 26, box_x + 9, box_y + 32.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x, box_y + 32.5, box_x + 9, box_y + 39, 0, 0, 0, 0, 0, 0);
		myRect(box_x, box_y + 39, box_x + 9, box_y + 52, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 9, box_y + 39, box_x + 18, box_y + 45.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 9, box_y + 45.5, box_x + 36, box_y + 52, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 9, box_y + 52, box_x + 18, box_y + 58.5, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 18, box_y + 13, box_x + 27, box_y + 19.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 19.5, box_x + 27, box_y + 26, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 26, box_x + 63, box_y + 32.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 32.5, box_x + 27, box_y + 39, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 39, box_x + 27, box_y + 45.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 52, box_x + 63, box_y + 58.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 18, box_y + 58.5, box_x + 36, box_y + 65, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 27, box_y + 32, box_x + 36, box_y + 51.5, 0, 0, 0, 0, 0, 0);//



		myRect(box_x + 36, box_y, box_x + 45, box_y + 6.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 36, box_y + 6.5, box_x + 45, box_y + 13, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 36, box_y + 13, box_x + 45, box_y + 26, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 36, box_y + 32.5, box_x + 45, box_y + 45.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 36, box_y + 45.5, box_x + 45, box_y + 52, 0, 0, 0, 0, 0, 0);
		//
		myRect(box_x + 45, box_y + 32, box_x + 54, box_y + 51.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 45, box_y + 58.5, box_x + 63, box_y + 65, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 54, box_y + 13, box_x + 63, box_y + 19.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 54, box_y + 19.5, box_x + 63, box_y + 26, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 54, box_y + 32.5, box_x + 63, box_y + 39, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 54, box_y + 39, box_x + 63, box_y + 45.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 54, box_y + 45.5, box_x + 72, box_y + 51, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 63, box_y + 52, box_x + 72, box_y + 58.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 63, box_y + 39, box_x + 72, box_y + 45.5, 0, 0, 0, 0, 0, 0);//

		myRect(box_x + 72, box_y + 26, box_x + 81, box_y + 32.5, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 72, box_y + 32.5, box_x + 81, box_y + 39, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 72, box_y + 39, box_x + 81, box_y + 52, 0, 0, 0, 0, 0, 0);//


		myRect(box_x + 23.1, box_y + 68, box_x + 30.8, box_y + 75, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30.8, box_y + 68, box_x + 38.5, box_y + 82, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 89, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 75, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 46.2, box_y + 68, box_x + 53.9, box_y + 82, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 53.9, box_y + 68, box_x + 61.6, box_y + 75, 0, 0, 0, 0, 0, 0);

	}
}
void drawBox(int box_x, int box_y,int a) //function to draw the spaceship.
{
	if (a == 1)
	{
		myRect(box_x, box_y + 35, box_x + 7.7, box_y + 42, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 7.7, box_y + 35, box_x + 15.4, box_y + 42, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 7.7, box_y + 42, box_x + 15.4, box_y + 49, 220, 0, 0, 220, 0, 0);//

		myRect(box_x + 15.4, box_y + 35, box_x + 23.1, box_y + 49, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 15.4, box_y + 42, box_x + 23.1, box_y + 49, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 23.1, box_y + 28, box_x + 30.8, box_y + 42, 60, 60, 60, 60, 60, 60);//

		myRect(box_x + 30.8, box_y + 21, box_x + 38.5, box_y + 49, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 30.8, box_y + 28, box_x + 38.5, box_y + 42, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 38.5, box_y + 7, box_x + 46.2, box_y + 56, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 38.5, box_y + 42, box_x + 46.2, box_y + 49, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 38.5, box_y + 7, box_x + 46.2, box_y + 21, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 38.5, box_y, box_x + 46.2, box_y + 7, 255, 215, 0, 255, 215, 0);//

		myRect(box_x + 46.2, box_y + 21, box_x + 53.9, box_y + 49, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 46.2, box_y + 28, box_x + 53.9, box_y + 42, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 53.9, box_y + 28, box_x + 61.6, box_y + 42, 60, 60, 60, 60, 60, 60);//

		myRect(box_x + 61.6, box_y + 35, box_x + 69.3, box_y + 49, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 61.6, box_y + 42, box_x + 69.3, box_y + 49, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 69.3, box_y + 42, box_x + 77, box_y + 49, 220, 0, 0, 220, 0, 0);
		myRect(box_x + 69.3, box_y + 35, box_x + 77, box_y + 42, 60, 60, 60, 60, 60, 60);//

		myRect(box_x + 77, box_y + 35, box_x + 84.7, box_y + 42, 100, 100, 100, 100, 100, 100);//


		myRect(box_x + 23.1, box_y + 63, box_x + 30.8, box_y + 70, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 30.8, box_y + 63, box_x + 38.5, box_y + 77, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 84, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 70, 255, 69, 0, 255, 69, 0);//
		myRect(box_x + 46.2, box_y + 63, box_x + 53.9, box_y + 77, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 53.9, box_y + 63, box_x + 61.6, box_y + 70, 255, 215, 0, 255, 215, 0);//

	}
	if (a == 2)
	{
		myEllipse(box_x - 10, box_y + 60, box_x + 5, box_y + 5, 179, 0, 0, 179, 0, 0);
		myRect(box_x, box_y, box_x + 60, box_y + 80, 0, 0, 0, 179, 0, 0);
		myRect(box_x + 20, box_y + 60, box_x + 40, box_y + 80, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30, box_y + 18, box_x + 60, box_y + 40, 0, 0, 0, 5, 111, 216);
	}
	if (a == 3)
	{
		myRect(box_x, box_y + 26, box_x + 9, box_y + 32.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x, box_y + 32.5, box_x + 9, box_y + 39, 30, 30, 30, 30, 30, 30);
		myRect(box_x, box_y + 39, box_x + 9, box_y + 52, 60, 60, 60, 60, 60, 60);//

		myRect(box_x + 9, box_y + 39, box_x + 18, box_y + 45.5, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 9, box_y + 45.5, box_x + 36, box_y + 52, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 9, box_y + 52, box_x + 18, box_y + 58.5, 220, 0, 0, 220, 0, 0);//

		myRect(box_x + 18, box_y + 13, box_x + 27, box_y + 19.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 18, box_y + 19.5, box_x + 27, box_y + 26, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 18, box_y + 26, box_x + 63, box_y + 32.5, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 18, box_y + 32.5, box_x + 27, box_y + 39, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 18, box_y + 39, box_x + 27, box_y + 45.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 18, box_y + 52, box_x + 63, box_y + 58.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 18, box_y + 58.5, box_x + 36, box_y + 65, 30, 30, 30, 30, 30, 30);//


		myRect(box_x + 27, box_y + 32, box_x + 36, box_y + 51.5, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 36, box_y, box_x + 45, box_y + 6.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 36, box_y + 6.5, box_x + 45, box_y + 13, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 36, box_y + 13, box_x + 45, box_y + 26, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 36, box_y + 32.5, box_x + 45, box_y + 45.5, 80, 80, 80, 80, 80, 80);
		myRect(box_x + 36, box_y + 45.5, box_x + 45, box_y + 52, 30, 30, 30, 30, 30, 30);//
		//

		myRect(box_x + 45, box_y + 32, box_x + 54, box_y + 51.5, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 45, box_y + 58.5, box_x + 63, box_y + 65, 30, 30, 30, 30, 30, 30);//

		myRect(box_x + 54, box_y + 13, box_x + 63, box_y + 19.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 54, box_y + 19.5, box_x + 63, box_y + 26, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 54, box_y + 32.5, box_x + 63, box_y + 39, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 54, box_y + 39, box_x + 63, box_y + 45.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 54, box_y + 45.5, box_x + 72, box_y + 51, 100, 100, 100, 100, 100, 100);//

		myRect(box_x + 63, box_y + 52, box_x + 72, box_y + 58.5, 220, 0, 0, 220, 0, 0);
		myRect(box_x + 63, box_y + 39, box_x + 72, box_y + 45.5, 60, 60, 60, 60, 60, 60);//

		myRect(box_x + 72, box_y + 26, box_x + 81, box_y + 32.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 72, box_y + 32.5, box_x + 81, box_y + 39, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 72, box_y + 39, box_x + 81, box_y + 52, 60, 60, 60, 60, 60, 60);//


		myRect(box_x + 23.1, box_y + 68, box_x + 30.8, box_y + 75, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 30.8, box_y + 68, box_x + 38.5, box_y + 82, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 89, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 75, 255, 69, 0, 255, 69, 0);//
		myRect(box_x + 46.2, box_y + 68, box_x + 53.9, box_y + 82, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 53.9, box_y + 68, box_x + 61.6, box_y + 75, 255, 215, 0, 255, 215, 0);//


	}
	
}
void drawlife1() //function to draw the hearts on the top of the screen.
{
	myEllipse(1700, 5, 1720, 28, 255, 0, 0,255,0,0); // Left ellipse
	myEllipse(1720, 5, 1741, 28, 255, 0, 0,255,0,0); // Right ellipse

	myTriangle(1700, 20, 1740, 20, 1720, 40, 255, 0, 0,255,0,0);
}
void removelife1() //remove the life .
{
	myEllipse(1700, 5, 1720, 28, 0, 0, 0, 0, 0, 0); // Left ellipse
	myEllipse(1720, 5, 1741, 28, 0, 0, 0, 0, 0, 0); // Right ellipse

	myTriangle(1700, 20, 1740, 20, 1720, 40, 0, 0, 0, 0, 0, 0);
}
void drawlife2()
{
	myEllipse(1750, 5, 1770, 28, 255, 0, 0, 255, 0, 0); // Left ellipse
	myEllipse(1770, 5, 1791, 28, 255, 0, 0, 255, 0, 0); // Right ellipse

	myTriangle(1750, 20, 1790, 20, 1770, 40, 255, 0, 0, 255, 0, 0);
}
void removelife2()
{
	myEllipse(1750, 5, 1770, 28, 0, 0, 0, 0, 0, 0); // Left ellipse
	myEllipse(1770, 5, 1791, 28, 0, 0, 0, 0, 0, 0); // Right ellipse

	myTriangle(1750, 20, 1790, 20, 1770, 40, 0, 0, 0, 0, 0, 0);
}
void drawlife3()
{
	myEllipse(1800, 5, 1820, 28, 255, 0, 0, 255, 0, 0); // Left ellipse
	myEllipse(1820, 5, 1841, 28, 255, 0, 0, 255, 0, 0); // Right ellipse

	myTriangle(1800, 20, 1840, 20, 1820, 40, 255, 0, 0, 255, 0, 0);
}
void removelife3()
{
	myEllipse(1800, 5, 1820, 28, 0, 0, 0, 0, 0, 0); // Left ellipse
	myEllipse(1820, 5, 1841, 28, 0, 0, 0, 0, 0, 0); // Right ellipse

	myTriangle(1800, 20, 1840, 20, 1820, 40, 0, 0, 0, 0, 0, 0);
}
void drawenemy(int x, int y) //for drawing the shapes of the enemies.
{
	myRect(x, y + 42, x + 7.5, y + 73.5, 0, 204, 0, 0, 204, 0);//

	myRect(x + 7.5, y + 31.5, x + 15, y + 52.5, 0, 204, 0, 0, 204, 0);//

	myRect(x + 15, y, x + 22.5, y + 10.5, 0, 204, 0, 0, 204, 0);
	myRect(x + 15, y + 21, x + 22.5, y + 74.5, 0, 204, 0, 0, 204, 0);//

	myRect(x + 22.5, y + 10.5, x + 30, y + 31.5, 0, 204, 0, 0, 204, 0);
	myRect(x + 22.5, y + 42, x + 30, y + 63, 0, 204, 0, 0, 204, 0);

	myRect(x + 22.5, y + 73.5, x + 37.5, y + 84, 0, 204, 0, 0, 204, 0);//

	myRect(x + 30, y + 21, x + 37.5, y + 63, 0, 204, 0, 0, 204, 0);//

	myRect(x + 37.5, y + 21, x + 45, y + 63, 0, 204, 0, 0, 204, 0);//

	myRect(x + 45, y + 21, x + 52.5, y + 63, 0, 204, 0, 0, 204, 0);
	myRect(x + 45, y + 73.5, x + 60, y + 84, 0, 204, 0, 0, 204, 0);//

	myRect(x + 52.5, y + 10.5, x + 60, y + 31.5, 0, 204, 0, 0, 204, 0);
	myRect(x + 52.5, y + 42, x + 60, y + 63, 0, 204, 0, 0, 204, 0);//

	myRect(x + 60, y, x + 68, y + 10.5, 0, 204, 0, 0, 204, 0);
	myRect(x + 60, y + 21, x + 68, y + 73.5, 0, 204, 0, 0, 204, 0);//

	myRect(x + 68, y + 31.5, x + 76, y + 52.5, 0, 204, 0, 0, 204, 0);//

	myRect(x + 76, y + 42, x + 83.5, y + 73.5, 0, 204, 0, 0, 204, 0);//
	
}
void removeenemy(int x, int y) //for removing the enemies.
{
	myRect(x, y + 42, x + 7.5, y + 73.5, 0, 0, 0, 0, 0, 0);//

	myRect(x + 7.5, y + 31.5, x + 15, y + 52.5, 0, 0, 0, 0, 0);//

	myRect(x + 15, y, x + 22.5, y + 10.5, 0, 0, 0, 0);
	myRect(x + 15, y + 21, x + 22.5, y + 74.5, 0, 0, 0,  0);//

	myRect(x + 22.5, y + 10.5, x + 30, y + 31.5, 0, 0, 0,  0);
	myRect(x + 22.5, y + 42, x + 30, y + 63, 0,  0, 0,  0);

	myRect(x + 22.5, y + 73.5, x + 37.5, y + 84, 0, 0, 0,  0);//

	myRect(x + 30, y + 21, x + 37.5, y + 63, 0,  0, 0, 0);//

	myRect(x + 37.5, y + 21, x + 45, y + 63, 0,  0, 0, 0);//

	myRect(x + 45, y + 21, x + 52.5, y + 63, 0, 0, 0, 0);
	myRect(x + 45, y + 73.5, x + 60, y + 84, 0, 0, 0, 0);//

	myRect(x + 52.5, y + 10.5, x + 60, y + 31.5, 0, 0, 0, 0);
	myRect(x + 52.5, y + 42, x + 60, y + 63, 0, 0, 0, 0);//

	myRect(x + 60, y, x + 68, y + 10.5, 0, 0, 0, 0);
	myRect(x + 60, y + 21, x + 68, y + 73.5, 0, 0, 0, 0);//

	myRect(x + 68, y + 31.5, x + 76, y + 52.5, 0, 0, 0, 0);//

	myRect(x + 76, y + 42, x + 83.5, y + 73.5, 0, 0, 0, 0);//
}
void drawfire(int box_x, int box_y,int fireheight) //for drawing the bullet of spaceship.
{
	myEllipse(box_x+25, fireheight, box_x+35 , fireheight-30 , 0, 255, 255, 255, 255, 255);
}
void removefire(int box_x, int box_y, int fireheight) //for removing spaceship bullet
{
	myEllipse(box_x + 25, fireheight, box_x + 35, fireheight - 30, 0, 0, 0);
}
void drawenmyfire(int enemy_x, int fireheight)
{
	myEllipse(enemy_x + 25, fireheight, enemy_x + 35, fireheight + 30, 0, 255, 255, 255, 255, 255);
}
void removeenmyfire(int enemy_x, int fireheight)
{
	myEllipse(enemy_x + 25, fireheight, enemy_x + 35, fireheight + 30, 0, 0, 0, 0, 0, 0);
}

void removeBar(int box_x, int box_y)//removing bars of the main menu.
{
	myRect(box_x, box_y, box_x + 25, box_y + 30, 0, 0, 0);
}
void drawBar(int box_x, int box_y)//drawing the bars of the mainmenu.
{
	myRect(box_x, box_y, box_x + 25, box_y + 25, 226, 80, 128, 226, 80, 128);
}

void bar(int barx, int &bary, int l) //
{
	drawBar(barx, bary);
	if (bary > l)
		bary -= 2;
	drawBar(barx, bary);
}
void bar2(int barx, int& bary, int l)
{
	
	if (bary > l)
	{
		bary -= 2;	
	}

	removeBar(barx, bary);
}

bool checkCollision(int bullet_x, int bullet_y, int enemy_x, int enemy_y) //checks the collision of two entities in the game and returns true if collision occurs.
{
	if (bullet_x >= enemy_x-40 && bullet_x <= enemy_x + 60 && bullet_y >= enemy_y-90 && bullet_y <= enemy_y + 90)
	{
		return true;

	}
	  return false;
}
int main()
{
	Sleep(25);
    PlaySound(TEXT("menu.wav"),NULL ,SND_FILENAME|SND_ASYNC);
	int left_limit = 20, right_limit = 1800, top_limit = 50, bottom_limit = 820;
	int box_x = 900, box_y = 770, step_size = 20, step_size2 = 15;
	int fire_x = 0, fire_y = 0;
	char direction = ' ';
	char fire_direction = ' ';
	int pausecheck = 0;
	bool gamequit = true;
	bool loop = true;
	bool mainmenu1 = true;
	bool mainmenu2 = true;
	bool shipselect = true;
	int ship = 0;
	int fireheight = 0;
	int interval = 0;
	int enemystep = 0;
	int point = 0;
	int lives = 3;
	bool destroy = false;
	int highscore1 = 200;
	int highscore2 = 150;
	int highscore3 = 100;
	int highscore4 = 80;
	int highscore5 = 50;
	


	ofstream write;
	ifstream read;

	read.open("highscore.txt");
	read >> highscore1;
	read >> highscore2;
	read >> highscore3;
	read >> highscore4;
	read >> highscore5;
	read.close();
		


	myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 226, 80, 128);//outer rectangle and boundary
	drawText(50, 600, 100, 0, 255, 0, "Space Invaders !");
	drawText(22, 600, 300, 0, 255, 0, "             Continue");
	drawText(22, 600, 400, 0, 255, 0, "             New Game");
	drawText(22, 580, 500, 0, 255, 0, "             Highscores");
	drawText(22, 590, 600, 0, 255, 0, "             Quit Game");
	int enemytime = 0;
	int whichKey = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	bool border = true;
	int barx = 30;
	int bary[100];
	bool newgame = false;
	bool check = false;
	int x = 250, y = 60;
	int score = 0;
	int iteration = 0;
	//for the movement of enemies.
	int enemydirection = 1;
	struct enemy //for making enemies.
	{
		int enemy_x=0;
		int enemy_y=0;
		bool status =true;
	};
	enemy s[50];

	

	for (int i = 0, j = 867; i < 100; i++)//for main menu bars.
	{
		bary[i] = j;
	}
	while (border = true) // this while loop is fr the animated bars in  the main menu.
	{
		bar(barx, bary[0], 100);
		bar(barx + 40, bary[1], 420);//
		bar(barx + 80, bary[2], 320);//
		bar(barx + 120, bary[3], 420);//
		bar(barx + 160, bary[4], 520);//
		bar(barx + 200, bary[5], 620);//
		bar(barx + 240, bary[6], 380);//
		bar(barx + 280, bary[7], 300);//
		bar(barx + 320, bary[8], 360);//
		bar(barx + 360, bary[9], 420);//
		bar(barx + 400, bary[10], 500);//
		bar(barx + 440, bary[11], 580);//
		bar(barx + 480, bary[12], 600);//
		bar(barx + 520, bary[13], 610);//
		bar(barx + 560, bary[14], 580);//
		bar(barx + 600, bary[15], 530);//
		bar(barx + 640, bary[16], 500);//
		bar(barx + 680, bary[17], 600);//
		bar(barx + 720, bary[18], 680);//
		bar(barx + 760, bary[19], 580);//
		bar(barx + 800, bary[20], 780);
		bar(barx + 840, bary[21], 700);
		bar(barx + 880, bary[20], 780);
		bar(barx + 920, bary[21], 780);
		bar(barx + 960, bary[20], 780);
		bar(barx + 1000, bary[21], 780);
		bar(barx + 1040, bary[20], 780);
		bar(barx + 1080, bary[19], 580);
		bar(barx + 1120, bary[18], 680);
		bar(barx + 1160, bary[17], 600);
		bar(barx + 1200, bary[15], 530);
		bar(barx + 1240, bary[14], 580);
		bar(barx + 1280, bary[14], 580);
		bar(barx + 1320, bary[12], 600);
		bar(barx + 1360, bary[11], 580);
		bar(barx + 1400, bary[9], 420);
		bar(barx + 1440, bary[8], 360);
		bar(barx + 1480, bary[7], 300);
		bar(barx + 1520, bary[6], 380);
		bar(barx + 1560, bary[5], 620);
		bar(barx + 1600, bary[4], 520);
		bar(barx + 1640, bary[3], 420);
		bar(barx + 1680, bary[2], 320);
		bar(barx + 1720, bary[1], 420);
		bar(barx + 1760, bary[0], 300);
		if (bary[0] <= 300)
		{
			break;
		}
	}
	while (mainmenu1)
	{
	jump:
		
		if (isKeyPressed(whichKey)) // isKeyPressed function returns true if a key is pressed and whichKey tells that which key was pressed.
		{
			if (whichKey == 5 && choice2 == 1)// 5 whichkey is enter and choice occurs when up or down key is changed. 
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
				whichKey = 0;
				drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
				drawText(22, 600, 300, 0, 0, 0, "             Continue");
				drawText(22, 600, 400, 0, 0, 0, "             New Game");
				drawText(22, 590, 600, 0, 0, 0, "             Quit Game");
				drawText(22, 580, 500, 0, 0, 0, "             Highscores");

				read.open("save.txt"); //for reading the variables of saved game.
				read >> box_x;
				read >> box_y;
				read >> score ;
				read >> enemystep;
				read >> interval;
				read >> enemydirection;
				read >> lives;
				read >> point;
				read >> ship;
				for (int i = 0; i < 50; i++)
				{
					read >> s[i].enemy_x;
					read >> s[i].enemy_y;
					read >> s[i].status;
				}
				read.close();

				break;
			}
			if (whichKey == 5 && choice2 == 2)
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
				whichKey = 0;
				drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
				drawText(22, 600, 300, 0, 0, 0, "             Continue");
				drawText(22, 600, 400, 0, 0, 0, "             New Game");
				drawText(22, 590, 600, 0, 0, 0, "             Quit Game");
				drawText(22, 580, 500, 0, 0, 0, "             Highscores");

				newgame = true; // for starting a new game.
				lives = 3;
				break;
			}
			if (whichKey == 5 && choice2 == 3) // representing the highscores.
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
				whichKey = 0;
				drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
				drawText(22, 600, 300, 0, 0, 0, "             Continue");
				drawText(22, 600, 400, 0, 0, 0, "             New Game");
				drawText(22, 590, 600, 0, 0, 0, "             Quit Game");
				drawText(22, 580, 500, 0, 0, 0, "             Highscores");
				drawText(22, 700, 100, 0, 255, 0, "Highscore 1");
				drawText(22, 700, 200, 0, 255, 0, "Highscore 2");
				drawText(22, 700, 300, 0, 255, 0, "Highscore 3");
				drawText(22, 700, 400, 0, 255, 0, "Highscore 4");
				drawText(22, 700, 500, 0, 255, 0, "Highscore 5");

				drawText(22, 1100, 100, 0, 255, 0, "", true, highscore1);
				drawText(22, 1100, 200, 0, 255, 0, "", true, highscore2);
				drawText(22, 1100, 300, 0, 255, 0, "", true, highscore3);
				drawText(22, 1100, 400, 0, 255, 0, "", true, highscore4);
				drawText(22, 1100, 500, 0, 255, 0, "", true, highscore5);

				
				while (1)
				{
					isKeyPressed(whichKey);
					
						if (whichKey == 7)
						{
							whichKey = 0;
							break;
						}
					
				}
				drawText(22, 700, 100, 0, 0, 0, "Highscore 1");
				drawText(22, 700, 200, 0, 0, 0, "Highscore 2");
				drawText(22, 700, 300, 0, 0, 0, "Highscore 3");
				drawText(22, 700, 400, 0, 0, 0, "Highscore 4");
				drawText(22, 700, 500, 0, 0, 0, "Highscore 5");

				drawText(22, 1100, 100, 0, 0, 0, "", true, highscore1);
				drawText(22, 1100, 200, 0, 0, 0, "", true, highscore2);
				drawText(22, 1100, 300, 0, 0, 0, "", true, highscore3);
				drawText(22, 1100, 400, 0, 0, 0, "", true, highscore4);
				drawText(22, 1100, 500, 0, 0, 0, "", true, highscore5);
				drawText(50, 600, 100, 0, 255, 0, "Space Invaders !");
				drawText(22, 600, 300, 0, 255, 0, "             Continue");
				drawText(22, 600, 400, 0, 255, 0, "             New Game");
				drawText(22, 580, 500, 0, 255, 0, "             Highscores");
				drawText(22, 590, 600, 0, 255, 0, "             Quit Game");
				
				goto jump;
				break;
			}
			if (whichKey == 5 && choice2 == 4) // for quiting the game.
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
				whichKey = 0;
				drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
				drawText(22, 600, 300, 0, 0, 0, "             Continue");
				drawText(22, 600, 400, 0, 0, 0, "             New Game");
				drawText(22, 590, 600, 0, 0, 0, "             Quit Game");
				drawText(22, 580, 500, 0, 0, 0, "             Highscores");

				gamequit = false;
				break;
			}
			
			if (whichKey == 4)
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);

				choice1++;
				whichKey = 0;
				
			}
			if (whichKey == 2)
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
				choice1--;
				whichKey = 0;
			}
			if (choice1 < 1)
			{
				choice1 = 1;
			}
			if (choice1 > 4)
			{
				choice1 = 4;
			}
				if (choice1 == 1) // same commands but for up key.
				{
					drawText(22, 600, 300, 255, 255, 255, "             Continue");
					drawText(22, 600, 400, 0, 255, 0, "             New Game");
					drawText(22, 580, 500, 0, 255, 0, "             Highscores");
					drawText(22, 590, 600, 0, 255, 0, "             Quit Game");
					choice2 = 1;
				}
				if (choice1 == 2)

				{
					drawText(22, 600, 300, 0, 255, 0, "             Continue");
					drawText(22, 600, 400, 255, 255, 255, "             New Game");
					drawText(22, 580, 500, 0, 255, 0, "             Highscores");
					drawText(22, 590, 600, 0, 255, 0, "             Quit Game");
					choice2 = 2;
				}
				if (choice1 == 3)
				{
					drawText(22, 600, 300, 0, 255, 0, "             Continue");
					drawText(22, 600, 400, 0, 255, 0, "             New Game");
					drawText(22, 580, 500, 255, 255, 255, "             Highscores");
					drawText(22, 590, 600, 0, 255, 0, "             Quit Game");
					choice2 = 3;
				}
				if (choice1 == 4)
				{
					drawText(22, 600, 300, 0, 255, 0, "             Continue");
					drawText(22, 600, 400, 0, 255, 0, "             New Game");
					drawText(22, 590, 600, 255, 255, 255, "             Quit Game");
					drawText(22, 580, 500, 0, 255, 0, "             Highscores");

					choice2 = 4;
				}
		}

	}


	//
	//code for difficulty select screen.
	if (gamequit != false)
	{
		//myRect(left_limit - 6, top_limit - 6, right_limit + 45, bottom_limit + 75, 226, 80, 128);
		drawText(50, 600, 100, 0, 255, 0, "Space Invaders !");
		drawText(22, 620, 300, 0, 255, 0, "  Please Select the Difficulty");
		drawText(22, 620, 400, 0, 255, 0, "             Easy");
		drawText(22, 620, 500, 0, 255, 0, "             Hard");

		bar2(barx, bary[0], 120); //for lowerring the bars a bit in the second menu.
		bar2(barx + 40, bary[1], 440);
		bar2(barx + 80, bary[2], 340);
		bar2(barx + 120, bary[3], 440);
		bar2(barx + 160, bary[4], 540);
		bar2(barx + 200, bary[5], 640);
		bar2(barx + 240, bary[6], 400);
		bar2(barx + 280, bary[7], 320);
		bar2(barx + 320, bary[8], 380);
		bar2(barx + 360, bary[9], 440);
		bar2(barx + 400, bary[10], 520);
		bar2(barx + 440, bary[11], 600);
		bar2(barx + 480, bary[12], 620);
		bar2(barx + 520, bary[13], 630);
		bar2(barx + 560, bary[14], 600);
		bar2(barx + 600, bary[15], 550);
		bar2(barx + 640, bary[16], 520);
		bar2(barx + 680, bary[17], 620);
		bar2(barx + 720, bary[18], 700);
		bar2(barx + 760, bary[19], 600);
		bar2(barx + 800, bary[20], 800);
		bar2(barx + 840, bary[21], 720);
		bar2(barx + 880, bary[20], 800);
		bar2(barx + 920, bary[21], 800);
		bar2(barx + 960, bary[20], 800);
		bar2(barx + 1000, bary[21], 800);
		bar2(barx + 1040, bary[20], 800);
		bar2(barx + 1080, bary[19], 600);
		bar2(barx + 1120, bary[18], 700);
		bar2(barx + 1160, bary[17], 620);
		bar2(barx + 1200, bary[15], 550);
		bar2(barx + 1240, bary[14], 600);
		bar2(barx + 1280, bary[14], 600);
		bar2(barx + 1320, bary[12], 620);
		bar2(barx + 1360, bary[11], 600);
		bar2(barx + 1400, bary[9], 440);
		bar2(barx + 1440, bary[8], 380);
		bar2(barx + 1480, bary[7], 320);
		bar2(barx + 1520, bary[6], 400);
		bar2(barx + 1560, bary[5], 640);
		bar2(barx + 1600, bary[4], 540);
		bar2(barx + 1640, bary[3], 440);
		bar2(barx + 1680, bary[2], 340);
		bar2(barx + 1720, bary[1], 440);
		bar2(barx + 1760, bary[0], 320);
		whichKey = 0;
		choice1 = 0;
		choice2 = 0;
		while (mainmenu2)
		{
			if (isKeyPressed(whichKey)) // isKeyPressed function returns true if a key is pressed and whichKey tells that which key was pressed.
			{
				if (whichKey == 5 && choice2 == 1) //same logic for highlighting as in first main menu.
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					whichKey = 0;
					drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
					drawText(22, 620, 300, 0, 0, 0, "  Please Select the Difficulty");
					drawText(22, 620, 400, 0, 0, 0, "             Easy");
					drawText(22, 620, 500, 0, 0, 0, "             Hard");
					enemystep = 20;
					enemytime = 25;
					break;
				}
				if (whichKey == 5 && choice2 == 2)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					whichKey = 0;
					drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
					drawText(22, 620, 300, 0, 0, 0, "  Please Select the Difficulty");
					drawText(22, 620, 400, 0, 0, 0, "             Easy");
					drawText(22, 620, 500, 0, 0, 0, "             Hard");
					enemystep = 40;
					enemytime = 10;
					break;
				}
				if (whichKey == 4)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
					choice1++;
					whichKey = 0;
					if (choice1 == 1)
					{
						drawText(22, 620, 400, 255, 255, 255, "             Easy");
						drawText(22, 620, 500, 0, 255, 0, "             Hard");
						choice2 = 1;
					}
					if (choice1 == 2)

					{
						drawText(22, 620, 400, 0, 255, 0, "             Easy");
						drawText(22, 620, 500, 255, 255, 255, "             Hard");
						choice2 = 2;
					}
				}
				if (whichKey == 2)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
					choice1--;
					whichKey = 0;
					if (choice1 == 1)
					{
						drawText(22, 620, 400, 255, 255, 255, "             Easy");
						drawText(22, 620, 500, 0, 255, 0, "             Hard");
						choice2 = 1;
					}
					if (choice1 == 2)

					{
						drawText(22, 620, 400, 0, 255, 0, "             Easy");
						drawText(22, 620, 500, 255, 255, 255, "             Hard");
						choice2 = 2;
					}
				}

			}

		}
		
		whichKey = 0;
		choice1 = 1;
		choice2 = 1;
		myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 226, 80, 128);//outer rectangle and boundary
		box_x = 800;
		box_y = 700;
		drawText(50, 600, 100, 0, 0, 0, "Space Invaders !");
		drawText(22, 620, 300, 0, 0, 0, "  Please Select the Difficulty");
		drawText(22, 620, 400, 0, 0, 0, "             Easy");
		drawText(22, 620, 500, 0, 0, 0, "             Hard");

		//first star ship.
		box_x = 700;
		myRect(box_x, box_y + 35, box_x + 7.7, box_y + 42, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 7.7, box_y + 35, box_x + 15.4, box_y + 42, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 7.7, box_y + 42, box_x + 15.4, box_y + 49, 220, 0, 0, 220, 0, 0);//
		myRect(box_x + 15.4, box_y + 35, box_x + 23.1, box_y + 49, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 15.4, box_y + 42, box_x + 23.1, box_y + 49, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 23.1, box_y + 28, box_x + 30.8, box_y + 42, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 30.8, box_y + 21, box_x + 38.5, box_y + 49, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 30.8, box_y + 28, box_x + 38.5, box_y + 42, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 38.5, box_y + 7, box_x + 46.2, box_y + 56, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 38.5, box_y + 42, box_x + 46.2, box_y + 49, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 38.5, box_y + 7, box_x + 46.2, box_y + 21, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 38.5, box_y, box_x + 46.2, box_y + 7, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 46.2, box_y + 21, box_x + 53.9, box_y + 49, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 46.2, box_y + 28, box_x + 53.9, box_y + 42, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 53.9, box_y + 28, box_x + 61.6, box_y + 42, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 61.6, box_y + 35, box_x + 69.3, box_y + 49, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 61.6, box_y + 42, box_x + 69.3, box_y + 49, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 69.3, box_y + 42, box_x + 77, box_y + 49, 220, 0, 0, 220, 0, 0);
		myRect(box_x + 69.3, box_y + 35, box_x + 77, box_y + 42, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 77, box_y + 35, box_x + 84.7, box_y + 42, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 23.1, box_y + 63, box_x + 30.8, box_y + 70, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 30.8, box_y + 63, box_x + 38.5, box_y + 77, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 84, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 38.5, box_y + 63, box_x + 46.2, box_y + 70, 255, 69, 0, 255, 69, 0);//
		myRect(box_x + 46.2, box_y + 63, box_x + 53.9, box_y + 77, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 53.9, box_y + 63, box_x + 61.6, box_y + 70, 255, 215, 0, 255, 215, 0);//

		//second amogus ship.
		box_x = 900;
		myEllipse(box_x - 10, box_y + 60, box_x + 5, box_y + 5, 179, 0, 0, 179, 0, 0);
		myRect(box_x, box_y, box_x + 60, box_y + 80, 0, 0, 0, 179, 0, 0);
		myRect(box_x + 20, box_y + 60, box_x + 40, box_y + 80, 0, 0, 0, 0, 0, 0);
		myRect(box_x + 30, box_y + 18, box_x + 60, box_y + 40, 0, 0, 0, 5, 111, 216);

		//third starship.
		box_x = 1100;
		myRect(box_x, box_y + 26, box_x + 9, box_y + 32.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x, box_y + 32.5, box_x + 9, box_y + 39, 30, 30, 30, 30, 30, 30);
		myRect(box_x, box_y + 39, box_x + 9, box_y + 52, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 9, box_y + 39, box_x + 18, box_y + 45.5, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 9, box_y + 45.5, box_x + 36, box_y + 52, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 9, box_y + 52, box_x + 18, box_y + 58.5, 220, 0, 0, 220, 0, 0);//
		myRect(box_x + 18, box_y + 13, box_x + 27, box_y + 19.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 18, box_y + 19.5, box_x + 27, box_y + 26, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 18, box_y + 26, box_x + 63, box_y + 32.5, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 18, box_y + 32.5, box_x + 27, box_y + 39, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 18, box_y + 39, box_x + 27, box_y + 45.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 18, box_y + 52, box_x + 63, box_y + 58.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 18, box_y + 58.5, box_x + 36, box_y + 65, 30, 30, 30, 30, 30, 30);//
		myRect(box_x + 27, box_y + 32, box_x + 36, box_y + 51.5, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 36, box_y, box_x + 45, box_y + 6.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 36, box_y + 6.5, box_x + 45, box_y + 13, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 36, box_y + 13, box_x + 45, box_y + 26, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 36, box_y + 32.5, box_x + 45, box_y + 45.5, 80, 80, 80, 80, 80, 80);
		myRect(box_x + 36, box_y + 45.5, box_x + 45, box_y + 52, 30, 30, 30, 30, 30, 30);//
		myRect(box_x + 45, box_y + 32, box_x + 54, box_y + 51.5, 100, 100, 100, 100, 100, 100);
		myRect(box_x + 45, box_y + 58.5, box_x + 63, box_y + 65, 30, 30, 30, 30, 30, 30);//
		myRect(box_x + 54, box_y + 13, box_x + 63, box_y + 19.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 54, box_y + 19.5, box_x + 63, box_y + 26, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 54, box_y + 32.5, box_x + 63, box_y + 39, 60, 60, 60, 60, 60, 60);
		myRect(box_x + 54, box_y + 39, box_x + 63, box_y + 45.5, 45, 45, 45, 45, 45, 45);
		myRect(box_x + 54, box_y + 45.5, box_x + 72, box_y + 51, 100, 100, 100, 100, 100, 100);//
		myRect(box_x + 63, box_y + 52, box_x + 72, box_y + 58.5, 220, 0, 0, 220, 0, 0);
		myRect(box_x + 63, box_y + 39, box_x + 72, box_y + 45.5, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 72, box_y + 26, box_x + 81, box_y + 32.5, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 72, box_y + 32.5, box_x + 81, box_y + 39, 30, 30, 30, 30, 30, 30);
		myRect(box_x + 72, box_y + 39, box_x + 81, box_y + 52, 60, 60, 60, 60, 60, 60);//
		myRect(box_x + 23.1, box_y + 68, box_x + 30.8, box_y + 75, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 30.8, box_y + 68, box_x + 38.5, box_y + 82, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 89, 255, 215, 0, 255, 215, 0);
		myRect(box_x + 38.5, box_y + 68, box_x + 46.2, box_y + 75, 255, 69, 0, 255, 69, 0);//
		myRect(box_x + 46.2, box_y + 68, box_x + 53.9, box_y + 82, 255, 215, 0, 255, 215, 0);//
		myRect(box_x + 53.9, box_y + 68, box_x + 61.6, box_y + 75, 255, 215, 0, 255, 215, 0);//

		while (shipselect)
		{
			
			drawText(22, 620, 600, 0, 250, 0, "       Select Your Ship!");
			drawText(50, 600, 100, 0, 100, 0, "Space Invaders !");
			drawText(22, 620, 300, 0, 100, 0, "  Please Select the Difficulty");
			drawText(22, 620, 400, 0, 100, 0, "             Easy");
			drawText(22, 620, 500, 0, 100, 0, "             Hard");
			
			if (isKeyPressed(whichKey))
			{
				if (whichKey == 3)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
					choice1++;
					whichKey = 0;

				}
				if (whichKey == 1)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
					choice1--;
					whichKey = 0;
				}
				if (choice1 < 1)
				{
					choice1 = 1;
				}
				if (choice1 > 3)
				{
					choice1 = 3;
				}
				if (whichKey == 5 && choice1 == 1)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					ship = 1;
					break;
				}
				if (whichKey == 5 && choice1 == 2)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					ship = 2;
					break;
				}
				if (whichKey == 5 && choice1 == 3)
				{
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					ship = 3;
					break;
				}
				if (choice1 == 1)
				{
					myRect(box_x, box_y + 100, box_x + 80, box_y + 120, 0, 0, 0, 0, 0, 0);
					box_x = 700;
					myRect(box_x, box_y+100, box_x + 80, box_y + 120, 255, 255, 255,255,255,255);
				}
				if (choice1 == 2)
				{
					
					myRect(box_x, box_y + 100, box_x + 80, box_y + 120, 0, 0, 0, 0, 0, 0);
					box_x = 890;
					myRect(box_x, box_y + 100, box_x + 80, box_y + 120, 255, 255, 255, 255, 255, 255);
				}
				if (choice1 == 3)
				{
					myRect(box_x, box_y + 100, box_x + 80, box_y + 120, 0, 0, 0, 0, 0, 0);
					box_x = 1100;
					myRect(box_x, box_y + 100, box_x + 80, box_y + 120, 255, 255, 255, 255, 255, 255);
				}
			}

		}
		box_x = 700;
		drawText(20, 10, 1, 0, 255, 0, "                                      Space Invaders !!"); // drawText function draws text on the screen with arguments size, x, y, r, g, b, text
		myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 255, 255, 0); // myRect function draws a rectangle with arguments x1, y1, x2, y2, r, g, b, r2, g2, b2
		//drawText(17, 10, 895, 0, 255, 0, "Score : ",true,score);
		drawText(17, 10, 940, 0, 255, 0, "Press Shift to Shoot!");
		drawText(17, 10, 925, 0, 255, 0, "//");
		//drawText(17, 10, 1, 0, 255, 0,  true, score);
		drawBox(box_x, box_y,ship);
		drawText(20, 1450, 1, 0, 255, 0, "Lives");
		drawlife1(); //for drawing liuves.
		drawlife2();
		drawlife3();

		if (newgame == true) //enemies will be drawn again if new game is selected.
		{
			for (int i = 0; i < 50; i++, x += 140)
			{
				if (i % 10 == 0 && i != 0)
				{
					x = 250;
					y += 100;
				}
				s[i].enemy_x = x;
				s[i].enemy_y = y;
				drawenemy(s[i].enemy_x, s[i].enemy_y);

			}
		}
		
		int num = 0;
		struct enemybullet
		{
			int bull_x = 0;
			int bull_y = 0;
			
		};
		enemybullet e_bullet;
		srand(static_cast<unsigned int>(time(0)));

		int whichKey = 0;
		PlaySound(NULL, NULL, 0);
		int bullet_stepsize = 10;
		bool strike = false;
		bool fire = true;
		bool enemyfire=false;
			while (gamequit == true) // 7 is the code for ESC key.
			{
				num = rand() % 50;
				//for time elapsed
				
				auto start = std::chrono::steady_clock::now();
				
				// for enemy directiion code.
				iteration++; //for moving enemies slowly.

				for (int i = 0; i < 50; i++)
				{

					if (iteration == enemytime && enemyfire == false && s[i].status==true)
					{
							if (i == num)
							{
								e_bullet.bull_x = s[i].enemy_x + 70;
								e_bullet.bull_y = s[i].enemy_y + 90;
								enemyfire = true;

							}	
					}
				}
				if (enemyfire == true)
				{
					removeenmyfire(e_bullet.bull_x, e_bullet.bull_y);
					e_bullet.bull_y += bullet_stepsize;
					drawenmyfire(e_bullet.bull_x, e_bullet.bull_y);
					strike = checkCollision(e_bullet.bull_x, e_bullet.bull_y, box_x, box_y+60);

				}
				if (e_bullet.bull_y > bottom_limit)
				{
					enemyfire = false;
					removeenmyfire(e_bullet.bull_x, e_bullet.bull_y);

				}
				if (strike == true && enemyfire==true)
				{
					//PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("live.wav"), NULL, SND_FILENAME | SND_ASYNC);
					lives--;
					enemyfire = false;
					removeenmyfire(e_bullet.bull_x, e_bullet.bull_y);
					strike = false;
				}
				if (iteration == 50)
				{
					//PlaySound(NULL, NULL, 0);
					//PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
					iteration = 0;
					for (int i = 0; i < 50; i++)
					{
						if (s[i].status == true) //moves the enemies in the y axis by step size.
						{
							removeenemy(s[i].enemy_x, s[i].enemy_y);
							if (enemydirection % 2 != 0)
							{
								s[i].enemy_x += enemystep;
							}

							else if (enemydirection % 2 == 0)
							{
								s[i].enemy_x -= enemystep;
							}

							drawenemy(s[i].enemy_x, s[i].enemy_y);

						}

					}

					for (int i = 0; i < 50; i++)
					{
						

						if (s[i].enemy_x >= 1720 || s[i].enemy_x <= 30 && s[i].status == true)//if enemies touch left or right boundary they get down and reverse direction.
						{
							enemydirection++;

							for (int i = 0; i < 50; i++)
							{
								
								if (s[i].status == true)
								{
									removeenemy(s[i].enemy_x, s[i].enemy_y);
									s[i].enemy_y += 20;
									drawenemy(s[i].enemy_x, s[i].enemy_y);
								}
							}
							break;
						}
						
					}
					for (int i = 0; i < 50; i++)
					{
						if (s[i].status == true)
						{
							destroy = checkCollision(box_x, box_y, s[i].enemy_x, s[i].enemy_y); //if spaceship and enemy collide lives decrease.
							if (destroy == true)
							{
								//PlaySound(NULL, NULL, 0);
								PlaySound(TEXT("live.wav"), NULL, SND_FILENAME | SND_ASYNC);
								lives--;
								removeenemy(s[i].enemy_x, s[i].enemy_y);
								s[i].status = false;
							}
							if (s[i].enemy_y >= bottom_limit - 20)
							{
								gamequit = false;
								break;
							}
							if (lives < 0)
							{
								lives = 0;
							}
						}
						
					}

				}
				// for life presentation
				if (lives == 3 )
				{
					drawlife1();
					drawlife2();
					drawlife3();
					destroy = false;
				}
				if (lives == 2 )
				{
					drawlife1();
					drawlife2();
					removelife3();
					destroy = false;
				}
				if (lives == 1 )
				{
					drawlife1();
					removelife2();
					removelife3();
					destroy = false;
				}
				if (lives == 0 ) // if lives drop to zero (0) game ends.
				{
					removelife1();
					removelife2();
					removelife3();
					myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 226, 80, 128, 0, 0, 0);
					//PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("live.wav"), NULL, SND_FILENAME | SND_ASYNC);
					drawText(50, 750, 300, 0, 255, 0, " You lose!");
					drawText(50, 550, 500, 0, 255, 0, " Your Score ");
					drawText(50, 1200, 500, 0, 255, 0, "", true, score);
					gamequit = false;
					destroy = false;
					return 0;
					
					
				
				}
				
				if (isKeyPressed(whichKey)) // isKeyPressed function returns true if a key is pressed and whichKey tells that which key was pressed.
				{
					switch (whichKey)//for movement of spaceship depending on keys.
					{
					case 1:
						direction = 'L';
						whichKey = 0;
						break;
					case 2:
						direction = 'U';
						whichKey = 0;
						break;
					case 3:
						direction = 'R';
						whichKey = 0;
						break;
					case 4:
						direction = 'D';
						whichKey = 0;
						break;
					case 7:
						direction = 'P';
						whichKey = 0;
						break;
					case 6:
						if (fire == true) // if shift is pressed for firing a bullet is fired.
						{
							PlaySound(TEXT("pew.wav"), NULL, SND_FILENAME | SND_ASYNC);
							removefire(fire_x, fire_y, fireheight);
							fire_direction = 'F';
							whichKey = 0;
							fire_x = box_x;
							fire_y = box_y;
							fireheight = fire_y;
							

						}
						break;
					}
				}

				Sleep(1); // 25 milliseconds

				switch (fire_direction)
				{
				case 'F'://for the contuination of the path of the bullet.
					fire = false;

					removefire(fire_x, fire_y, fireheight);
					drawfire(fire_x, fire_y, fireheight);
					removefire(fire_x, fire_y, fireheight);
					if (fireheight > top_limit + 35)
					{
						fireheight -= step_size2;
						drawfire(fire_x, fire_y, fireheight);

					}
					else
					{
						removefire(fire_x, fire_y, fireheight);
						fire_direction = ' ';
						fire = true;
						break;

					}
					for (int i = 0; i < 50; i++)
					{


						if (s[i].status == true)
						{
							check = checkCollision(fire_x, fireheight, s[i].enemy_x, s[i].enemy_y); // for cghecking the collosioin of buillet and the enemy.
						}
						if (check == true) // enemy disspaers if their is a collion and the bullet 2.

						{
							drawText(20, 10, 1, 0, 0, 0, "Score : ", true, score);
							//PlaySound(NULL, NULL, 0);
							PlaySound(TEXT("kill.wav"), NULL, SND_FILENAME | SND_ASYNC);
							if (interval < 10000)
								score += 20;
							else if (interval < 20000 && interval>10000)
								score += 10;
							else
								score += 5;
							removeenemy(s[i].enemy_x, s[i].enemy_y);
							removefire(fire_x, fire_y, fireheight);
							fire_direction = ' ';
							fire = true;
							point++;
							s[i].status = false;
							check = false;

						}
					}
					if (point == 50) // if all 50 enemies are killed u win the game.
					{
						myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 226, 80, 128,0,0,0);

						drawText(50, 750, 300, 0, 255, 0, " You win!");
						drawText(50, 550, 500, 0, 255, 0, " Your Score ");
						drawText(50, 1200, 500, 0, 255, 0,"",true,score);
						PlaySound(NULL, NULL, 0);
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_SYNC);
						gamequit = false;
						return 0;
						break;

					}

				}
				

				switch (direction)
				{


				case 'L':
					// Left
					removeBox(box_x, box_y,ship);
					if (box_x > left_limit)
						box_x -= step_size;
					drawBox(box_x, box_y,ship);
					direction = ' ';
					break;
				case 'U':
					// Up
					removeBox(box_x, box_y,ship);
					if (box_y > top_limit)
						box_y -= step_size;
					drawBox(box_x, box_y,ship);
					direction = ' ';
					break;
				case 'R':
					// Right
					removeBox(box_x, box_y,ship);
					if (box_x + 20 < right_limit)
						box_x += step_size;
					drawBox(box_x, box_y,ship);
					direction = ' ';
					break;
				case 'D':
					// Down
					removeBox(box_x, box_y,ship);
					if (box_y + 20 < bottom_limit)
						box_y += step_size;
					drawBox(box_x, box_y,ship);
					direction = ' ';
					break;
				case 'P':
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
					whichKey = 0;
					pausecheck++;
					myRect(left_limit - 12, top_limit - 6, right_limit + 65, bottom_limit + 75, 255, 255, 0); // myRect function draws a rectangle with arguments x1, y1, x2, y2, r, g, b, r2, g2, b2

					if (pausecheck % 2 != 0)
					{
						removeBox(box_x, box_y,ship);
						drawText(50, 650, 200, 0, 255, 0, "Game Paused!");
						drawText(20, 650, 465, 0, 255, 0, "            Quit");
						drawText(20, 650, 565, 0, 255, 0, "            Save");
						
						int choice = 0;
						int choice2 = 0;
						while (loop == true)
						{
							if (isKeyPressed(whichKey)) // isKeyPressed function returns true if a key is pressed and whichKey tells that which key was pressed.
							{
								if (whichKey == 5 && choice2 == 1)
								{
									gamequit = false;
									pausecheck++;
									whichKey = 0;
									drawText(20, 650, 465, 0, 0, 0, "            Quit");
									drawText(20, 650, 565, 0, 0, 0, "            Save");
									
									break;
								}
								if (whichKey == 5 && choice2 == 2) // if game is saved all variables are stored in a file.
								{
									pausecheck++;
									whichKey = 0;
									drawText(20, 650, 465, 0, 0, 0, "            Quit");
									drawText(20, 650, 565, 0, 0, 0, "            Save");

									write.open("save.txt");
									write << box_x<<"\n";
									write << box_y<<"\n";
									write << score << "\n";
									write << enemystep << "\n";
									write << interval << "\n";
									write << enemydirection << "\n";
									write << lives << "\n";
									write << point << "\n";
									write << ship << '\n';
									for (int i = 0; i < 50; i++)
									{
										write << s[i].enemy_x << "\n";
										write << s[i].enemy_y << "\n";
										write << s[i].status << "\n";
									}
									write.close();
									
									break;
								}
								if (whichKey == 7)
								{
									pausecheck++;
									whichKey = 0;
									PlaySound(NULL, NULL, 0);
									PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
									
									break;
								}
								if (whichKey == 4)
								{
									PlaySound(NULL, NULL, 0);
									PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
									choice++;
									if (choice > 2)
									{
										choice = 2;
									}
									whichKey = 0;
									if (choice == 1)
									{
										drawText(20, 650, 465, 255, 255, 255, "            Quit");
										drawText(20, 650, 565, 0, 255, 0, "            Save");
										
										choice2 = 1;
									}
									if (choice == 2 )

									{
										drawText(20, 650, 465, 0, 255, 0, "            Quit");
										drawText(20, 650, 565, 255, 255, 255, "            Save ");
										
										choice2 = 2;
									}
									
								}
								if (whichKey == 2)
								{
									PlaySound(NULL, NULL, 0);
									PlaySound(TEXT("scroll.wav"), NULL, SND_FILENAME | SND_ASYNC);
									choice--;
									if (choice < 1)
									{
										choice = 1;
									}
									whichKey = 0;
									if (choice == 1)
									{
										drawText(20, 650, 465, 255, 255, 255, "            Quit");
										drawText(20, 650, 565, 0, 255, 0, "            Save");
										
										choice2 = 1;
									}
									if (choice == 2)

									{
										drawText(20, 650, 465, 0, 255, 0, "            Quit");
										drawText(20, 650, 565, 255, 255, 255, "            Save");
										
										choice2 = 2;
									}
									
								}
							}
						}
					}
					if (pausecheck % 2 == 0)
					{
						PlaySound(NULL, NULL, 0);
						PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC);
						iteration = 49;
						drawBox(box_x, box_y,ship);
						drawText(50, 650, 200, 0, 0, 0, "Game Paused!");
						drawText(20, 650, 465, 0, 0, 0, "            Quit");
						drawText(20, 650, 565, 0, 0, 0, "            Save");
					}

					direction = ' ';
					break;
				}
				

				drawText(20, 10, 1, 0, 255, 0, "Score : ", true, score); // represents score.


				auto end = std::chrono::steady_clock::now(); // for the measurment of time fromm chrono library.
				auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
					drawText(17, 10, 895, 0, 0, 0, "Time : ", true, interval/1000 );
				interval += elapsed.count();// adds time to a int variable.
					drawText(17, 10, 895, 0, 255, 0, "Time : ", true, interval/1000 );

					// for assabigning highscores to a variable.
					if (score > highscore5 && score < highscore4 && score < highscore3 && score < highscore2 && score < highscore1)
					{
						highscore5 = score;
					}
					else if (score > highscore5 && score > highscore4 && score < highscore3 && score < highscore2 && score < highscore1)
					{
						highscore4 = score;
					}
					else if (score > highscore5 && score > highscore4 && score > highscore3 && score < highscore2 && score < highscore1)
					{
						highscore3 = score;
					}
					else if (score > highscore5 && score > highscore4 && score > highscore3 && score > highscore2 && score < highscore1)
					{
						highscore2 = score;
					}
					else if (score > highscore5 && score > highscore4 && score > highscore3 && score > highscore2 && score > highscore1)
					{
						highscore1 = score;
					}
					write.open("highscore.txt");
					write << highscore1 << '\n';
					write << highscore2 << '\n';
					write << highscore3 << '\n';
					write << highscore4 << '\n';
					write << highscore5 << '\n';
					write.close();
					
			}
	}

		return 0;// hehe boi

}

	