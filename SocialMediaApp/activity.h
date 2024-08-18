#pragma once
using namespace std;
#include"helper.h"
class Activity
{
	int type;
	char* value;
	helper temp;
public:
	Activity();
	~Activity();
	int get_type();
	char* get_value();
	void set_type(int a);
	void set_value(char* a);

};