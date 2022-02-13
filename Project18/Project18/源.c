#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//int main()
//{
//	int num = 0, n;
//	scanf("%d", &n);
//	int j = 1;
//	for (int i = 1; i <=n; i++)
//	{
//		j *= i;
//		num += j;
//	}
//	printf("%d", num);
//	return 0;
//}
//int main()
//{
//	double n, x;
//	scanf("%lf",&x);
//	scanf("%lf", &n);
//	double j = x, num = 1.0;
//	for (double i = 1.0; i < n; i++)
//	{
//		num += j;
//		j = j * j / (i+1);
//	}
//	printf("%lf", num);
//	return 0;
//}
//int main()
//{
//    double prec = 1e-6; 
//	double term = 1, sum = 0, x = 0;  //每个相加的数为term 
//	double up = 1, low = 1;           // 每个相加的数的分子为up， 分母为low 
//	int i = 1;                         //i为循环体 
//	scanf("%lf", &x);
//	while (term > prec)
//	{
//		sum =sum+ term;
//		up = up * x;
//		low = low * i;
//		term = up / low;
//		i++;
//	} 
//	printf("e^%.0lf = %lf\n", x, sum);
//}

#include<Windows.h>
//int main()
//{
//	int i;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for ( i = 0; i <=12; i++)
//	{
//		arr[i] = 0;
//		printf("ly\n");
//	}
//	system("pause");
//	return 0;
//}
//#define  _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#include<assert.h>
//void mystrcpy(char* a,const char* b)
//{
//	assert(a != NULL);
//	assert(b != NULL);
//	while (*a++ = *b++);
//	//进阶写法
//	/*if (a != NULL && b != NULL)
//		while (*a++ = *b++);
//	else printf("参数有误！！！\n");*/
//	//基础写法：
//	/*while (*b != '\0') {
//		*a = *b;
//		b++;
//		a++;
//	}
//	*a = *b;
//	while (*a != '\0')
//	{
//		*a = '\0';
//		a++;
//	}*/
//}
////int main()
//{
//	char a[20] = "lylyly";
//	char  b[20];
//	char c[20];
//	mystrcpy(b, a);
//	mystrcpy(c, "copy successful");
//	printf("%s\n%s\n%s",a,b,c);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	int* p = &a;
//	char* b = (char*)&a;
//	if (*b == 1)
//		printf("小端");
//	else printf("大端");
//	return 0;
//}
//%u无符号十进制整数
//char a=128;
//printf("%u",a)
//==  极大的数
//整型提升的典例




//#include <stdio.h>
//
//int main() {
//    void swap(int* p1, int* p2);
//    int a=0, b=0, c=0;
//    scanf("%d%d%d", &a, &b, &c);
//    int* p = &a, * q = &b, * r = &c;
//    if (*p > * q)
//        swap(p, q);
//    if (*p > * r)
//        swap(p, r);
//    if (*q > * r)
//        swap(q, r);
//    printf("%d %d %d\n", *p, *q, *r);
//    return 0;
//}
//
//void swap(int* p1, int* p2)
//{
//    int p3;
//    p3 = *p1;
//    *p1 = *p2;
//    *p2 = p3;
//}
//
//int main()
//{
//	int r1 = 0, r3 = 16, r4 = 1;
//	int r2;
//	scanf("%d", &r2);
//	int r5 ;
//	do
//	{
//		r5 = r2 & r4;
//		if (r5 != 0)
//			r1 += 1;
//		r4 *= 2;
//		r3 -= 1;
//	} while (r3!=0);
//	printf("%d", r1);
//	return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int fun(long n, long* hw);
//    long a, b, c;
//    long* hw=b;
//    scanf("%ld", &a);
//    c = fun(a, *hw);
//    if (c == -1)
//        printf("error\n");
//    else
//        printf("%ld,%ld\n", b, c);
//    return 0;
//}
//
//int fun(long n, long* hw)
//{
//    int fanxushu(long n);
//    int huiwen(long n);
//    int cishu, x;
//    for (cishu = 0; cishu <= 10000; cishu++) {
//        x = fanxushu(n);
//        x = x + n;
//        if (huiwen(x) == 1) {
//            cishu++;
//            *hw = x;
//            return cishu;
//        }
//        if (cishu >= 10000)
//            return -1;
//    }
//}
//
//int fanxushu(long n)
//{
//    int a, y = 0;
//    while (a) {
//        a = n % 10;
//        y = a + y * 10;
//        a = a / 10;
//    }
//    return y;
//}
//
//int huiwen(long n)
//{
//    return fanxushu(n) == n ? 1 : 0;
//}
#include<stdio.h>
long reverse(long n)
{
	long a = 1, y = 0;
	while (n)
	{
		a = n % 10;
		n = n / 10;
		y = a + y * 10;
	}
	return y;
}

int jiance(long n)
{
	return (reverse(n) == n ? 0 : 1);
}

int fun(long n, long* hw)
{
	int swap = 0;
	while(jiance(n))
	{
		int huiwen = reverse(n);
		n += huiwen;
		swap++;
		if (swap > 10000)
			return -1;
	}
	*hw = n;
	return swap;
}

int main()
{
	int a=0, b=0, c=0;
	scanf("%d", &a);
	long* hw = &b;
	c = fun(a, hw);
	if (c == -1)
		printf("error");
	else printf("%d,%d",*hw,c);
	return 0;
}