#pragma once
#include"User.h"
#include"Page.h"
#include"helper.h"
using namespace std;
class post;
class user;
class page;
class socialentity;
class comments
{
	char* comment_id;
	post* published_on_post;
	socialentity* owner;
	char* description;
	helper temp;
public:
	~comments();
	char* get_comment_id();
	void set_comment_id(char* a);
	post* get_published_on_post();
	void set_published_on_post(post& a);
	socialentity* get_owner();
	void set_owner(socialentity& a);
	char* get_description();
	void set_description(char*& a);
};