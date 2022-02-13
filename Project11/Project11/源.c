#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<Windows.h>
//int main()
//{
//	int arr[][4] = { {1,2,3,4},{4,4,4,4},{4,3,2,1} };
//	for (int i = 0; i < 3;i++)
//	{
//		int n = 0;
//		for (; n < 4; n++) 
//		{
//			printf("%d\t", arr[i][n]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//void maopao(int ly[],int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int n = 0;
//		int jc = 1;
//		for (; n < sz-1; n++)
//		{
//			if (ly[n] > ly[n + 1]) {
//				int jy = ly[n];
//				ly[n] = ly[n + 1];
//				ly[n + 1] = jy;
//				jc = 0;
//			}
//		}
//		if (jc == 1) break;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", ly[i]);
//	}
//
//}
//int main()
//{
//	int arr[] = { 8,1,2,3,4,5,6,7,9,10 };
//	int t = sizeof(arr)/sizeof(arr[0]);
//	maopao(arr,t);
//	return 0;
//}
//int main()
//{
//	int a = 0, b = 0,f=0;
//	scanf("%d\n%d",&a,&b);
//	for (;a< 366; a+=3)
//	{
//		for (; b < 366; b += 7)
//		{
//			if (a == b)
//			{
//				f = 1;
//				break;
//			}
//		}	
//	}
//	if (f == 1)printf("Y\n");
//	else printf("N\n");
//	return 0;
//}
//int fbnq(int n)
//{
//	if (n == 2 || n == 1)
//		return 1;
//	else
//	{
//	return n= fbnq(n - 1) + fbnq(n - 2);
//	}
//}
//int main()
//{
//	int a,n = 0;
//	scanf("%d", &n);
//	a=fbnq(n);
//	printf("\n%d", a);
//	return 0;
//}
//int main()
//{
//	int i;
//	int j;
//	for (i = 4; i >= 0; i--) {
//		Sleep(500);
//		for (j = 1; j <= i; j++)
//			printf("#");
//		for (j = 1; j <= 4 - i; j++)
//			printf("*");
//		printf("\n");
//	}
//	return 0;
//}
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%dÊ±%d·Ö%dÃë", a/3600,a/60%60,a%60);
	return 0;
}