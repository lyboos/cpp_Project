#define _CRT_SECURE_NO_WARNINGS
//应用系统的，规范的，可量化的方法来开发，运行和维护软件，即将工程应用到软件
//对上述方法的各项研究
#include"header.h"

int replaceSubstr(char* src,char** dest,char* sub,char* new_sub) {
	if (src == NULL || dest == NULL || sub == NULL || new_sub == NULL)
		return -1;
	char* start = src;
	char* pointer = NULL;
	char tmp[512] = {0};
	int length = 0;
	do
	{
		pointer = strstr(start, sub);
		if (pointer != NULL) {
			length = pointer - start;
			//如果不是开头就出现sub的特殊情况，先把sub之前的字符拷贝来
			if (length > 0) {
				strncat(tmp,start,length);
			}
			//加上应该替换的new_sub
			strncat(tmp, new_sub, strlen(new_sub));
			//重新设置起点位置
			start = pointer + strlen(sub);
		}
		else {
			strcat(tmp, start);
			break;
		}
	} while (*start!='\0');
	char* buf = (char*)malloc((strlen(tmp) + 1)*sizeof(char));
	buf[strlen(tmp)] = '\0';
	strcpy(buf, tmp);
	*dest = buf;
	//废弃方案
	/*int len_rpl = strlen(sub);
	int len_new = strlen(new_sub);
	char* replace_location = strstr(src, sub);
	printf("dest:%s\n", src);
	while (replace_location != NULL)
	{
		char* adder2 = (char*)malloc(100);
		char* adder1 = (char*)malloc(100);
		memset(adder1, 0, 100);
		memset(adder2, 0, 100);
		int i = 0, j = 0;
		while((src+i)!=replace_location) {
			i++;
		}
		for (; i >= 1; i--) {
			*(adder1+i) = src[i];
		}
		while ((src + j) != (replace_location+len_rpl)) {
			j++;
		}
		adder2 = src + j;
		char *adder = strcat(adder1, new_sub);
		src = strcat(adder, adder2);
		replace_location = strstr(src, sub);
	}
	replace_location = NULL;
	*dest = src;*/
	return 0;
}

void freebuf(char* buf)
{
	free(buf);
	buf = NULL;
}
//分割字符串，STRING.split
int spitString(const char* src,char sub_c,char buf[10][30],int* count) {
	if (src == NULL || count == NULL) return -1;
	const char* start = src;
	int n = 0;
	char* p = NULL;
	do
	{
		p = strchr(start, sub_c);
		if (p != NULL) {
			int length = p - start;
			if (length > 0) {
				strncpy(buf[n], start, p - start);
				buf[n][length] = 0;
				n++;
			}
			start = p + 1;
		}
		else {
			strcpy(buf[n],start);
			break;
		}
	} while (*start!='\0');
	*count = n;
	if (n == 0) return -2;
	return 0;
}


typedef struct t2 {
	char name[50];
	int age;
}t1;


void copyt1(t1* dst, t1* src) {
	*dst = *src;
}

//int main() {
//	t1 ly = {"lyboos",89};
//	//t1 lyy = ly;
//	
//	t1 lyy;
//	copyt1(&lyy,&ly);
//	printf("%s,%d\n", lyy.name, lyy.age);
//	return 0;
//}
//int main() {
//	const char* src = "abcd,asd,dasaws,adedsw";
//	char buf[10][30] = { 0 };
//	int n = 0, ret = 0;
//	ret = spitString(src,',',buf,&n);
//	if(ret==0)
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s\n", buf[i]);
//	}
//	/*printf("sb out");
//	char p[] = {'0','1','2','\0'};
//	printf("%s", p);*/
//	/*strstr("lyboos",p);
//	int pl=strcmp(p, "lyboos");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
//	printf("%d",pl);*/
//	
//	/*char* p1[3] = { "111","222","000" };
//	char p2[3][3] = { "333","555","444" };*/
//
//
//	//char* src = "abcd754yg4t8uhj8abcd";
//	//char* buf = NULL;
//	//int ret = replaceSubstr(src,&buf,"abcd","qqqq");
//	//if (ret != 0) {
//	//	printf("replacement error:%d", ret);
//	//	system("pause");
//	//	return ret;
//	//}
//	//printf("origin:%s\n", src);
//	//printf("new:%s\n\n", buf);
//	//
//	////freebuf(buf);
//	///*if (buf != NULL) {
//	//	free(buf);
//	//	buf = NULL;
//	//}*/
//	return 0;
//}

//typedef struct A{
//	int a;
//}A;
//
//int main() {
//	A a;
//	return 0;
//}