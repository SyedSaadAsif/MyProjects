#pragma once
using namespace std;
#include"Page.h"
#include"helper.h"
#include"SocialEntity.h"
class page;
class post;
class user : public socialentity
{
	char* userID;
	char* name;
	user** friendlist;
	int friendlist_size;
	int pagesliked_size;
	page** pagesliked;
	post** user_timeline;
	int timeline_size;
	helper temp;

public:
	~user();
	char* get_userID();
	char* get_name();
	user** get_friendlist();
	void set_pagesliked(int& a);
	int get_timeline_size();
	int get_pagesliked_size();
	int get_friendlist_size();
	void set_friendlist_size(int a);
	void set_timeline_size(int a);
	void increment_timeline_size();
	void insert_post_timeline(int a, post* b);
	void initialize_timeline(int a);
	page** get_pagesliked();
	post** get_user_timeline();
	void reset_user_timeline();
	user(char* id = 0, char* nam = 0);
	void set_friendlist(int& a);

};