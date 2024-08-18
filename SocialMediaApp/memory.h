#pragma once
using namespace std;
#include"post.h"
class post;
class memory:public post
{
	post* linked_post;
	helper temp;
public:
	post* get_linked_post();
	~memory();
	memory(char* a, post* obj, date b);
};