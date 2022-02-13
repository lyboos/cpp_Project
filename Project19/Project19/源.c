#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
//
//int inverse(int n);
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    while (n != inverse(n))
//    {
//        printf("%d ", n);
//        n += inverse(n);
//    }
//    printf("%d ", n);
//    return 0;
//}
//int inverse(int n)
//{
//    int a, b;
//    a = 0;
//    b = 0;
//    while (n != 0)
//    {
//        a = n % 10;
//        b = (a + b) * 10;
//        n = n / 10;
//    }
//    b /= 10;
//    return b;
//}
//#include <stdio.h>
//int huiwen(long n)
//{
//	long int a, b = 0, m;
//	m = n;
//	while (n > 0) {
//		a = n % 10;
//		n = n / 10;
//		b = b * 10 + a;
//	}
//	return b;
//}
//
//int fun(long n, long* hw)
//{
//	long int i;
//	for (i = 0; i < 10000 && n != huiwen(n); i++)
//		n += huiwen(n);
//	if (n != huiwen(n))
//		return -1;
//	else
//		*hw = n;
//	return i;
//}
//
//int main(void)
//{
//	long a, b, c;
//	scanf("%ld", &a);
//	c = fun(a, &b);
//	if (c == -1)
//		printf("error");
//	else
//		printf("%ld,%ld", b, c);
//	return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int i, a[5], * p;
//    for (i = 0; i <= 4; i++)
//        scanf("%d", &a[i]);
//    p = &a[0];
//    for (i = 0; i <= 4; i++) {
//        *(p + i) = *(p + i) * 2;
//        printf("%d\n", *(p + i));
//    }
//    return 0;
//}
//int main()
//{
//	int n = 9;
//	float* p = (float*)&n;
//	printf("%d\n", n);
//	printf("%f\n", *p);
//	*p = 9.0;
//	printf("%d\n", n);
//	printf("%f", *p);
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int i, a[5], * p;
//    for (i = 0; i <= 4; i++)
//        scanf("%d", &a[i]);
//    p = &a[0];
//    for (i = 0; i <= 4; i++) {
//        *(p + i) = *(p + i) * 2;
//        printf("%d\n", *(p + i));
//    }
//    return 0;
//}
//int main()
//{
//	int n = 9;
//	float* p = (float*)&n;
//	printf("%d\n", n);
//	printf("%f\n", *p);
//	*p = 9.0;
//	printf("%d\n", n);
//	printf("%f", *p);
//	return 0;
//}
//#include<stdio.h>
//void sort(int x, int y, int z)
//{
//	if (x > y)
//	{
//		x = x ^ y;
//		y = x ^ y;
//		x = x ^ y;
//	}
//	if (y > z)
//	{
//		y = y ^ z;
//		z = y ^ z;
//		y = y ^ z;
//	}
//	if (x > y)
//	{
//		x = x ^ y;
//		y = x ^ y;
//		x = x ^ y;
//	}
//	printf("%d %d %d", x, y, z);
//}
//int main()
//{
//	int x, y, z;
//	scanf("%d %d %d", &x, &y, &z);
//	sort(x, y, z);
//	return 0;
//}
//int main()
//{
//	char arr[5];
//	char(*pa)[5] = &arr;
//	return 0;
//}
void print1(int arr[3][2], int x, int y)
{
	int i, j;
	for ( i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print2(int(*p)[2], int x, int y)
{
	int j, i;
	for ( i = 0; i < x; i++)
	{
		for ( j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][2] = { {1,2},{2,3},{3,4} };
	print1(arr, 3, 2);
	printf("¶Ô±È\n");
	print2(arr, 3, 2);
	return 0;
}