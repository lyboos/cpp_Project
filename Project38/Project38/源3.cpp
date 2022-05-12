#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include <vector>

using namespace std;

void split(string*& info, string str, char ch) {
	string temp = ""; int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == ch) {
			info[count] = temp;
			temp = "";
			count++;
		}
		else {
			temp += str.at(i);
		}
	}
}