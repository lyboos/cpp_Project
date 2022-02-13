#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

struct LY
{
	char like[20];
	int height
		; short weight;
};
int main()
{
	int a = 0;
	printf("press password to start\n");
	scanf("%d", &a);
	switch (a)
	{
	default:printf("ERROR");
		break;
	case 613:
		printf("通过\n");
		struct LY liuy = { "MAN",182,55 };
		struct LY* LPN = &liuy;
		strcpy(liuy.like, "WOMEN");
		printf("LYlike%s\n", liuy.like)
			; printf("身高%dcm\n", liuy.height)
			; printf("体重%dkg\n", liuy.weight);
		; printf("LYlike%s\n", LPN->like);
		break;
	}
	return 0;
}
////int main()
//{
//	int a = 0;
//	printf("输入一个整数\n");
//	scanf("%d",&a);
//	if (1 == a % 2)
//		printf("%d是一个奇数\n", a);
//	else if (0 == a % 2)
//		printf("%d是一个偶数\n");
//	else printf("输一个整数很难？？？");
//	return 0;
//}
//int main()
//{
//	int i = 99;
//	while (i > 0)
//	{
//		
//		printf("%d\n", i)
//
//			; i -= 2;
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	printf("1-清华\n2-北大\n3-复旦\n4-上交\n5-中科大\n6-浙大\n7-南大\n");
//	scanf("%d", &a);
//	switch (a)
//	{
//	default:printf("ERROR");
//		break;
//	case 1:
//	   case 2:
//	   case 3:
//	   case 4:
//	   case 5:
//	   case 6:printf("华伍强校\n");
//		   break;
//	   case 7:printf("华伍守门员\n");
//		   break;
//	  	}
//	return 0;
//}
//int main(){
//	int a = 0;
//	printf("press [ENTER] to start\n");
//	while (getchar() != '\n') {}
//	; printf("欢迎使用复读机\n键入CTRL+Z以停止");
//	while ((a = getchar()) != EOF)
//
//	{
//		putchar(a);
//	}
//	return 0;
//}
//int main()
//{
//	int t = 0, a = 0;
//	for(; a=0; t++,a++)
//	{
//		a = 0;
//	}
//	do {
//		if (a == 5)
//			continue;
//		printf("%d\n", a)
//			; a++		;
//	}
//	while (a < 10);
//	return 0;
//}
//int main()
//{
//	printf("输入n求1！+2！……n！\n");
//	int a = 1, n = 0, sum = 0;
//	long long total = 1;
//	scanf("%d", &n);
//	for (int b = 1; b <= n; b++)
//	{
//		total = total * b;
//		sum = sum + total;
//	}
//	printf("总和为%d\n", sum);
//	return 0;
//}
////{
//	printf("输入n求1！+2！……n！\n");
//	int a = 1, n = 0,sum=0;
//	long total = 1;
//	scanf("%d", &n);
//	for (int b = 1; b <= n; b++) {
//		for (; a <= b; ++a)
//		{
//			total = total * a;
//		}
//		sum = sum + total;
//	}
//	printf("总和为%d\n", sum);
//	return 0;
//}
int main()
{
	int m = 0;
	int abc[] = { 1,2,3,4,5,6,7,8,9 };
	printf("输入数字查找下标\n");
	scanf("%d", &m);
	int sz = sizeof(abc) / sizeof(abc[0]);
	int L = 0, R = sz - 1;
	while (L <= R)
	{
		int Mid = (L + R) / 2;

		if ((abc[Mid]) > m) {
			R = Mid - 1;
		}
		else if ((abc[Mid]) < m) {
			L = Mid + 1;
		}
		else {
			printf("找到，下标为%d\n", Mid);
			break;
		}
	}
	if (L > R) printf("ERROR\n");
		
	
	/*for (; i < sz; i++)
	{
		if (abc[i] == m) {
			printf("已发现，下标为%d\n", i);
			break;
		}
	}
		if (i==sz) {
			printf("404 NOT FOUND"); 
		}*/
			
	return 0;
}