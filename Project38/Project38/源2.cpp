#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
using namespace std;

void setheader(string& str, int size,bool iswrite) {
	int headnum = (size -8)/8;
	headnum = headnum >> 1;
	str = to_string(headnum);
	if (iswrite)
		str += "9";
	else
		str += "8";
	while (str.length()<8)
	{
		str = "0" + str;
	}
}

void setnormal(string& str) {
	str = "dfdfdfdf";
}

void split(string* &set,string str,char ch) {
	string temp = ""; int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == ch) {
			set[count] = temp;
			temp = "";
			count++;
		}
		else 
		 temp += str.at(i);
	}
}


//int main() {
//	int size = 0, maxBlock = 0;
//	cin >> size >> maxBlock;
//
//	string* map = new string[size/4];
//	for (int i = 0; i < size/4; i++)
//	{
//		if (i == 0 || size / 4-1 == i)
//			setheader(map[i], size,false);
//		else
//			setnormal(map[i]);
//	}
//	int numOrder = 0,count=0;
//	cin >> numOrder;
//	string* order = new string[numOrder];
//	for (int i = 0; i < numOrder; i++)
//	{
//		cin >> order[i];
//	}
//	
//	for (int i = 0; i < numOrder; i++)
//	{
//		char option = order[i][0];
//		switch(option)
//		{
//		case 'A':
//			string* orderstr=new string[3];//创建一个存储string类型的vector;
//			split(orderstr, order[i], ' ');
//			
//			if (count >= maxBlock) {
//				cout << "failed to alloc object " <<orderstr[1]<< endl;
//			}
//			else {
//				int block = atoi(orderstr[2].c_str());
//				while (block % 8 != 0) {
//					block++;
//				}
//				block /= 4; block += 2;
//				cout << "succeeded to alloc object " << orderstr[2] << endl;
//				count++;
//			}
//			break;
//		case 'F':
//			cout << "f";
//			break;
//		case 'S':
//			for (int i = 0; i < size / 4; i++)
//			{
//				cout << map[i] << endl;
//			}
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}