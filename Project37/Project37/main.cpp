#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

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