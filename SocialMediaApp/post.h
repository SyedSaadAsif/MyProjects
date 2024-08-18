#pragma once
using namespace std;
#include"User.h"
#include"page.h"
#include"comments.h"
#include"SocialEntity.h"
#include"date.h"
#include"activity.h"
#include"helper.h"
class user;
class page;
class date;
class comments;
class Activity;
class socialentity;
class helper;
class post
{
	char* postID;
	char* description;
	int comment_size;
	char* memory_description;
	bool memory_exists;
	socialentity* owner;
	date postDate;
	comments** comment;
	Activity activity;
	socialentity** social_liked;
	helper temp;
	int liked;

public:
	virtual ~post();
	char* get_memory_description();
	bool get_memory_exists();
	void set_memory_description(char* a);
	char* get_postID();
	char* get_description();
	socialentity* get_owner();
	date& get_postDate();
	comments** get_comment();
	void initialize_comment();
	Activity& get_activity();
	socialentity** get_social_liked();
	void set_social_liked();
	void increment_liked();
	int get_liked();
	void set_liked(int a);
	post(char* id = 0, char* name = 0);
	void set_postID(char* a);
	void set_description(char* a);
	void set_owner(socialentity& obj);
	void set_owner(page& obj);
	int get_comment_size();
	void set_comment_size(int a);
	void increment_comment_size();
	void link_comment(int i, comments* a);
	void link_socialliked(int i, socialentity* a);
	void initialize_socialliked(int i);
	char* give_activity();

};