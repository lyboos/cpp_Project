#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	vector<string> addAlpha(vector<string> res, string src) {
		vector<string> result;
		if (res.size() == 0) {
			for (char c : src) {
				string temp = string(1,c);
				result.push_back(temp);
			}
			return result;
		}
		for (string temp : res) {
			for (char c : src) {
				result.push_back(temp + c);
			}
		}
		return result;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		for (char c : digits) {
			switch (c-'2')
			{
			case 0://abc
				res=addAlpha(res, "abc");
				break;
			case 1://def
				res=addAlpha(res, "def");
				break;
			case 2://ghi
				res=addAlpha(res, "ghi");
				break;
			case 3://jkl
				res=addAlpha(res, "jkl");
				break;
			case 4://mno
				res=addAlpha(res, "mno");
				break;
			case 5://pqrs
				res=addAlpha(res, "pqrs");
				break;
			case 6://tuv
				res=addAlpha(res, "tuv");
				break;
			case 7://wxyz
				res=addAlpha(res, "wxyz");
				break;
			default:
				break;
			}
		}
		return res;
	}

	string intToRoman(int num) {
		string res = "";
		int counth = 0,countt = 0,counti = 0;
		while (num>0)
		{
			if (num >= 1000) {
				res += 'M';
				num -= 1000;
			}
			else if (num >= 900) {
				res += "CM";
				num -= 900;
			}
			else if (num >= 500) {
				res += "D";
				num -= 500;
			}
			else if (num >= 400) {
				res += "CD";
				num -= 400;
			}
			else if (num >= 100) {
				res += "C";
				num -= 100;
			}
			else if (num >= 90) {
				res += "XC";
				num -= 90;
			}
			else if (num >= 50) {
				res += "L";
				num -= 50;
			}
			else if (num >= 40) {
				res += "XL";
				num -= 40;
			}
			else if (num >= 10) {
				res += "X";
				num -= 10;
			}
			else if (num >= 9) {
				res += "IX";
				num -= 9;
			}
			else if (num >= 5) {
				res += "V";
				num -= 5;
			}
			else if (num >= 4) {
				res += "IV";
				num -= 4;
			}
			else{
				res += "I";
				num --;
			}
		};
		return res;
	}

	bool isIsomorphic(string s, string t) {
		int arr1[256],arr2[256];
		for (int i = 0; i < 256; i++)
		{
			arr1[i] = -1;
			arr2[i] = -1;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (arr1[s.at(i)]==-1&&arr2[t.at(i)]==-1) {
				arr1[s.at(i)] = t.at(i);
				arr2[t.at(i)] = s.at(i);
			}
			else {
				if (arr1[s.at(i)] != t.at(i)|| arr2[t.at(i)] != s.at(i))
					return false;
			}
		}
		return true;
	}

	bool isHappy(int n) {
		int fast = n;
		int slow = n;
		do {
			slow = squareSum(slow);
			fast = squareSum(fast);
			fast = squareSum(fast);
		} while (slow != fast);
		if (fast == 1)
			return true;
		else return false;
	}

	int squareSum(int m) {
		int squaresum = 0;
		while (m != 0) {
			squaresum += (m % 10) * (m % 10);
			m /= 10;
		}
		return squaresum;
	}

	vector<int> numberOfLines(vector<int>& widths, string s) {
		int length = 0,count=0;
		for (char c : s) {
			int simple = widths[c - 'a'];
			if (simple+length >= 100) {
				length = 0;
				count++;
			}
			length += simple;
		}
		vector<int> res;
		res.push_back(count+1);
		res.push_back(length);
		return res;
	}

	int majorityElement(vector<int>& nums) {
		int res = -9999,count=1;
		for (int i : nums) {
			if (i == res) count++;
			else count--;
			if (count == 0) res = i;
		}
		return res;
	}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headB == NULL || headA == NULL) return NULL;
		ListNode* temp1 = NULL;
		vector<ListNode*> arr1,arr2;
		while (headB != NULL)
		{
			arr1.push_back(headB);
			headB = headB->next;
		}
		while (headA != NULL)
		{
			arr2.push_back(headA);
			headA = headA->next;
		}
		for (ListNode* b:arr1)
		{
			for (ListNode* a : arr2) {
				if (a == b) return a;
			}
		}
		return NULL;
	}

	bool rotateString(string s, string goal) {
		if (s == goal) return true;
		int len1 = s.length();
		int len2 = goal.length();
		if (len1 != len2) return false;
		string temp = s;
		for (int i = 0; i < len1; i++)
		{
			temp = temp.substr(1) + temp.at(0);
			if (temp == goal) return true;
		}
		return false;
	}
	bool hasCycle(ListNode* head) {
		if (head->next == NULL)
			return false;
		vector<ListNode*> arr;
		while (head->next!=NULL)
		{
			arr.push_back(head);
			head = head->next;
			for (ListNode* temp:arr)
			{
				if (temp == head->next)
					return true;
			}
		}
		return false;
	}
};

struct teacher {
	int id;
	char name[64];
};

int get_mem1(teacher** tpp) {
	teacher* tp = NULL;
	tp = (teacher*)malloc(sizeof(teacher));
	if (tp == NULL) {
		return -1;
	}
	tp->id = 613;
	strcpy(tp->name, "lyboos");
	*tpp = tp;
	return 0;
}

void free_teacher1(teacher** tpp) {
	if (tpp == NULL)
		return;
	teacher* tp = *tpp;
	if (tp != NULL) {
		free(tp);
		*tpp = NULL;
	}
}

int get_mem2(teacher*& tp) {
	tp = (teacher*)malloc(sizeof(teacher));
	if (tp == NULL)
		return -1;
	tp->id = 123;
	strcpy(tp->name, "sadsada");
	return 0;
}

void free_teacher2(teacher*& tp) {
	if (tp != NULL) {
		free(tp);
		tp = NULL;
	}
}

int main() {
	
	/*teacher* p = NULL;
	get_mem1(&p);
	cout << p->id << ":" << p->name << endl;
	free_teacher1(&p);
	get_mem2(p);
	cout << p->id << ":" << p->name << endl;
	free_teacher2(p);*/
	/*int a = 613;
	int& temp = a;
	temp = 5;
	cout << a << endl;
	cin >> temp;
	cout << a << endl;*/
	return 0;
}