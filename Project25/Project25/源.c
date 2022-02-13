#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int strlen(const char* s)
{
	int i = 0;
	while (*(s + i) != '\0')
		i++;
	return i;
}
char* strcpy(char* dest, const char* src)
{
	while ((*dest++=*src++)!='\0')
	{
		;
	}
}

char* strcat(char* dest,const char* src)
{
	while (*dest!='\0')
	{
		dest++;
	}
	while (*dest++=*src++)
	{
		;
	}
}
int strcmp(const char* a, const char* b)
{
	while (*a==*b)
	{
		if (*a == '\0')
			return 0;
		a++;
		b++;
	}
	return (*a - *b);
}

char* high_strstr(char* a,char* b)
{
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)a;
	if (b == '\0')
		return (char*)a;
	while (*cur!='\0')
	{
		s1 = cur;
		s2 = (char*)b;
		while((*s1 != '\0') &&(*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
//处理任意类型数组的copy：
void* memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
//处理重叠内存使用memmove（）；
//int main()
//{
//	int a1[5] = { 1,2,3,4,5 };
//	int a2[5] = { 0 };
//	memcpy(a2, a1, sizeof(a1));
//	return 0;
//}

//char* strtok(char* str,const char* sep)
//{
//	;
//}
//
//char* strerror(int num)
//{
//	;
//}
//#include<errno.h>
//int main()
//{
//	char a[40] = "201250119@smail.nju!edu&cn";
//	char b[40] = "@.&";
//	char c[40] = "efgh";
//	/*char *d ;
//	for (d = strtok(a, b); d != NULL; d = strtok(NULL, b))
//	{
//		printf("%s\n", d);
//	}*/
//	FILE* pf=fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file successfully\n");
//	}
//	return 0;
//}




































//char* replaceSpace(char* s) {
//    char arr[1000];
//    int i = strlen(s), j, count = 0;
//    for (j = 0; j <= i; j++)
//        arr[j] = s[j];
//    for (j = 0; j < i; j++)
//        if (*(s + j) == ' ')
//            count++;
//    for (j = 0,i=0; j < i + 2 * count; j++,i++)
//    {
//        if (*(arr + i) == ' ')
//        {
//            *(s + j) = '%';
//            *(s + j + 1) = '2';
//            *(s + j + 2) = '0';
//            j += 2;
//        }
//        else
//            *(arr + i) = *(s + j);
//    }
//    *(s + i + 2 * count) = '\0';
//    return s;
//}
//int main()
//{
//    char a[40] = "sdaasd djfs";
//    replaceSpace(a);
//    printf("%s", a);
//    return 0;
//}
//#include<stdlib.h>
//#include<stdio.h>
//int main()
//{
//	char str[100]; 
//	scanf("%s", str);
//	printf("%d", atoi(str)); 
//	return 0;
//}
//char* replaceSpace(char* s) {
//    char arr[1000] = s;
//
//    return s;
//}
//
//int main()
//{
//    char a[40] = "sss bbb";
//    replaceSpace(a);
//    printf("%s", a);
//    return 0;
//}