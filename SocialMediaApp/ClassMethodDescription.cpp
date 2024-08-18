#pragma once
using namespace std;
#include<iostream>
#include"SocialMediaApp.h"
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

//method description for main socialmeddia class.

SocialMediaApp :: ~SocialMediaApp()
{
	cout << "All destructurs called succesfully\n";
	int x = 1;
	current_user = 0;
	for (int i = 0; i < total_pages; i++)
	{
		delete pages[i];
	}
	delete[] pages;
	pages = nullptr;
	total_pages = 0;
	for (int i = 0; i < total_users; i++)
	{
		delete users[i];
	}
	delete[] users;
	users = nullptr;

	for (int i = 0; i < total_posts; i++)
	{
		delete posts[i];
	}
	if (x != 1)
	{
		delete[]posts;
	}
	posts = nullptr;

}
SocialMediaApp :: SocialMediaApp()
{
	current_user = 0;
	pages = 0;
	users = 0;
	posts = 0;
	current_date.set_day(15);
	current_date.set_month(11);
	current_date.set_year(2017);
	temp1.key = 1;
	total_users = 0;
	total_pages = 0;
	total_posts = 0;
}
date SocialMediaApp::get_current_date()
{
	return current_date;
}
void SocialMediaApp::readInitialData()
{
	ifstream read;
	read.open("users.txt");
	read >> total_users;
	char* temp = new char[100];
	char* temp2 = new char[100];
	char a[100]; //only to store trash data and skip a line in file.
	users = new user * [total_users];
	read.getline(temp, 100);

	for (int i = 0; i < total_users; i++)
	{
		read.getline(temp, 100);
		read.getline(temp2, 100);
		read.getline(a, 100);
		users[i] = new user(temp, temp2);
	}
	read.close();
	read.open("pages.txt");
	read >> total_pages;
	pages = new page * [total_pages];
	read.getline(temp, 100);

	for (int i = 0; i < total_pages; i++)
	{
		read.getline(temp, 100);
		read.getline(temp2, 100);
		pages[i] = new page(temp, temp2);
	}
	read.close();
	read.open("posts.txt");
	//read data for posts.
	read >> total_posts;
	posts = new post * [total_posts];
	for (int i = 0; i < total_posts; i++)
	{
		posts[i] = new post();
	}
	int type = 0;
	for (int i = 0; i < total_posts; i++)
	{
		read >> type;
		if (type == 2)
		{
			read >> temp;
			posts[i]->set_postID(temp);
			read >> type;
			posts[i]->get_postDate().set_day(type);
			read >> type;
			posts[i]->get_postDate().set_month(type);
			read >> type;
			posts[i]->get_postDate().set_year(type);
			read.getline(temp, 100);
			read.getline(temp, 100);
			posts[i]->set_description(temp);
			read >> type;
			posts[i]->get_activity().set_type(type);
			read.getline(temp, 100);
			posts[i]->get_activity().set_value(temp);
			///read.getline(temp, 100);
			read.getline(temp, 100);
			int set = 0;
			for (int j = 0; j < total_users && set == 0 && temp[0] == 'u'; j++)
			{
				if (temp1.mycompare(temp, users[j]->get_objID()))
				{
					posts[i]->set_owner(users[j][0]);
					users[j][0].increment_timeline_size();
					set = 1;
				}
			}
			if (set == 0)
			{
				for (int j = 0; j < total_pages && set == 0 && temp[0] == 'p'; j++)
				{
					if (temp1.mycompare(temp, pages[j]->get_objID()))
					{
						posts[i]->set_owner(pages[j][0]);
						pages[j][0].increment_timeline_size();
						set = 1;
					}
				}
			}//have to do something about the number of likes most probs resize method is optimal in this case
			int val = 0;
			for (int j = 0, k = 0, s = 0; k != 1; )
			{
				read >> temp;
				j += temp1.mylen(temp);
				s++;
				if (temp1.mycompare(temp, "-1"))
				{
					j--;
					s--;
					posts[i]->set_liked(s);

					val = -j;
					k = 1;
				}
			}
			read.seekg(val, ios_base::cur);
			val = posts[i]->get_liked();
			posts[i]->set_social_liked();
			set = 0;
			for (int j = 0; j < val; j++)
			{
				read >> temp;
				set = 0;
				if (temp1.mycompare(temp, "-1"))
				{
					break;
				}
				else
				{
					for (int k = 0; k < total_users && set == 0; k++)
					{
						if (temp1.mycompare(temp, users[k]->get_objID()))
						{
							posts[i]->get_social_liked()[j] = users[k];
							set = 1;
						}

					}
					if (set == 0)
					{
						for (int k = 0; k < total_pages && set == 0; k++)
						{
							if (temp1.mycompare(temp, pages[k]->get_objID()))
							{
								posts[i]->get_social_liked()[j] = pages[k];
								set = 1;
							}

						}
					}


				}
			}
			type = 2;
			read >> temp;
		}
		if (type == 1)
		{
			read >> temp;
			posts[i]->set_postID(temp);
			read >> type;
			posts[i]->get_postDate().set_day(type);
			read >> type;
			posts[i]->get_postDate().set_month(type);
			read >> type;
			posts[i]->get_postDate().set_year(type);
			read.getline(temp, 100);
			read.getline(temp, 100);
			posts[i]->set_description(temp);
			read.getline(temp, 100);
			int set = 0;
			for (int j = 0; j < total_users && set == 0 && temp[0] == 'u'; j++)
			{
				if (temp1.mycompare(temp, users[j]->get_objID()))
				{
					posts[i]->set_owner(users[j][0]);
					users[j][0].increment_timeline_size();
					set = 1;
				}
			}
			if (set == 0)
			{
				for (int j = 0; j < total_pages && set == 0 && temp[0] == 'p'; j++)
				{
					if (temp1.mycompare(temp, pages[j]->get_objID()))
					{
						posts[i]->set_owner(pages[j][0]);
						pages[j][0].increment_timeline_size();
						set = 1;
					}
				}
			}
			int val = 0;
			for (int j = 0, k = 0, s = 0; k != 1; )
			{
				read >> temp;
				j += temp1.mylen(temp);
				s++;
				if (temp1.mycompare(temp, "-1"))
				{
					j--;
					s--;
					posts[i]->set_liked(s);
					val = -j;
					k = 1;
				}
			}
			read.seekg(val, ios_base::cur);
			val = posts[i]->get_liked();
			posts[i]->set_social_liked();
			set = 0;

			for (int j = 0; j < val; j++)
			{
				read >> temp;
				set = 0;
				if (temp1.mycompare(temp, "-1"))
				{
					break;
				}
				else
				{
					for (int k = 0; k < total_users && set == 0; k++)
					{
						if (temp1.mycompare(temp, users[k]->get_objID()))
						{
							posts[i]->get_social_liked()[j] = users[k];
							set = 1;
						}

					}
					if (set == 0)
					{
						for (int k = 0; k < total_pages && set == 0; k++)
						{
							if (temp1.mycompare(temp, pages[k]->get_objID()))
							{
								posts[i]->get_social_liked()[j] = pages[k];
								set = 1;
							}

						}
					}


				}
			}
			type = 1;
			read >> temp;

		}


	}

	//all data of posts is read here.
	//post read here.
	//now for reading friendlist and pages liked.
	read.close();
	read.open("Users.txt");
	read.getline(temp, 100);
	int val = 0;
	for (int i = 0; i < total_users; i++)
	{
		read.getline(temp, 100);
		read.getline(temp, 100);
		int s = 0;
		for (int j = 0, k = 0; k != 1; )
		{
			read >> temp;
			j += temp1.mylen(temp);
			s++;
			if (temp1.mycompare(temp, "-1"))
			{
				j--;
				s--;
				users[i]->set_friendlist(s);
				val = -j;
				k = 1;
			}
		}
		read.seekg(val, ios_base::cur);
		val = s;
		for (int j = 0; j < val; j++)
		{
			read >> temp;
			int set = 0;
			for (int k = 0; k < total_users && set == 0; k++)
			{
				if (temp1.mycompare(temp, users[k]->get_objID()))
				{
					users[i]->get_friendlist()[j] = &users[k][0];
					set = 1;
				}

			}
		}
		read >> temp;
		s = 0;
		for (int j = 0, k = 0; k != 1; )
		{
			read >> temp;
			j += temp1.mylen(temp);
			s++;
			if (temp1.mycompare(temp, "-1"))
			{
				j--;
				s--;
				users[i]->set_pagesliked(s);
				val = -j;
				k = 1;
			}
		}
		read.seekg(val, ios_base::cur);
		val = s;
		for (int j = 0; j < val; j++)
		{
			read >> temp;
			int set = 0;
			for (int k = 0; k < total_pages && set == 0; k++)
			{
				if (temp1.mycompare(temp, pages[k]->get_objID()))
				{
					users[i]->get_pagesliked()[j] = &pages[k][0];
					set = 1;
				}

			}
		}
		read.getline(temp, 100);
	}
	//now for initialization of timelines of user and pages.
	for (int i = 0; i < total_users; i++)
	{
		users[i]->initialize_timeline(users[i]->get_timeline_size());
		users[i]->set_timeline_size(0);
	}
	for (int i = 0; i < total_pages; i++)
	{
		pages[i]->initialize_timeline(pages[i]->get_timeline_size());
		pages[i]->set_timeline_size(0);
	}
	int set = 0;
	for (int i = 0; i < total_posts; i++)
	{
		set = 0;
		for (int j = 0; j < total_users && set == 0; j++)
		{
			if (posts[i]->get_owner()->get_objID() == users[j]->get_objID())
			{
				users[j]->insert_post_timeline(users[j]->get_timeline_size(), posts[i]);
				//cout << users[j]->get_user_timeline()[users[j]->get_timeline_size()]->get_postID() << endl;
				users[j]->increment_timeline_size();

				set = 1;
			}
		}
		for (int j = 0; j < total_pages && set == 0; j++)
		{
			if (posts[i]->get_owner()->get_objID() == pages[j]->get_objID())
			{
				pages[j]->insert_post_timeline(pages[j]->get_timeline_size(), posts[i]);
				//cout << pages[j]->get_page_timeline()[pages[j]->get_timeline_size()]->get_postID() << endl;
				pages[j]->increment_timeline_size();
			}
		}
	}
	// done.
	//now for owners of pages (seperate text file).
	read.close();
	read.open("pages_owner.txt");
	for (int i = 0; i < total_pages; i++)
	{
		set = 0;
		read.getline(temp, 100);
		for (int j = 0; j < total_users && set == 0; j++)
		{
			if (temp1.mycompare(temp, users[j]->get_objID()))
			{
				pages[i]->set_owner(users[j][0]);
				set = 1;
			}
		}
	}
	//done;
	//now for commenting on seperate posts.
	read.close();
	read.open("Comments.txt");
	int total_comm = 0;
	read >> total_comm;
	for (int i = 0; i < total_posts; i++)
	{
		posts[i]->initialize_comment();
		posts[i]->set_comment_size(0);
	}
	read.close();
	read.open("Comments.txt");
	read >> temp;
	for (int i = 0; i < total_comm; i++)
	{
		read >> temp;
		read >> temp2;
		for (int j = 0, l = 0; j < total_posts && l != 1; j++)
		{
			if (temp1.mycompare(temp2, posts[j]->get_postID()))
			{
				posts[j]->get_comment()[posts[j]->get_comment_size()]->set_comment_id(temp);
				read >> temp;
				set = 0;
				for (int k = 0; k < total_users && set == 0; k++)
				{
					if (temp1.mycompare(temp, users[k]->get_objID()))
					{
						posts[j]->get_comment()[posts[j]->get_comment_size()]->set_owner(users[k][0]);
						set = 1;
					}

				}
				for (int k = 0; k < total_pages && set == 0; k++)
				{
					if (temp1.mycompare(temp, pages[k]->get_objID()))
					{
						posts[j]->get_comment()[posts[j]->get_comment_size()]->set_owner(pages[k][0]);
						set = 1;
					}
				}
				read.getline(temp, 100);
				posts[j]->get_comment()[posts[j]->get_comment_size()]->set_description(temp);
				posts[j]->increment_comment_size();
				l = 1;
			}
		}
	}
	//comment reading done.
	//i hereby declare the end of file reading (OwO).
	delete[]temp;
	delete[] temp2;
}
void SocialMediaApp::run()
{
	bool isviewhome = 0;
	bool main = 0;
	bool userset = 0;
	int screen1 = 0;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "~SOCIAL MEDIA APP~", sf::Style::Default);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("Swansea.ttf"))
	{
		std::cout << "Error loading font file!" << std::endl;
	}
	char* inputString = new char[100];
	inputString[0] = '\0';

	sf::Text inputText("", font, 50);
	inputText.setFillColor(sf::Color::Black);
	inputText.setPosition(950.f, 570.f);
	sf::Texture texture;
	texture.loadFromFile("hex.png");
	sf::Texture texture2;
	texture2.loadFromFile("currentuser.png");
	sf::Texture texture3;
	texture3.loadFromFile("viewhome.png");
	sf::Texture texture4;
	texture4.loadFromFile("main.png");
	sf::Text message("", font, 50);
	sf::Texture texture5;
	texture5.loadFromFile("likeapost.png");
	sf::Texture texture6;
	texture6.loadFromFile("viewlikelist.png");
	sf::Texture texture7;
	texture7.loadFromFile("commentonpost.png");
	sf::Texture texture8;
	texture8.loadFromFile("viewpost.png");
	sf::Texture texture9;
	texture9.loadFromFile("memory.png");
	sf::Texture texture10;
	texture10.loadFromFile("viewfriendlist.png");
	sf::Texture texture11;
	texture11.loadFromFile("viewpage.png");

	message.setFillColor(sf::Color::White);
	message.setPosition(830.f, 770.f);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event) && window.isOpen())
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::TextEntered && screen1 >= 100)
			{
				if (event.text.unicode < 128 && event.text.unicode != 8 && strlen(inputString) < 99) // Allow ASCII characters except backspace and limit input length
				{
					size_t len = strlen(inputString);
					inputString[len] = static_cast<char>(event.text.unicode);
					inputString[len + 1] = '\0';
					inputText.setString(inputString);
				}
				else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
				{
					inputString[strlen(inputString) - 1] = '\0';
					inputText.setString(inputString);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				inputString[strlen(inputString)] = '\0';
				if (userset == 0)
				{
					if (set_current_user(inputString))
					{
						message.setString("User set to: " + std::string(inputString));
						userset = 1;
						main = 1;
					}
					else
					{
						message.setString("Invalid User : " + std::string(inputString));
					}
				}
				char digit = 'a';
				while (main = 1 && userset == 1 && window.isOpen())
				{
					while (window.pollEvent(event) && window.isOpen())
					{
						if (event.type == sf::Event::Closed)
							window.close();
						if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::RShift)
						{
							window.close();
						}
						if (event.type == sf::Event::TextEntered) {
							if (event.text.unicode >= '0' && event.text.unicode <= '9') {
								digit = static_cast<char>(event.text.unicode);
							}
						}
						if (digit == '1')
						{
							window.clear(sf::Color::White);
							sprite.setTexture(texture3);
							window.draw(sprite);
							view_home(window, font);
							window.display();
							for (int i = 0; i == 0;)
							{
								if (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										i = 1;
										digit = 'a';
									}
								}
							}
						}
						if (digit == '2')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '2')
							{
								window.clear(sf::Color::White);
								sprite.setTexture(texture5);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										window.clear(sf::Color::White);
										sprite.setTexture(texture3);
										window.draw(sprite);
										inputString[strlen(inputString)] = '\0';
										like_a_post(window, font, inputString);
										window.display();
										while (digit == '2')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
												if (event.type == sf::Event::Closed)
													window.close();
											}
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '3')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '3')
							{
								window.clear(sf::Color::White);
								sprite.setTexture(texture6);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										window.clear(sf::Color::White);
										sprite.setTexture(texture3);
										window.draw(sprite);
										inputString[strlen(inputString)] = '\0';
										print_like_list(window, font, inputString);
										window.display();
										while (digit == '3')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
												if (event.type == sf::Event::Closed)
													window.close();
											}
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '4')
						{

							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '4')
							{
								bool postfound = 0;
								window.clear(sf::Color::White);
								sprite.setTexture(texture7);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										inputString[strlen(inputString)] = '\0';
										comment_on_post(window, font, inputString, inputText, sprite, texture3, texture7);
										window.display();
										while (digit == '4')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
											}
											if (event.type == sf::Event::Closed)
												window.close();
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '5')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '5')
							{
								window.clear(sf::Color::White);
								sprite.setTexture(texture8);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										window.clear(sf::Color::White);
										sprite.setTexture(texture3);
										window.draw(sprite);
										inputString[strlen(inputString)] = '\0';
										view_post(window, font, inputString);
										window.display();
										while (digit == '5')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
												if (event.type == sf::Event::Closed)
													window.close();
											}
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}
								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '6')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '6')
							{
								bool postfound = 0;
								window.clear(sf::Color::White);
								sprite.setTexture(texture9);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										inputString[strlen(inputString)] = '\0';
										share_memory(window, font, inputString, inputText, sprite, texture3, texture9);
										window.display();
										while (digit == '6')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
											}
											if (event.type == sf::Event::Closed)
												window.close();
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '7')
						{
							window.clear(sf::Color::White);
							sprite.setTexture(texture3);
							window.draw(sprite);
							user_profile(window, font);
							window.display();
							for (int i = 0; i == 0;)
							{
								if (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										i = 1;
										digit = 'a';
									}
								}
							}
						}
						if (digit == '8')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '8')
							{
								window.clear(sf::Color::White);
								sprite.setTexture(texture10);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										window.clear(sf::Color::White);
										sprite.setTexture(texture3);
										window.draw(sprite);
										inputString[strlen(inputString)] = '\0';
										Print_friendlist(window, font, inputString);
										window.display();
										while (digit == '8')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
												if (event.type == sf::Event::Closed)
													window.close();
											}
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '9')
						{
							inputString[0] = '\0';
							inputText.setString("\0");
							while (digit == '9')
							{
								window.clear(sf::Color::White);
								sprite.setTexture(texture11);
								window.draw(sprite);
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window.close();

									if (event.type == sf::Event::TextEntered)
									{
										if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
										{
											size_t len = strlen(inputString);
											inputString[len] = static_cast<char>(event.text.unicode);
											inputString[len + 1] = '\0';
											inputText.setString(inputString);
										}
										else if (event.text.unicode == 8 && strlen(inputString) > 0) // Handle backspace
										{
											inputString[strlen(inputString) - 1] = '\0';
											inputText.setString(inputString);
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
									{
										window.clear(sf::Color::White);
										sprite.setTexture(texture3);
										window.draw(sprite);
										inputString[strlen(inputString)] = '\0';
										View_page(window, font, inputString);
										window.display();
										while (digit == '9')
										{
											while (window.pollEvent(event))
											{
												if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
												{
													digit = 'a';
												}
												if (event.type == sf::Event::Closed)
													window.close();
											}
										}
									}
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
									{
										digit = 'a';
									}

								}
								inputText.setString(inputString);
								window.draw(inputText);
								window.display();
							}
						}
						if (digit == '0')
						{
							main = 0;
							userset = 0;
						}

					}
					window.clear(sf::Color::White);
					sprite.setTexture(texture4);
					window.draw(sprite);
					window.display();
				}


			}
		}
		if (screen1 < 100)
		{
			screen1++;
			window.clear(sf::Color::Black);
			window.draw(sprite);
			window.display();

		}
		else if (screen1 >= 100 && main == 0)
		{
			window.clear(sf::Color::White);
			sprite.setTexture(texture2);
			window.draw(sprite);
			window.draw(inputText);
			window.draw(message);
			window.display();
		}
	}

}
int SocialMediaApp::set_current_user(char* temp)
{
	for (int i = 0, j = 0; i < total_users && j == 0; i++)
	{
		if (temp1.mycompare(temp, users[i]->get_objID()))
		{
			current_user = users[i];
			j = 1;
			return 1;
		}
	}
	return 0;
}
bool SocialMediaApp::compare_date(date a, date b)
{
	if ((a.get_day() == b.get_day() || a.get_day() == b.get_day() - 1) && a.get_month() == b.get_month() && a.get_year() == b.get_year())
	{
		return 1;
	}
	else
		return 0;
}
void SocialMediaApp::print_post(sf::RenderWindow& window, post& obj, sf::Font& font, int x, int y)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(x, y);


	// Create a stringstream to construct the text
	std::stringstream ss;

	// Construct the text content
	ss << "--------------------------------------------------------------\n\n";

	// Add relevant information from the post object
	if (obj.get_memory_exists())
	{
		ss << "Shared a memory\n\n" << obj.get_memory_description() << "\t(" << obj.get_postDate().get_day() << " , " << obj.get_postDate().get_month() << " , " << obj.get_postDate().get_year() << ")\n\n\n\n";
	}
	if (obj.get_activity().get_type() != 0)
	{
		ss << obj.get_owner()->get_nameofentity() << " is " << obj.give_activity() << obj.get_activity().get_value() << "\n\n";
	}

	ss << obj.get_owner()->get_nameofentity() << " (" << obj.get_owner()->get_objID() << ")" << " posted " << "(" << obj.get_postID() << ")" << " : \n\n";
	ss << obj.get_description() << std::endl;
	ss << "\nPeople Commented : \n\t\n";

	for (int i = 0; i < obj.get_comment_size(); i++)
	{
		ss << obj.get_comment()[i]->get_owner()->get_nameofentity() << " : ";
		ss << obj.get_comment()[i]->get_description() << "\n\n";
	}

	ss << "liked by :\n\t\n";

	for (int i = 0; i < obj.get_liked(); i++)
	{
		ss << obj.get_social_liked()[i]->get_nameofentity() << "\n\n";
	}

	ss << std::endl;

	// Set the text content to the stringstream
	text.setString(ss.str());

	// Draw the text on the SFML window
	window.draw(text);
}
void SocialMediaApp::view_home(sf::RenderWindow& window, sf::Font& font)
{
	int y = 70, x = 60;
	int size = current_user->get_friendlist_size();
	for (int i = 0; i < size; i++)
	{
		if (y > 700)
		{
			x += 500;
			y = 70;
		}
		int size2 = current_user->get_friendlist()[i]->get_timeline_size();
		for (int j = 0; j < size2; j++, y += 250)
		{
			if (compare_date(current_user->get_friendlist()[i]->get_user_timeline()[j]->get_postDate(), current_date))
			{
				print_post(window, *current_user->get_friendlist()[i]->get_user_timeline()[j], font, x, y);
			}

		}
	}
	size = current_user->get_pagesliked_size();
	y += 250;
	for (int i = 0; i < size; i++)
	{
		if (y > 700)
		{
			x += 600;
			y = 70;
		}
		int size2 = current_user->get_pagesliked()[i]->get_timeline_size();
		for (int j = 0; j < size2; j++, y += 250)
		{
			if (compare_date(current_user->get_pagesliked()[i]->get_page_timeline()[j]->get_postDate(), current_date))
			{
				print_post(window, *current_user->get_pagesliked()[i]->get_page_timeline()[j], font, x, y);
			}
		}
	}

}
void SocialMediaApp::like_a_post(sf::RenderWindow& window, sf::Font& font, char* temp)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(760.f, 470.f);
	stringstream ss;
	bool found = 0;
	for (int i = 0; i < total_posts && found == 0; i++)
	{
		if (temp1.mycompare(temp, posts[i]->get_postID()))
		{
			found = 1;
			if (posts[i]->get_liked() < 10)
			{
				posts[i]->get_social_liked()[posts[i]->get_liked()] = current_user;
				posts[i]->increment_liked();
				ss << "User : " << current_user->get_name() << "(" << current_user->get_objID() << ")" << " liked " << posts[i]->get_postID() << endl;
				ss << "\nnumber of likes on " << posts[i]->get_postID() << " = " << posts[i]->get_liked() << endl;
			}
			else
			{
				ss << "\nlike limit reached on post!\n";
			}
		}

	}
	if (found == 0)
	{
		ss << "\nInvalid post name or post not found!\n";
	}
	text.setString(ss.str());

	// Draw the text on the SFML window
	window.draw(text);
}
void SocialMediaApp::print_like_list(sf::RenderWindow& window, sf::Font& font, char* temp)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(760.f, 470.f);
	stringstream s;
	bool found = 0;
	for (int i = 0; i < total_posts && found == 0; i++)
	{
		if (temp1.mycompare(temp, posts[i]->get_postID()))
		{
			found = 1;
			for (int j = 0; j < posts[i]->get_liked(); j++)
			{
				s << j + 1 << ".\t" << posts[i]->get_social_liked()[j]->get_nameofentity() << " (" << posts[i]->get_social_liked()[j]->get_objID() << ")" << "\n\n";
			}
		}

	}
	if (found == 0)
	{
		s << "\nInvalid post name or post not found!\n\n";
	}
	text.setString(s.str());

	// Draw the text on the SFML window
	window.draw(text);
}
void SocialMediaApp::comment_on_post(sf::RenderWindow& window, sf::Font& font, char* temp, sf::Text& in, sf::Sprite& sprite, sf::Texture& texture3, sf::Texture& texture6)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(760.f, 470.f);

	stringstream s;

	sf::Text inputText2("", font, 50);
	inputText2.setFillColor(sf::Color::Black);
	inputText2.setPosition(860.f, 850.f);
	char* temp2 = new char[100];
	temp2[0] = '\0';
	sf::Event event;
	bool found = 0;
	bool exit = 0;
	for (int i = 0; i < total_posts && found == 0; i++)
	{
		if (temp1.mycompare(temp, posts[i]->get_postID()))
		{
			found = 1;
			bool set = 0;
			while (set == 0 && exit == 0)
			{
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
						{
							size_t len = strlen(temp2);
							temp2[len] = static_cast<char>(event.text.unicode);
							temp2[len + 1] = '\0';
							inputText2.setString(temp2);
						}
						else if (event.text.unicode == 8 && strlen(temp2) > 0) // Handle backspace
						{
							temp2[strlen(temp2) - 1] = '\0';
							inputText2.setString(temp2);
						}
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
					{
						set = 1;
						temp2[strlen(temp2)] = '\0';
						inputText2.setString(temp2);
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					{
						exit = 1;
					}
					window.clear(sf::Color::White);
					sprite.setTexture(texture6);
					window.draw(sprite);
					window.draw(in);
					window.draw(inputText2);
					window.display();
				}
			}
			if (exit == 0)
			{


				temp2 = temp1.addstrings("\t", temp2);
				if (posts[i]->get_comment_size() < 10)
				{
					posts[i]->get_comment()[posts[i]->get_comment_size()]->set_owner(*current_user);
					posts[i]->get_comment()[posts[i]->get_comment_size()]->set_description(temp2);
					posts[i]->increment_comment_size();
					s << "User : " << current_user->get_name() << "(" << current_user->get_objID() << ")" << " commented on " << posts[i]->get_postID() << "\n\n";
					s << "number of comments on " << posts[i]->get_postID() << " = " << posts[i]->get_comment_size() << "\n\n";
				}
				else
				{
					s << "\ncomment limit reached on post!\n";
				}
			}
		}

	}
	if (found == 0)
	{
		s << "\nInvalid post name or post not found!\n";
	}
	text.setString(s.str());

	// Draw the text on the SFML window
	if (exit == 0)
	{
		window.clear(sf::Color::White);
		sprite.setTexture(texture3);
		window.draw(sprite);
		window.draw(text);
	}
	delete[]temp2;
}
void SocialMediaApp::view_post(sf::RenderWindow& window, sf::Font& font, char* temp)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(660.f, 370.f);
	stringstream s;
	bool found = 0;
	for (int i = 0; i < total_posts && found == 0; i++)
	{
		if (temp1.mycompare(temp, posts[i]->get_postID()))
		{
			found = 1;
			s << "--------------------------------------------------------------------------------------------\n\n";
			s << posts[i]->get_owner()->get_nameofentity() << " (" << posts[i]->get_owner()->get_objID() << ")" << " posted " << "(" << posts[i]->get_postID() << ")" << " : \n\n";
			s << posts[i]->get_description() << "\n\n";
			s << "People Commented : \n\t\n";
			for (int j = 0; j < posts[i]->get_comment_size(); j++)
			{
				s << posts[i]->get_comment()[j]->get_owner()->get_nameofentity() << " : ";
				s << posts[i]->get_comment()[j]->get_description() << "\n\n";
			}
			cout << "\nliked by :\n\t\n";
			for (int j = 0; j < posts[i]->get_liked(); j++)
			{
				s << posts[i]->get_social_liked()[j]->get_nameofentity() << "\n\n";
			}
			s << endl;
		}

	}
	if (found == 0)
	{
		cout << "\nInvalid post name or post not found!\n";
	}
	text.setString(s.str());

	// Draw the text on the SFML window
	window.draw(text);
}
void SocialMediaApp::reinitialize_posts(int new_size)
{
	post** updated_posts = new post * [new_size];
	for (int i = 0; i < new_size; i++)
	{
		updated_posts[i] = 0;
	}
	for (int i = 0; i < total_posts && i < new_size; i++)
	{
		updated_posts[i] = posts[i];
	}
	for (int i = 0; i < total_posts; i++)
	{
		posts[i] = 0;
		delete[]posts[i];
	}
	posts = 0;
	delete[]posts;
	posts = new post * [new_size];
	for (int i = 0; i < new_size; i++)
	{
		posts[i] = updated_posts[i];
	}
	for (int i = 0; i < new_size; i++)
	{
		updated_posts[i] = 0;
		delete[]updated_posts[i];
	}
	updated_posts = 0;
	delete[]updated_posts;
	if (new_size > total_posts)
	{
		total_posts += new_size - total_posts;
	}
	else
		total_posts += total_posts - new_size;

}
void SocialMediaApp::resize_timeline(int new_size, user* a, post* b)
{
	post** updated_posts = new post * [new_size];
	for (int i = 0; i < new_size; i++)
	{
		updated_posts[i] = 0;
	}
	for (int i = 0; i < a->get_timeline_size() && i < new_size; i++)
	{
		updated_posts[i] = a->get_user_timeline()[i];
	}
	for (int i = 0; i < a->get_timeline_size(); i++)
	{
		a->get_user_timeline()[i] = 0;
		delete[]a->get_user_timeline()[i];
	}
	a->reset_user_timeline();
	delete[]a->get_user_timeline();
	a->initialize_timeline(new_size);
	for (int i = 0; i < new_size; i++)
	{
		if (i + 1 == new_size)
		{
			a->insert_post_timeline(i, b);
		}
		else
			a->insert_post_timeline(i, updated_posts[i]);
	}
	for (int i = 0; i < new_size; i++)
	{
		updated_posts[i] = 0;
		delete[]updated_posts[i];
	}
	updated_posts = 0;
	delete[]updated_posts;
	if (new_size > a->get_timeline_size())
	{
		a->set_timeline_size(a->get_timeline_size() + 1);
	}
	else
		a->set_timeline_size(a->get_timeline_size() + 1);

}
void SocialMediaApp::share_memory(sf::RenderWindow& window, sf::Font& font, char* temp, sf::Text& in, sf::Sprite& sprite, sf::Texture& texture3, sf::Texture& texture6)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(760.f, 470.f);

	stringstream s;

	sf::Text inputText2("", font, 50);
	inputText2.setFillColor(sf::Color::Black);
	inputText2.setPosition(860.f, 850.f);
	char* temp2 = new char[100];
	temp2[0] = '\0';
	sf::Event event;
	bool found = 0;
	bool exit = 0;
	for (int i = 0; i < current_user->get_timeline_size() && found == 0; i++)
	{
		if (temp1.mycompare(temp, current_user->get_user_timeline()[i]->get_postID()))
		{
			found = 1;
			found = 1;
			bool set = 0;
			while (set == 0 && exit == 0)
			{
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode < 128 && event.text.unicode != 8) // Allow ASCII characters except backspace and limit input length
						{
							size_t len = strlen(temp2);
							temp2[len] = static_cast<char>(event.text.unicode);
							temp2[len + 1] = '\0';
							inputText2.setString(temp2);
						}
						else if (event.text.unicode == 8 && strlen(temp2) > 0) // Handle backspace
						{
							temp2[strlen(temp2) - 1] = '\0';
							inputText2.setString(temp2);
						}
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
					{
						set = 1;
						temp2[strlen(temp2)] = '\0';
						inputText2.setString(temp2);
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					{
						exit = 1;
					}
					window.clear(sf::Color::White);
					sprite.setTexture(texture6);
					window.draw(sprite);
					window.draw(in);
					window.draw(inputText2);
					window.display();
				}
			}
		}
		if (found == 1 && exit == 0)
		{
			int new_size = total_posts + 1;
			reinitialize_posts(new_size);
			posts[total_posts] = new memory(temp2, current_user->get_user_timeline()[i], current_date);
			int r = current_user->get_timeline_size() + 1;
			resize_timeline(r, current_user, posts[total_posts]);
		}
	}
	if (found == 0)
	{
		s << "post not found in user timeline\n";
	}
	else
	{
		s << "Memory shared in respective user's timeline\n\n";
	}
	text.setString(s.str());

	// Draw the text on the SFML window
	if (exit == 0)
	{
		window.clear(sf::Color::White);
		sprite.setTexture(texture3);
		window.draw(sprite);
		window.draw(text);
	}
	delete[]temp2;

}
void SocialMediaApp::enter_line()
{
	cout << "----------------------------------------------------------------------------------------\n";
	cout << "----------------------------------------------------------------------------------------\n";
}
void SocialMediaApp::user_profile(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text text;
	int x = 60, y = 70;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(x, y);


	// Create a stringstream to construct the text
	std::stringstream ss;

	//cout << "Current user " << current_user->get_name() << "(" << current_user->get_objID() << ")" << endl;
	for (int i = 0; i < current_user->get_timeline_size(); i++, y += 250)
	{
		if (y > 700)
		{
			x += 700;
			y = 70;
		}
		print_post(window, current_user->get_user_timeline()[i][0], font, x, y);
	}
}
void SocialMediaApp::Print_friendlist(sf::RenderWindow& window, sf::Font& font, char* temp)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(760.f, 470.f);
	bool found = 0;
	stringstream ss;
	for (int j = 0; j < total_users; j++)
	{
		if (temp1.mycompare(temp, users[j]->get_objID()))
		{
			found = 1;
			for (int i = 0; i < users[j]->get_friendlist_size(); i++)
			{
				ss << "\n\nName : " << users[j]->get_friendlist()[i]->get_name() << " ID : " << users[j]->get_friendlist()[i]->get_objID();
			}
		}
		if (found == 1)
		{
			break;
		}
	}
	if (found == 0)
	{
		ss << "User ID incorrect or not found\n\n";
	}
	text.setString(ss.str());

	// Draw the text on the SFML window
	window.draw(text);
}
void SocialMediaApp::View_page(sf::RenderWindow& window, sf::Font& font, char* temp)
{
	sf::Text text;
	int x = 60, y = 70;
	text.setFont(font);
	text.setCharacterSize(25); // Set the font size
	text.setFillColor(sf::Color::Black);
	text.setPosition(x, y);


	// Create a stringstream to construct the text
	std::stringstream ss;
	bool found = 0;
	for (int i = 0; i < total_pages; i++)
	{
		if (temp1.mycompare(temp, pages[i]->get_objID()))
		{
			found = 1;
			for (int j = 0; j < pages[i]->get_timeline_size(); j++, y += 350)
			{
				if (y > 700)
				{
					x += 450;
					y = 70;
				}
				print_post(window, pages[i]->get_page_timeline()[j][0], font, x, y);
			}
		}
		if (found == 1)
		{
			break;
		}
	}
	if (found == 0)
	{
		ss << "Page ID incorrect or Page not found!\n ";
	}
	text.setString(ss.str());

	// Draw the text on the SFML window
	window.draw(text);
}


