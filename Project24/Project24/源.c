#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//#include<string.h>
//#include<assert.h>
int strlen(char* a)
{
	char* p1 = a;
	while (*p1)
	{
		p1++;
	}
	int i = p1 - a;
	return i;
}

void fun(int x, int y, int z)
{
	printf("%x\n%x\n%x", &x, &y, &z);
}

int main()
{
	int a=100, b=200, c=300;
	fun(a, b, c);
}
//int fun(char* a)
//{
//	int i = 0,flag=0,num=0,check=0;
//	for ( i = 0; i <strlen(a); i++)
//	{
//		if (a[i] == ' ' && flag == 0)
//			continue;
//		if (a[i] == '-'&&flag==0)
//		{
//			check = 1;
//			flag = 1;
//			continue;
//		}
//		if (*(a+i)>='0'&&*(a+i)<='9')
//		{
//			num=*(a+i)-48+num*10;
//			flag = 1;
//		}
//		else if(flag)
//		{
//			*(a + i) = '\0';
//			break;
//		}
//	}
//	if (check)
//		return -num;
//	else if (flag)
//		return num;
//	return 0;
//}
//
//int main()
//{
//	char a[40];
//	scanf("%s", a);
//	printf("%d", fun(a));
//	return 0;
//}
////void delete(char* a, char* b, char* c)
//{
//	int x, y, arr[40] = { 0 },i=0,m;
//	for (y = 0; y < strlen(b); y++)
//	{
//		for (x = 0; x < strlen(a); x++)
//		{
//			if (a[x] == b[y])
//			{
//				c[i++] = a[x];
//				for (m = x; m < strlen(a); m++)
//					a[m] = a[m + 1];
//			}
//		}
//	}
//}
//
//int main()
//{
//	char a[40];
//	char b[40];
//	char c[40];
//	for (int i = 0; i < 40; i++)
//	{
//		c[i] = '\0';
//	}
//	scanf("%s", a);
//	scanf("%s", b);
//	delete(a,b,c);
//	printf("%s\n", a);
//	printf("%s", c);
//	return 0;
//}
//int main()
//{
//	int a[100], i=0, n;
//	for (i=0;i<100;i++)
//	{
//		scanf("%d", &a[i]);
//		if (getchar() == EOF)
//			break;
//	}
//	return 0;
//}
////编写函数void sort(PS *p,int n)，对p指向的数组中的n个联系人信息排序。
////要求：按性别排序（f在前m在后，f的编码小于m的编码），性别相同的按姓名排序（字典序）
//
//typedef struct student {
//	long id;
//	char name[10];
//	char sex[2];
//}PS;
//
//void sort(PS* p, int n)
//{
//	int i, j;
//	for ( i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (j == i) continue;
//	        if(strcmp((p + i)->sex, ((p + j)->sex)) <0)
//			{
//				PS swap = *(p + i);
//				*(p + i) = *(p + j);
//				*(p + j) =swap;
//			}
//			else if(strcmp((p + i)->sex, ((p + j)->sex)) == 0)
//			{
//				if (strcmp((p + i)->name, (p + j)->name) > 0)
//				{
//					PS swap = *(p + i);
//					*(p + i) = *(p + j);
//					*(p + j) =swap;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	PS a[3] = { {.id = 44,.name = "lyboos",.sex = "m"} ,{.id = 33,.name = "fdsfdf",.sex = "m"},{.id = 22,.name = "lyboos",.sex = "f"} };
//	sort(a, 3);
//	printf("%s,%s",a->name,a->sex);
//	printf("%s,%s", (a+1)->name, (a+1)->sex);
//	printf("%s,%s", (a+2)->name, (a+2)->sex);
//	return 0;
//}
/*void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void leftmove(char arr[], int n)
{
	assert(arr);
	int len = strlen(arr);
	assert(n <= len);
	reverse(arr, arr + n - 1);
	reverse(arr + n, arr + len - 1);
	reverse(arr, arr + len - 1);
}
int isleftmove(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	int i = 0;
	for ( i = 0; i < len; i++)
	{
		leftmove(arr1, i);
		int ret = strcmp(arr1, arr2);
		if (ret == 0)
			return 1;
	}
}

int main()
{
	char arr1[30]= "abcdef";
	char arr2[30]= "defabc";
	int ret = isleftmove(arr1, arr2);
	if (ret==1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}*/
//int detect(char* arr1, char* arr2)
//{
//	int len1 = strlen(arr1), len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//	strncat(arr1, arr1, len1);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	return 1;
//}
//
//int main()
//{
//	char arr1[30] = "abcdefg";
//	char arr2[30] = "fgabcde";
//	if (detect(arr1,arr2)==1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}

//void reverse(char arr[],int a)
//{
//	int len = strlen(arr);
//	int i, j;
//	for ( i = 0; i <a; i++)
//	{
//		char tmp = *arr;
//			j = 0;
//		for ( j = 0; j < len-1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + len-1) = tmp;
//	}
//}


//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int a;
//	scanf("%d",&a);
//	leftmove(arr,a);
//	printf("%s", arr);
//	return 0;
//}
//


//int main()
//{
//	int t, num,i,j;
//	char allstring[100][40];
//	scanf("%d", &t);
//	scanf("%d", &num);
//	for ( i = 0; i <num; i++)
//	{
//		scanf("%s", &allstring[i]);
//	}
//	char out[40][2];
//	for ( i = 0; i < num-1; i++)
//	{
//		if (1)
//		{
//			out[40][0]= allstring[i];
//		}
//	}
//	printf("%s", out[1]);
//	return 0;
//}
//int count(const char* p1,const char* p2)
//{
//	int num = 0,i=0,j=0,count=0;
//	int len1 = strlen(p1), len2 = strlen(p2);
//	for ( i = 0; i < len1; i++)
//	{
//		num = 0;
//		for ( j = 0; j < len2; j++)
//		{
//			if ((*(p1+i+j)-*(p2+j))==0)
//				num++;
//			if (num == len2)
//				count++;
//		}
//	}
//	return count;
//}
//
//
//int main()
//{
//	char a1[100], a2[10];
//	scanf("%s", a1);
//	scanf("%s", a2);
//	printf("%d", count(a1,a2));
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3 }, * p = arr;
//	printf("%x", arr);
//	return 0;
//}
//智力题
//每个人只说对一半
//int main()
//{
//	int a, b, c, d,e;
//	for ( a = 1; a <=5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for ( c = 1; c <=5; c++)
//			{
//					for (d = 1; d <=5; d++)
//					{
//						for ( e = 1; e <=5; e++)
//						{
//							if (((b == 2) + (a == 3) == 1) &&
//								((b == 2) + (e == 4) == 1) &&
//								((c == 1) + (d == 2) == 1) &&
//								((c == 5) + (d == 3) == 1) &&
//								((e == 4) + (a == 1) == 1) && 
//								(a * b * c * d * e) == 120)
//								printf("a:%d\nb:%d\nc:%d\nd:%d\ne:%d", a, b, c, d, e);
//						}
//					}
//			}
//		}
//	}
//	return 0;
//}