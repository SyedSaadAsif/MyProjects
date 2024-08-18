#pragma once
#include"helper.h"
using namespace std;
class date
{
	int day;
	int month;
	int year;
public:
	date();
	int get_day();
	int get_month();
	int get_year();
	void set_day(int a);
	void set_month(int a);
	void set_year(int a);


};