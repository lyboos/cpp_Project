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
//	printf("%d��int", count);
//}
//int main(void)
//{
//    int a, b, c, d;
//    scanf("%d:%d %d:%d", &a, &b, &c, &d);
//    if (c == 7) {
//        if (d <= 40) printf("%d��\n", 100 * (d - b));
//        if (b <= 40 && d <= 50 && d > 40) printf("%d��\n", 100 * (d - b) + 50 * (d - 40));
//        if (b <= 40 && d > 50) printf("%d��\n", 100 * (a - b) - 50 * (d - 50));
//        if (b <= 50 && d <= 50 && b > 40 && d > 40) printf("%d��\n", 150 * (d - b));
//        if (b <= 50 && b > 40 && d > 50) printf("%d��\n", 150 * (d - b) - 100 * (d - 100));
//        if (b > 50) printf("%d��\n", 50 * (d - b));
//    }
//    else {
//        if (b <= 40) printf("%d��\n", 2000 + 100 * (40 - b));
//        if (b > 40 && b <= 50) printf("%d��\n", 500 + 150 * (50 - b));
//        if (b > 50) printf("%d��\n", 50 * (60 - b));
//    }
//    return 0;
//
//}
//��ѧ�������Ͽ�ʱ���ǰ˵��ӡ�С��ͬѧ7��30����ʳ�ó��극����100m/min���ٶȲ���ȥ����,��1000m
//��������10���Ӻ�С��һ���ֱ����ֱ����Ѿ�7��55���ˣ���ʵ���ֱ��ˣ���С���е����ż����Ͽ�ʼ�ܲ���
//С���ܲ����ٶ���150m/min��С������10���Ӻ�����1500m�����ֻ����죬ԭ�����������õ����ӣ����ڲ�7��50��
//���������Ҳֻ��500m�ľ����ˣ�����С���ַ����Ų�����50m/min���ٶȸպ���8�㵽����ң���ʼ�ϿΡ�
//��������ʱ���t1��t2��t1��t2��7:30��8:00֮����t1<t2����ʽ��7:30 7:40����:��ǰ������������ʾ��7��30��7��40�������С��ͬѧ��ʱ��t1��t2���˶��ľ��롣
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
//        if (d <= 40) printf("%d��\n", 100 * (d - b));
//        if (b <= 40 && d <= 50 && d > 40) printf("%d��\n", 100 * (d - b) + 50 * (d - 40));
//        if (b <= 40 && d > 50) printf("%d��\n", 100 * (a - b) - 50 * (d - 50));
//        if (b <= 50 && d <= 50 && b > 40 && d > 40) printf("%d��\n", 150 * (d - b));
//        if (b <= 50 && b > 40 && d > 50) printf("%d��\n", 150 * (d - b) - 100 * (d - 100));
//        if (b > 50) printf("%d��\n", 50 * (d - b));
//    }
//    else {
//        if (b <= 40) printf("%d��\n", 2000 + 100 * (40 - b));
//        if (b > 40 && b <= 50) printf("%d��\n", 500 + 150 * (50 - b));
//        if (b > 50) printf("%d��\n", 50 * (60 - b));
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