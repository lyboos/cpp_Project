#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//int main()
//{	char nchar;
//	int count = 0;
//	int gotINT = 0;
//	printf("Enter your string:");
//	do{	scanf("%c", &nchar);
//	if (gotINT > 2) gotINT = 0;
//	switch (nchar)
//	{case'i':
//		gotINT++;break;
//	case'n':
//		if (gotINT = 1) {
//			gotINT++; break;}
//	case't':
//		if (gotINT == 2)
//		{gotINT = 0;
//			count++;}
//		break;}	} while (nchar!='\n');
//	printf("%d个int", count);
//}
//int main(void)
//{
//    int a, b, c, d;
//    scanf("%d:%d %d:%d", &a, &b, &c, &d);
//    if (c == 7) {
//        if (d <= 40) printf("%d米\n", 100 * (d - b));
//        if (b <= 40 && d <= 50 && d > 40) printf("%d米\n", 100 * (d - b) + 50 * (d - 40));
//        if (b <= 40 && d > 50) printf("%d米\n", 100 * (a - b) - 50 * (d - 50));
//        if (b <= 50 && d <= 50 && b > 40 && d > 40) printf("%d米\n", 150 * (d - b));
//        if (b <= 50 && b > 40 && d > 50) printf("%d米\n", 150 * (d - b) - 100 * (d - 100));
//        if (b > 50) printf("%d米\n", 50 * (d - b));
//    }
//    else {
//        if (b <= 40) printf("%d米\n", 2000 + 100 * (40 - b));
//        if (b > 40 && b <= 50) printf("%d米\n", 500 + 150 * (50 - b));
//        if (b > 50) printf("%d米\n", 50 * (60 - b));
//    }
//    return 0;
//
//}
//大学里上午上课时间是八点钟。小明同学7点30分在食堂吃完饭后，以100m/min的速度步行去教室,走1000m
//但是走了10分钟后小明一看手表发现手表上已经7点55分了（其实是手表坏了），小明感到很着急马上开始跑步，
//小明跑步的速度是150m/min，小明跑了10分钟后，跑了1500m听到手机在响，原来这是他设置的闹钟，现在才7点50！
//而距离教室也只有500m的距离了，所以小明又放慢脚步，以50m/min的速度刚好在8点到达教室，开始上课。
//现在输入时间点t1、t2（t1、t2在7:30到8:00之间且t1<t2，格式如7:30 7:40，“:”前后都是整数，表示从7点30到7点40），求出小明同学在时间t1，t2内运动的距离。
int main()
{
	int a, b, c, d;
	int dis = 3000;
	scanf("%d:%d %d:%d", &a, &b, &c, &d);
	if (a != 7 || b < 30 || b>59 || c == 8 && d != 0)
		return 0;
	if (a == c && b > d) return 0;
	if (d > 50) {
		if (b >= 40 && b < 50)
			dis = dis - 1000 - (b - 30) * 150 - (d - 50) * 50;
		else if (b >= 50) dis = (d - b) * 50;
		else dis = dis - (b - 30) * 100 - (60 - d) * 50;
	}
	else if (d <= 40) dis = (d - b) * 100;
	else {
		if (b >= 40)
			dis = (d - b) * 150;
		else dis = dis - 500 - (b - 30) * 100 - (50 - d) * 150;
	}
	printf("%dm", dis);
	return 0;
}
//#include<stdio.h>
//int main(void)
//{
//    int a, b, c, d;
//    scanf("%d:%d %d:%d", &a, &b, &c, &d);
//    if (c == 7) {
//        if (d <= 40) printf("%d米\n", 100 * (d - b));
//        if (b <= 40 && d <= 50 && d > 40) printf("%d米\n", 100 * (d - b) + 50 * (d - 40));
//        if (b <= 40 && d > 50) printf("%d米\n", 100 * (a - b) - 50 * (d - 50));
//        if (b <= 50 && d <= 50 && b > 40 && d > 40) printf("%d米\n", 150 * (d - b));
//        if (b <= 50 && b > 40 && d > 50) printf("%d米\n", 150 * (d - b) - 100 * (d - 100));
//        if (b > 50) printf("%d米\n", 50 * (d - b));
//    }
//    else {
//        if (b <= 40) printf("%d米\n", 2000 + 100 * (40 - b));
//        if (b > 40 && b <= 50) printf("%d米\n", 500 + 150 * (50 - b));
//        if (b > 50) printf("%d米\n", 50 * (60 - b));
//    }
//    return 0;
//
//}
//int main()
//{
//	int n;
//	do {
//		scanf("%d", &n);
//		printf("%d", n);
//	} while (n != -1);
//		return 0;
//}