//method description for social entity class.
socialentity::socialentity() { objID; temp.key; name; }
socialentity:: ~socialentity()
{
	delete[]objID;
	objID = 0;
	delete[]name;
	name = 0;
}
char* socialentity::get_nameofentity() { return name; }
void socialentity::set_nameofentity(char* a) { temp.mycopy(name, a); }
char* socialentity::get_objID() { return objID; };
void socialentity::set_objID(char* id) { temp.mycopy(objID, id); }
void socialentity::set_objID(const char* id) { temp.mycopy(objID, id); }



// method description for page class
page::page(char* id, char* name)
{
	if (id != 0)
	{
		temp.mycopy(pageID, id);
		set_objID(id);
	}
	else
	{
		pageID = 0;
	}
	if (name != 0)
	{
		temp.mycopy(title, name);
		set_nameofentity(name);
	}
	else
	{
		title = 0;
	}
	owner = 0;
	page_timeline = 0;
	likes = 0;
	temp.key = 0;
	timeline_size = 0;
}
page::~page()
{
	delete[]pageID;
	delete[]title;
	owner = 0;
	for (int i = 0; i < timeline_size; i++)
	{
		page_timeline[i] = 0;
	}
	delete[]page_timeline;
	page_timeline = 0;
	timeline_size = 0;
	likes = 0;
}
int page::get_timeline_size()
{
	return timeline_size;
}
void page::increment_timeline_size()
{
	timeline_size++;
}
void page::set_timeline_size(int a) 
{
	timeline_size = a; 
}
void page::insert_post_timeline(int a, post* b)
{
	page_timeline[a] = b;

}
void page::initialize_timeline(int a)
{
	page_timeline = new post * [a];
	for (int i = 0; i < timeline_size; ++i)
	{
		page_timeline[i] = nullptr;
	}
}
char* page::get_pageID()
{
	return pageID;
}
char* page::get_title()
{
	return title;
}
user* page::get_owner()
{
	return owner;
}
void page::set_owner(user& a)
{
	owner = &a;
}
post** page::get_page_timeline()
{
	return page_timeline;
}

