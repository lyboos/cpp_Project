#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

struct ly
{
	char c1;
	int b;
	int a[20];
	char c3;
};

struct yl
{
	double a;
	char c;
	int b;
};
int main()
{
	struct ly lpn = { 0 };
	struct yl npl = { 0 };
	printf("%d\n%d", sizeof(lpn),sizeof(npl));
	return 0;
}
//typedef struct lpn
//{
//	char a;
//	char name[20];
//	int age;
//}lpn;
//
//struct node
//{
//	int data;
//	struct node* next;
//};
//int main()
//{
//	lpn l13 = { 0 };
//	struct node ly = { 0 };
//	printf("%d\n%d", sizeof(ly),sizeof(l13));
//	return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char s[100][80] = { 0 };
//	double a[100] = { 0 };
//	int i, j, max = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("\n");
//		gets(s[i]);
//		scanf("%lf", &a[i]);
//	}
//	for (j = 0; j < n; j++)
//	{
//		if (a[j] < a[max])
//			max = j;
//	}
//	printf("%.2f,%s",a[max],s[max] );
//	return 0;
//}








//int main()
//{
//	int num = 0, counter,tem,i=0,line[1000] = { 0 };
//	scanf("%d", &num);
//	for (counter = 0; counter < num; counter++)
//	{
//		scanf("%d", &line[counter]);
//	}
//	for (counter = 0; counter < num; counter++)
//	{
//		for (tem = 1; tem<= line[counter]; tem++)
//		{
//			for (i = 0; i < line[counter]-tem; i++)
//			{
//				printf(" ");
//			}
//			i = 0;
//			int flag = 1;
//			do{
//				if (flag)
//				{
//					printf("%c", 'a' + i);
//					i++;
//				}
//				else {
//					i--;
//					printf("%c", 'a' + i);
//				}
//				if (i == tem)
//				{
//					i--;
//					flag = 0;
//				}
//			} while (i);
//			printf("\n");
//		}
//		for (tem = line[counter]; tem>0 ; tem--)
//		{
//			for (i = 0; i < line[counter]-tem; i++)
//				printf(" ");
//			printf("a");
//			for (i = 0; i <(2*tem-3); i++)
//				printf(" ");
//			if (tem > 1) printf("a");
//			printf("\n");
//		}
//		printf("\n");
//	}
//	return 0;
//}