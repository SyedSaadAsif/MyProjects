using namespace std;
#include<iostream>
#include"SocialMediaApp.h"
#include"User.h"
#include"Page.h"
#include"post.h"
#include"date.h"
#include"comments.h"
#include"activity.h"
#include"memory.h"
#include"SFML/Graphics.hpp"

int main()
{
    
  SocialMediaApp App;
  App.readInitialData();
  App.run();
  cout << endl;
  system("pause");
	return 0;
}