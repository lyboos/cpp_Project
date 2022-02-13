#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//void ly(int b)
//{
//	int a = 0;
//}
//分析
//(*(void(*)())0)();

//void(*signal(int,void(*)(int)))(int)
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//double Sub(double x, double y)
//{
//	return x - y;
//}
//double Mul(double x, double y)
//{
//	return x * y;
//}
//double Div(double x, double y)
//{
//	return x / y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (pa)(a, b));
//	printf("%d\n", (*pa)(2, 3));
//    printf("%d\n", (**pa)(5, b));
//    printf("%d\n", (***pa)(a, 10));
//	return 0;
//}
//char* mystrcpy(char* desk, const char* src)
//{
//
//}
//char* (*pf)(char*, const char*) = mystrcpy;
//char* (*pfarr[4])(char*, const char*) = { mystrcpy,mystrcpy,mystrcpy,mystrcpy };
//void menu()
//{
//	printf("**********************\n");
//	printf("***1.add*****2.sub****\n");
//	printf("***3.mul*****4.div****\n");
//	printf("********0.exit********\n");
//	printf("**********************\n");
//}
//int main()
//{
//	int input = 0;
//	double x, y;
//	double (*parr[5])(double, double) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4) {
//			printf("输入两个计算数：\n");
//			scanf("%lf %lf", &x, &y);
//			printf("%lf\n", parr[input](x, y));
//		}
//		else if (input == 0)
//		{
//			printf("已退出\n");
//		}
//		else {
//			printf("参数错误\n");
//	        }
//		/*switch (input)
//		{
//		case 1:   printf("%lf\n", Add(x, y));
//			break;
//		case 2:  printf("%lf\n", Sub(x, y));
//			break;
//		case 3:  printf("%lf\n", Mul(x, y));
//			break;
//		case 4:  printf("%lf\n", Div(x, y));
//			break;
//		default:
//			printf("Error!\n");
//			break;
//		}*/
//	} while (input!=0);
//
//	return 0;
//}
//void maopao(int ly[], int sz)
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
#include<stdlib.h>
//void qsort(void* base, 
//	        size_t num, 
//	        size_t width, 
//	        int(__cdecl* compare)(const void*, const void*));
//struct lpn {
//	char name[20];
//	int age;
//};
//int mycmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int lycmp1(const void* e1, const void* e2)
//{
//	return ((struct lpn*)e1)->age - ((struct lpn*)e2)->age;
//}
//int main()
//{
//	int arr[5] = { 4,6,8,3,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	struct lpn ly[3] = { { "lol",10 },{"ow",20},{"teachfeeling",15} };
//	int szs = sizeof(ly) / sizeof(ly[0]);
//	qsort(arr, sz, sizeof(arr[0]), mycmp);
//	qsort(ly,szs ,sizeof(ly[0]),lycmp1);
//	print(arr,sz);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
//给上各种compare函数的种类
int intcmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int doublecmp(const void* e1, const void* e2)
{
	return (*(double*)e1 > * (double*)e2 ? 1:-1);
}
int charcmp(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
//若有结构体根据字符串来进行排序
int stringcmp(const void* e1, const void* e2)
{
	return strcmp(*(char*)e1, *(char*)e2);
}
void swap(char* e1, char* e2,int width)
{
	int i = 0;
	for ( i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		*e1++;
		*e2++;
	}
}
void bubblesort(void* base,int sz,int width,int(*cmp)(const void*,const void*))
{
	int i;
	for ( i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j=0;j<sz-1-i;j++)
		{
			if (cmp((char*)base+j*width, (char*)base + (1+j)*width) > 0)
				swap((char*)base+j*width, (char*)base + (1+j)*width,width);
		}
	}
}
int main()
{
	char a[20] = "lyboos";
	char b[20] = "executioner";
	bubblesort(a, 6, 1, charcmp);
	bubblesort(b, 11, 1, charcmp);
	printf("%s\n", a);
	printf("%s\n", b);
	return 0;
}