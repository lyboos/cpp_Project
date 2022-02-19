#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"socketClient.h"

void print_array(int* arr,int len) {
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

void select_sort(int* a, int len) {
	int i;
	for (i = 0; i < len - 1; i++) {
		int j;
		for (j = i + 1; j < len; j++)
		{
			if (a[j] < a[i]) {
				a[i] = a[j] ^ a[i];
				a[j] = a[j] ^ a[i];
				a[i] = a[j] ^ a[i];
			}
		}
	}
}

int main() {
	/*printf("lyboos/n");
	system("pause");*/
	//Ñ¡ÔñÅÅÐò
	int a[] = { 33,56,74,21,45,85,69,3 };
	int len = sizeof(a) / sizeof(a[0]);
	int i = 0;
	print_array(a, len);
	printf("\n");
	select_sort(a, len);
	print_array(a, len);
	return 0;
}