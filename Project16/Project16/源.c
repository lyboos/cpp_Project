#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int* p=NULL;
//	char arr[10] = {'0','1','2','3','4','5','6','7','8','9' };
//	printf("%d\n", arr[9] - arr[0]);
//	printf("%x", p);
//	return 0;
//}
//int mystrlen(char* bbb)
//{
//	char* start = bbb;
//	char* end = bbb;
//	while (*end!='\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	char arr[] = "bitch";
//	printf("%d\n", mystrlen(arr));
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	printf("%d\n%x\n%x", **ppa, pa, ppa);
//	return 0;
////}
//void init(int bbb[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		bbb[i] = i;
//	}
//}
void print(char bbb[],int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%c",bbb[i]);
	}
}
//void reverse(int bbb[], int n)
//{
//	int left = 0, right = n - 1;
//	while (left<right)
//	{
//		int a = bbb[left];
//		bbb[left] = bbb[right];
//		bbb[right] = a;
//		left++;
//		right--;
//	}
//}
//int main()
void reverse(char a[], char b[],int i)
{
	int  n;
	char m;
	for (n = 0; n < i; n++)
	{
		m = a[n];
		a[n] = b[n];
		b[n] = m;
	}
}
int main()
{
	char a[20];
	char b[20];
	scanf("%s", a);
	scanf("%s", b);
	int i = strlen(a);
	reverse(a, b,i);
	print(a, i);
	printf("\n");
	print(b, i);
	return 0;
}