// method description for user class.
user::~user()
{
	delete[] userID;
	userID = nullptr;

	delete[] name;
	name = nullptr;

	if (friendlist != nullptr)
	{
		for (int i = 0; i < friendlist_size; i++)
		{
			friendlist[i] = 0;
		}
		delete[] friendlist;
		friendlist = nullptr;
	}

	if (pagesliked != nullptr)
	{
		for (int i = 0; i < pagesliked_size; i++)
		{
			pagesliked = 0;;
		}
		delete[] pagesliked;
		pagesliked = nullptr;
	}

	if (user_timeline != nullptr)
	{
		for (int i = 0; i < timeline_size; i++)
		{
			user_timeline[i] = 0;
		}
		delete[] user_timeline;
		user_timeline = nullptr;
	}
}
char* user::get_userID() { return userID; };
char* user::get_name() { return name; };
user** user::get_friendlist() { return friendlist; };
void user::set_pagesliked(int& a) { pagesliked = new page * [a]; pagesliked_size = a; };
int user::get_timeline_size() { return timeline_size; }
int user::get_pagesliked_size() { return pagesliked_size; }
int user::get_friendlist_size() { return friendlist_size; }
void user::set_friendlist_size(int a) { timeline_size = a; }
void user::set_timeline_size(int a) { timeline_size = a; }
void user::increment_timeline_size() { timeline_size++; }
void user::insert_post_timeline(int a, post* b)
{
	user_timeline[a] = b;
}
void user::initialize_timeline(int a)
{
	user_timeline = new post * [a];
	for (int i = 0; i < timeline_size; ++i)
	{
		user_timeline[i] = nullptr;
	}
}
page** user::get_pagesliked() { return pagesliked; };
post** user::get_user_timeline() { return user_timeline; };
void user::reset_user_timeline() { user_timeline = 0; };
user::user(char* id , char* nam )
{
	temp.key = 1;
	friendlist_size = 0;
	timeline_size = 0;
	if (id != 0)
	{
		temp.mycopy(userID, id);
		set_objID(id);
	}
	else
	{
		userID = 0;
	}
	if (nam != 0)
	{
		temp.mycopy(name, nam);
		set_nameofentity(nam);
	}
	else
	{
		name = 0;
	}
	friendlist = 0;
	pagesliked = 0;
	user_timeline = 0;
}
void user::set_friendlist(int& a)
{

	friendlist = new user * [a];
	friendlist_size = a;
}

