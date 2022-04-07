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