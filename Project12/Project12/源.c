#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	char a = '8';
	char b = '\n';
	int c = 0;
	printf("%c%c\n%d", a, b, c);
}
//{
//	double e=1,i,jiecheng=1;
//	int n;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		jiecheng = jiecheng*i;
//		e =e+ (1 / jiecheng);
//	}
//	printf("eԼΪ%f", e);
//	return 0;
//}
//{
//	int n;
//	double sum = 0;
//	scanf("%d", &n);
//	for (double j = 1; j <= n; j++)
//	{
//		int i = j;
//		if (i% 2 == 1)
//			sum = sum + 4 / (2*j - 1);
//		else
//			sum = sum - 4 / (2*j - 1);
//	}
//	printf("������ֵΪ%f", sum);
//}
//{
//	int n;
//	scanf("%d", &n);
//	for (int j = 1; j <= n; j++)
//	{
//		for (int i = 1; i <= j; i++)
//		{
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//}
//{
//	int sum=1,n = 9;
//	while (n > 0)
//	{
//		sum = sum * n;
//		n--;
//	}
//	printf("%d", sum);
//}
////{
//	int c,n,a=1,b=1;
//	scanf("%d", &n);
//	for (c = 0; n > 1; n--)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d", a);
//}
////int main()
//{
//	int a, b;
//	printf("���������Եõ�����\n");
//	scanf("%d %d", &a, &b);
//	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
//		printf("%d", 31);
//	else if (b == 2 && a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
//		printf("%d", 29);
//	else if (b == 2)
//		printf("%d", 28);
//	else printf("%d", 30);
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		printf("%d", a);
//	}
//	else
//	{
//		printf("%d", b);
//	}
//	return 0;
//}
//int main()
//{
//	char result;
//	int input;
//	printf("Input an integer:");
//	scanf("%d", &input);
//	if (input % 7 != 0)
//	{
//		printf("F");
//	}
//	else {
//		printf("T");
//	}
//}
//int main()
//{
//	int a = 7, b = 8;
//	a = a * b;
//	b = a / b;
//	a = a / b;
//	return 0;
//}
//int main(void)
//{
//    int a, b,c;
//    scanf("%d %d", &a, &b);
//    c = (a > b )?a:b;
//    printf("\n%d", c);
//}
////char m = '\n';
//printf("%c", m);
/*
int n;
double m;
scanf("%lf", &m);
n =5/35*1000*m/0.001/350;
printf("%d", n);
return 0;*/
//��Ƴ������һ��mλ������n�ĵ�kλ�������������֣����У�k = m / 2��m > 1��
//���磬49��һ��2λ�������1λ����Ϊ9��89532��һ��5λ�������2λ����Ϊ3��
//��Ҫ��ֱ��ú���int CountDigit(int n)��int KthDigit(int n, int k)ʵ�� n ��λ�� m �͵� k λ���ֵ���⹦�ܣ����Ժ����Ķ��塢���ü���������ע�͡���
//int qushu(int a, int b)
//{
//	int n = b / 2;
//	for (; n >=0; n--)
//	{
//		a = a / 10;
//	}
//	if (n / 10 == 0) return a % 10;
//	else return 0;
//}
//int shushu(int a)
//{
//	int i ;
//	for (i = 1; a >=10; i++)
//	{
//		a=a / 10;
//	}
//	return i;
//}
//int main()
//{
//	int a,b,c;
//	scanf("%d", &a);
//	b=shushu(a);
//	c=qushu(a, b);
//	printf("%d��%dλ����%dλ����%d", a, b, b / 2, c);
//	return 0;
//}
