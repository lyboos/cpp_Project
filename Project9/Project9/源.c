#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<windows.h>
//int main()
//{
//	char ly1[] = "welcome to los santos";
//	char ly2[] = "*********************";
//	int L = 0, R = strlen(ly1) - 1;
//	for (; L <=R;L++,R--)
//	{
//		printf("%s\n", ly2);
//		Sleep(500);
//		ly2[L] = ly1[L];
//	    ly2[R] = ly1[R];		
//	}
//	return 0;
//}
//int main()
//{
//	char PASSWORD[20] = {0};
//	for (int i = 1; i <= 3; i++)
//	{
//		printf("print password to continue\n");
//		scanf("%s", PASSWORD);
//		if (strcmp(PASSWORD , "613613")==0)
//		{
//			printf("\nWELCOME");
//			break;
//		}
//		else printf("\nERROR!");
//	}
//	return 0;
//}
//int main()
//{
//	char ly[] = { "MMODOKA" };
//	memset(ly, '*', 1);
//	printf("%s\n",ly);
//    return 0;
//}
//int main()
//{
//	int a = 0;
//	printf("输入数以检测一至它的质数\n");
//	scanf("%d", &a);
//	for(int t=0;t<=a;t++)
//	{
//		if (t % 2 != 0 && t % 3 != 0 && t % 5 != 0&&t%7!=0)
//		printf("%d\n", t);
//		else if(t == 2 )
//			printf("%d\n", t);
//		else if (t == 3)
//			printf("%d\n", t);
//		else if (t == 5)
//			printf("%d\n", t);
//		else if (t == 7)
//			printf("%d\n", t);
//	}
//	return 0;
//}
//int main()
//{
//	int y = 0;
//	printf("输入年份判断是否为闰年\n")
//		; scanf("%d", &y);
//	if (y % 4 == 0 && y % 100 != 0)
//		printf("\n%d是闰年", y);
//	else printf("\n%d不是闰年", y);
//	return 0;
//}
//int erfen_search(int ly[], int a,int sz)
//{
//	int L = 0, R = sz- 1;
//	while (L <= R)
//	{
//		int Mid = (L + R) / 2;
//		if (ly[Mid] < a)
//			L = Mid + 1;
//		else if (ly[Mid] > a)
//			R = Mid - 1;
//		else if (ly[Mid] = a) 
//			return Mid;
//	}
//	return -1;
//}
//int main()
//{
//	int ly[] = { 1,2,3,4,5,6,7,8,9 }, a = 0,sz=sizeof(ly)/sizeof(ly[0]);
//	printf("输入一至九数字测试二分查找法\n");
//		scanf("%d", &a);
//		int ret = erfen_search(ly, a,sz);
//		if (ret == -1)
//			printf("\n找不到指定数字");
//		else
//			printf("\n找到了，下角标为%d", ret);
//	return 0;
//}
void app(int* p)
{
	*p = *p + 1;
}
int main()
{
	int num = 0;
	app(&num);
	printf("num=%d\n", num);
	return 0;
}
