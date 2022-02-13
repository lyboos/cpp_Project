#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
//int countbitone(unsigned int i)
//{
//	int n = 0;
//	for (int a= 0; a < 32; a++)
//	{
//		if ((i >> a) & 1 == 1)
//			n++;
//	}
//	/*while (i)
//	{
//		if (i % 2)
//			n++;
//		i = i / 2;
//	}*/
//	return n;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int count = countbitone(a);
//	printf("%d", count);
//	return 0;
//}
//int bijiao(int a, int b)
//{
//	int n = 0, tem = a ^ b;
//	while (tem)
//	{
//		tem=tem& (tem - 1);
//		n++;
//	}
//	return n;
//}
//int main()
//{
//	int a, b;
//	scanf("%d\n%d", &a, &b);
//	int count = bijiao(a, b);
//	printf("%d", count);
//	return 0;
//}
//void bitprinit(n)
//{
//	for (int i = 31; i >=0; i = i - 2)
//	{
//		printf("%d", 1  & (n>>i));
//	}
//	printf("\n");
//	for (int i = 30; i >=0; i=i-2)
//	{
//		printf("%d", 1 & (n>>i));
//	}
//}
//int main()
//{
//	int m;
//	scanf("%d", &m);
//	bitprinit(m);
//	return 0;
//}



//print(int* p, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8 };
//	int n = sizeof(a) / sizeof(a[0]);
//	print(a, n);
//	return 0;
//}
//void board(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1;  j<=i; j++)
//		{
//			printf("%d*%d=%-3d ",i,j, i * j);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	board(a);
//	return 0;
//}
//reverse(char arr[])
//{
//	char tem = arr[0];
//	int len = strlen(arr);
//	arr[0] = arr[len- 1];
//	arr[len - 1] = '\0';
//	if(strlen(arr+1)>2)
//	reverse(arr + 1);
//	arr[len - 1] = tem;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
//int digsum(unsigned int n)
//{
//	if (n > 9)
//		return n % 10 + digsum(n / 10);
//	else return n%10;
//}
//int main()
//{
//	unsigned int a = 0;
//	scanf("%d", &a);
//	printf("%d", digsum(a));
//	return 0;
//}
//int detection(int a)
//{
//	int b = a / 100, c = a/10-b*10, d = a % 10;
//	if (pow(b, 3) + pow(c, 3) + pow(d, 3) == a)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (detection(a))
//		printf("%d是水仙花数", a);
//	return 0;
//}
//typedef struct ly
//{
//	char name[];
//	struct ZYS;
//}ly;
//int main()
//{
//	ly liuyang = {"lyboos"};
//    ly *p = &liuyang;
//	printf("%s\n", p->name);
//	printf("%s", liuyang.name);
//	return 0;
//}
#include<stdio.h>
int main()
{
	char a[99];
	int n = 0,c=0;
	scanf("%s", a);
	while (a[c]!='\0')
	{
		int b = 0;
		if (a[c] == 'i')
		b++;
		if (a[c + 1] == 'n')
			b++;
		if (a[c + 2] == 't')
			b++;
		if (b == 3)
			n++;
		c++;
	}
	printf("%d个int", n);
	return 0;
}