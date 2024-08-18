#pragma once
#include"User.h"
#include"Page.h"
#include"helper.h"
class socialentity
{
	char* objID;
	char* name;
	helper temp;
public:
	socialentity();
	virtual ~socialentity();
	char* get_nameofentity();
	void set_nameofentity(char* a);
	char* get_objID();
	void set_objID(char* id = 0);
	void set_objID(const char* id = 0);

};