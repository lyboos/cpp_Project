#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"stddef.h"
#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name) 
struct MyStruct
{
	char c1;
	int a;
	char c2;
};

int main()
{
	//printf("%d\n", OFFSETOF(struct MyStruct,c1));
	//printf("%d\n", OFFSETOF(struct MyStruct,a));
	//printf("%d\n", OFFSETOF(struct MyStruct,c2));
	int i = 65531;
	if(i==(int)(float)i)
		printf("yes");
	unsigned short a = 32769;
	short b = a;
	return 0;
}
//#define SQUARE(X) X*X
////#define PRINT(X) printf("the value of "#X" is %d\n",X)
//#define DEBUG
//int main()
//{
//	int num = 99;
//	//printf("%d\n%d\n", SQUARE((5+1)), SQUARE(5+1));
//#ifdef DEBUG
//	printf("%d\n", num);
//#else
//	PRINT(num);
//#endif // DEBUG
//#ifndef DEBUG
//	PRINT(num);
//#elif !defined(PRINT)
//	printf("%d\n", num);
//#endif // !DEBUG
//
//	return 0;
//}
//#define MAX_INT 224400000
//#define STR "lyboos"
//#define do_forever for(;;)
//#define write_log fprintf(pf, "%s\t\t%s\t\t    \
//									%s\t\t%ld\t\tcount:%d\n",   \
//								 __FILE__, __DATE__, __TIME__, __LINE__		\
//													,arr[i]+1);
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char roman[100];
//	int sum = 0;
//	scanf("%s", roman);
//	int i = 0, a = strlen(roman);
//	for ( i = 0; i < a; i++)
//	{
//		switch (roman[i])
//		{
//		case 'I':
//			if (roman[i + 1] == 'V')
//			{
//				i++;
//				sum += 4;
//			}
//			else if (roman[i + 1] == 'X')
//			{
//				i++;
//				sum += 9;
//			}
//			else {
//				sum += 1;
//			}
//			break;
//		case 'V':
//			sum += 5;
//			break;
//		case 'X':
//			if (roman[i + 1] == 'C')
//			{
//				i++;
//				sum += 90;
//			}
//			else if (roman[i + 1] == 'L')
//			{
//				i++;
//				sum += 40;
//			}
//			else {
//				sum += 10;
//			}
//			break;
//		case 'L':
//			sum += 50;
//			break;
//		case 'C':
//			if (roman[i + 1] == 'D')
//			{
//				i++;
//				sum += 400;
//			}
//			else if (roman[i + 1] == 'M')
//			{
//				i++;
//				sum += 900;
//			}
//			else {
//				sum += 10;
//			}
//			break;
//		case 'D':
//			sum += 500;
//			break;
//		case 'M':
//			sum += 1000;
//			break;
//		default:
//			break;
//		}
//	}
//	if(i==a-1)
//		switch (roman[i])
//		{
//		case 'I':
//			if (roman[i + 1] == 'V')
//			{
//				i++;
//				sum += 4;
//			}
//			else if (roman[i + 1] == 'X')
//			{
//				i++;
//				sum += 9;
//			}
//			else {
//				sum += 1;
//			}
//			break;
//		case 'V':
//			sum += 5;
//			break;
//		case 'X':
//			if (roman[i + 1] == 'C')
//			{
//				i++;
//				sum += 90;
//			}
//			else if (roman[i + 1] == 'L')
//			{
//				i++;
//				sum += 40;
//			}
//			else {
//				sum += 10;
//			}
//			break;
//		case 'L':
//			sum += 50;
//			break;
//		case 'C':
//			if (roman[i + 1] == 'D')
//			{
//				i++;
//				sum += 400;
//			}
//			else if (roman[i + 1] == 'M')
//			{
//				i++;
//				sum += 900;
//			}
//			else {
//				sum += 10;
//			}
//			break;
//		case 'D':
//			sum += 500;
//			break;
//		case 'M':
//			sum += 1000;
//			break;
//		default:
//			break;
//		}
//	printf("num:%d\n", sum);
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	int c=2;
//	a *= c + 1;
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	printf("%s\n", STR);
//	printf("%d\n",MAX_INT);
//	printf("%s\n%s\n", __FILE__, __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%ld", __LINE__);
//	FILE* pf = fopen("log.txt", "w");
//	int i = 0, arr[10] = { 0 };
//	for ( i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "%s\t\t%s\t\t%s\t\t%ld\t\tcount:%d\n", __FILE__, __DATE__, __TIME__, __LINE__,arr[i]+1);
//		printf("\n%s\n", __FUNCTION__);
//		printf("%d", __STDC_HOSTED__);
//	}
//	fclose(pf);
//	pf = NULL;
//	int b = 10, a = !b == 10 == 0 == 1;
//	printf("%d", a);
//	return 0;
//}