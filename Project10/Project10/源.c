#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//int main()
//{
//	printf("hhhh\n");
//	main();
//	return 0;
//}
//void print(int a)
//{
//	if (a > 9) print(a/ 10);
//	printf("%d ", a % 10);
//}
//int main()
//{
//	int num = 0;
//	printf("输入一个数以打印它的每一位\n");
//	scanf("%d", &num);
//		print(num);
//	return 0;
//}
//int my_strlen(char* str)
//{
//	if (*str== 0)
//		return 0;
//	else
//		return my_strlen(str + 1) + 1;
//}
//int main()
//{
//	char arr[] = "lylpn";
//	int length = my_strlen(arr);
//	printf("length=%d", length);
//	return 0;
//}
int i = 1;
void move(int n, char a, char c)
{
	printf("第%d步：将第%d个圆盘从%c棒放到%c棒上\n", i++, n, a, c);
}
void hnt(int n,char a,char b,char c)
{
	if (n == 1) 
		move(n, a, c);
	else {
		hnt(n - 1, a, c,b);
		move(n, a, c);
		hnt(n - 1, b,a,c);
	}
}

int main()
{
	int a = 1;
	scanf("%d", &a);
	hnt(a,'A','B','C');
	return 0;
}
//int qwt(int n)
//{
//	int c = 1;
//	for (int a=1,b=1; n > 2; n--)
//	{  
//		c = a + b;
//			a = b;
//			b = c;
//	}
//	return c;
//}
//int main()
//{
//	int a = 1;
//	printf("输入n值以查找青蛙跳到n台阶上方式\n");
//	scanf("%d", &a);
//	int b=qwt(a);
//	printf("\n%d种方法", b);
//	return 0;
//}