//method description for post class.

post::~post()
{
	delete[]postID;
	postID = 0;
	delete[]description;
	description = 0;
	if (memory_description != 0)
	{
		delete[]memory_description;
		memory_description = 0;


	}
	activity.~Activity();
	owner = 0;
	for (int i = 0; i < comment_size; i++)
	{
		delete comment[i];
	}
	delete[]comment;
	comment = 0;
	comment_size = 0;
	for (int i = 0; i < liked; i++)
	{
		social_liked[i] = 0;
	}
	delete[]social_liked;
	social_liked = 0;
	liked = 0;
}
char* post::get_memory_description()
{
	return memory_description;
}
bool post::get_memory_exists()
{
	return memory_exists;
}
void post::set_memory_description(char* a)
{
	temp.mycopy(memory_description, a);
	memory_exists = 1;
}
char* post::get_postID() { return postID; };
char* post::get_description() { return description; };
socialentity* post::get_owner() { return owner; };
date& post::get_postDate() { return postDate; };
comments** post::get_comment() { return comment; };
void post::initialize_comment()
{
	comment = new comments * [10];
	for (int i = 0; i < 10; i++)
	{
		comment[i] = new comments();
	}
}
Activity& post::get_activity() { return activity; };
socialentity** post::get_social_liked() { return social_liked; };
void post::set_social_liked()
{
	social_liked = new socialentity * [10];
	for (int i = 0; i < 10; ++i)
	{
		social_liked[i] = 0;
	}
};
void post::increment_liked()
{
	liked++;
}
int post::get_liked() { return liked; };
void post::set_liked(int a) { liked = a; };
post::post(char* id, char* name)
{
	memory_exists = 0;
	memory_description = 0;
	activity.set_type(0);
	//activity.set_value(0);
	comment_size = 0;
	if (id != 0)
	{
		temp.mycopy(postID, id);
	}
	else
	{
		postID = 0;
	}
	if (name != 0)
	{
		temp.mycopy(description, name);
	}
	else
	{
		description = 0;
	}
	owner = 0;
	comment = 0;
	social_liked = 0;
	temp.key = 0;
	liked = 0;

}
void post::set_postID(char* a)
{
	temp.mycopy(postID, a);
}
void post::set_description(char* a) { temp.mycopy(description, a); };
void post::set_owner(socialentity& obj)
{
	owner = &obj;
}
void post::set_owner(page& obj)
{
	owner = (socialentity*)&obj;
}
int post::get_comment_size() { return comment_size; }
void post::set_comment_size(int a) { comment_size = a; }
void post::increment_comment_size() { comment_size++; }
void post::link_comment(int i, comments* a)
{
	this->comment[i] = a;
}
void post::link_socialliked(int i, socialentity* a)
{
	this->social_liked[i] = a;
}
void post::initialize_socialliked(int i)
{
	social_liked = new socialentity * [i];
}
char* post::give_activity()
{
	char* temp1 = new char[100];
	if (activity.get_type() == 1)
	{
		temp.mycopy(temp1, "feeling");
		return temp1;
	}
	if (activity.get_type() == 2)
	{
		temp.mycopy(temp1, "thinking about");
		return temp1;
	}
	if (activity.get_type() == 3)
	{
		temp.mycopy(temp1, "making");
		return temp1;
	}
	if (activity.get_type() == 4)
	{
		temp.mycopy(temp1, "celebrating");
		return temp1;
	}
}

