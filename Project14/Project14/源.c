#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//void printReverse(char* str) {
//	if (!*str)
//		return;
//	printReverse(str + 1);
//	printf("%c",*str);
//}
//int main()
//{
//	char arr[100];
//	scanf("%s", arr);
//	printReverse(arr);
//}
////int main()
////{
////	int a = 6;
////	printf("%d%d",++a, a++);
////}
//int main()
//{
//	int y, m, r,sum=0;
//	printf("����������\n");
//	scanf("%d %d %d", &y, &m, &r);
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//		if(m>=3)
//		sum++;
//	switch (m)
//	{
//	case 1:sum =sum+ r; break;
//	case 2:sum =sum+r+31 ; break;
//	case 3:sum = sum + r + 59; break;
//	case 4:sum = sum + r + 90; break;
//	case 5:sum = sum + r + 120; break;
//	case 6:sum = sum + r + 151; break;
//	case 7:sum = sum + r + 181; break;
//	case 8:sum = sum + r + 212; break;
//	case 9:sum = sum + r + 243; break;
//	case 10:sum = sum + r + 273; break;
//	case 11:sum = sum + r + 304; break;
//	case 12:sum = sum + r + 334; break;
//	}
//	printf("%d %d %d is the %dth days.\n", y, m, r, sum);
//}
//{
//	int i = 0, s = 0;
//	for (;;)
//		if (i < 10) {
//			s = s+i++;
//			printf("%d\n", s);
//		}
//		else {
//			printf("Y"); break;
//		}
//	printf("N");
//	printf("%d\n", s);
//}
int main()
{
	int a, b, c, d, n;
	scanf("%d %d", &a, &b);
	for (n = a; n <= b; n++)
	{
		c = 1;
		for (d = 2; d < n; d++)
			if ((n % d) == 0)
				c = 0;
		if (c)
			printf("%d\n", n);
	}
}