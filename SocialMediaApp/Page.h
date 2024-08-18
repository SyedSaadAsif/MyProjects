#pragma once
using namespace std;
#include"User.h"
#include"post.h"
#include"SocialEntity.h"
class user;
class post;
class page : public socialentity
{
	char* pageID;
	char* title;
	user* owner;
	post** page_timeline;
	int timeline_size;
	int likes;
	helper temp;
public:
	page(char* id = 0, char* name = 0);
	~page();
	int get_timeline_size();
	void increment_timeline_size();
	void set_timeline_size(int a);
	void insert_post_timeline(int a, post* b);
	void initialize_timeline(int a);
	char* get_pageID();
	char* get_title();
	user* get_owner();
	void set_owner(user& a);
	post** get_page_timeline();
};