//description for helper class.
int helper::mylen(char*& a)
{
	int i = 0;
	for (; a[i] != '\0'; i++)
	{
	}
	i++;
	return i;
}
int helper::mylen(const char*& a)
{
	int i = 0;
	for (; a[i] != '\0'; i++)
	{
	}
	i++;
	return i;
}
void helper::mycopy(char*& a, char*& b)
{
	//a destination , b source.
	int k = mylen(b);
	a = new char[k];
	for (int i = 0; i < k; i++)
	{
		a[i] = b[i];
	}
}
void helper::mycopy(char*& a, const char* b)
{
	//a destination , b source.
	int k = mylen(b);
	a = new char[k];
	for (int i = 0; i < k; i++)
	{
		a[i] = b[i];
	}
}
bool helper::mycompare(char*& a, char* b)
{
	int size = mylen(a) - 1;
	for (int i = 0, k = 0; i < size; i++)
	{
		if (a[i] == b[i])
		{
			k++;
		}
		if (k == size)
		{
			return 1;
		}
	}
	return 0;
}
bool helper::mycompare(char*& a, const char* b)
{
	int size = mylen(a) - 1;
	for (int i = 0, k = 0; i < size; i++)
	{
		if (a[i] == b[i])
		{
			k++;
		}
		if (k == size)
		{
			return 1;
		}
	}
	return 0;
}
char*& helper::addstrings(char* a, char* b)
{
	char* temp = new char[100];
	int i = 0, k = 0;
	for (; i < mylen(a); i++)
	{
		temp[i] = a[i];
	}
	for (; i < mylen(b); i++, k++)
	{
		temp[i] = b[k];
	}
	return temp;
}
char*& helper::addstrings(const char* a, char* b)
{
	char* temp = new char[100];
	int i = 0, k = 0;
	for (; i < mylen(a) - 1; i++)
	{
		temp[i] = a[i];
	}
	for (; k < mylen(b); i++, k++)
	{
		temp[i] = b[k];
	}
	return temp;
}

