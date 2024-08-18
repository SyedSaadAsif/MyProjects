#pragma once
#include<iostream>
using namespace std;
class helper
{
public:
	int key;
	int mylen(char*& a);
	void mycopy(char*& a, char*& b);
	int mylen(const char*& a);
	void mycopy(char*& a, const char* b);
	bool mycompare(char*& a, char* b);
	bool mycompare(char*& a, const char* b);
	char*& addstrings(char* a, char* b);
	char*& addstrings(const char* a, char* b);

};
