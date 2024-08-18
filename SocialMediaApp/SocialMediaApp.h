#pragma once
using namespace std;
#include<iostream>
#include<fstream>
#include"User.h"
#include"Page.h"
#include"post.h"
#include"date.h"
#include"comments.h"
#include"activity.h"
#include"memory.h"
#include"helper.h"
#include<sstream>
#include"SFML/Graphics.hpp"

class SocialMediaApp
{
	int total_users;
	int total_pages;
	int total_posts;
	user* current_user;
	page** pages;
	user** users;
	post** posts;
	date current_date;
	helper temp1;
public:
	~SocialMediaApp();
	SocialMediaApp();
	date get_current_date();
	void readInitialData();
	void run();
	int set_current_user(char* temp);
	bool compare_date(date a, date b);
	void print_post(sf::RenderWindow& window, post& obj, sf::Font& font, int x, int y);
	void view_home(sf::RenderWindow& window, sf::Font& font);
	void like_a_post(sf::RenderWindow& window, sf::Font& font, char* temp);
	void print_like_list(sf::RenderWindow& window, sf::Font& font, char* temp);
	void comment_on_post(sf::RenderWindow& window, sf::Font& font, char* temp, sf::Text& in, sf::Sprite& sprite, sf::Texture& texture3, sf::Texture& texture6);
		void view_post(sf::RenderWindow& window, sf::Font& font, char* temp);
	void reinitialize_posts(int new_size);
	void resize_timeline(int new_size, user* a, post* b);
	void share_memory(sf::RenderWindow& window, sf::Font& font, char* temp, sf::Text& in, sf::Sprite& sprite, sf::Texture& texture3, sf::Texture& texture6);
		void enter_line();
	void user_profile(sf::RenderWindow& window, sf::Font& font);
	void Print_friendlist(sf::RenderWindow& window, sf::Font& font, char* temp);
	void View_page(sf::RenderWindow& window, sf::Font& font, char* temp);
};