//method description for date.h class
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}
int date::get_day() { return day; }
int date::get_month() { return month; }
int date::get_year() { return year; }
void date::set_day(int a) { day = a; }
void date::set_month(int a)
{
	month = a;
}
void date::set_year(int a) { year = a; }

//method description for Activity class.

Activity::Activity()
{
	type = 0;
	value = 0;
}
Activity::~Activity()
{
	delete[]value;
	value = 0;
}
int Activity::get_type() { return type; }
char* Activity::get_value() { return value; }
void Activity::set_type(int a) { type = a; }
void Activity::set_value(char* a) { temp.mycopy(value, a); }


//method description for memory class.
post* memory::get_linked_post()
{
	return linked_post;
}
memory::~memory()
{
	linked_post = 0;
}
memory::memory(char* a, post* obj, date b)
{
	set_memory_description(a);
	linked_post = obj;
	set_postID(linked_post->get_postID());
	set_description(linked_post->get_description());
	set_comment_size(linked_post->get_comment_size());
	set_owner(*linked_post->get_owner());
	get_postDate().set_day(b.get_day());
	get_postDate().set_month(b.get_month());
	get_postDate().set_year(b.get_year());
	set_liked(linked_post->get_liked());
	initialize_comment();
	for (int i = 0; i < get_comment_size(); i++)
	{
		link_comment(i, linked_post->get_comment()[i]);
	}
	get_activity().set_type(linked_post->get_activity().get_type());
	if (get_activity().get_type() != 0)
	{
		get_activity().set_value(linked_post->get_activity().get_value());
	}
	initialize_socialliked(linked_post->get_liked());
	for (int i = 0; i < linked_post->get_liked(); i++)
	{
		link_socialliked(i, linked_post->get_social_liked()[i]);
	}

}

// method description for commnet class.
comments::~comments()
{
	delete[]comment_id;
	comment_id = 0;
	published_on_post = 0;
	owner = 0;
	delete[]description;
	description = 0;
}
char* comments::get_comment_id() { return comment_id; }
void comments::set_comment_id(char* a) { temp.mycopy(comment_id, a); }
post* comments::get_published_on_post() { return published_on_post; }
void comments::set_published_on_post(post& a) { published_on_post = &a; }
socialentity* comments::get_owner() { return owner; }
void comments::set_owner(socialentity& a) { owner = &a; }
char* comments::get_description() { return description; }
void comments::set_description(char*& a) { temp.mycopy(description, a); }