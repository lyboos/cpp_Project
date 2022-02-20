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
int main() {
	/*printf("sb out");
	char p[] = {'0','1','2','\0'};
	printf("%s", p);*/
	/*strstr("lyboos",p);
	int pl=strcmp(p, "lyboos");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	printf("%d",pl);*/
	
	/*char* p1[3] = { "111","222","000" };
	char p2[3][3] = { "333","555","444" };*/
	char* src = "abcd754yg4t8uhj8abcd";
	char* buf = NULL;
	int ret = replaceSubstr(src,&buf,"abcd","qqqq");
	if (ret != 0) {
		printf("replacement error:%d", ret);
		system("pause");
		return ret;
	}
	printf("origin:%s\n", src);
	printf("new:%s\n\n", buf);
	
	//freebuf(buf);
	/*if (buf != NULL) {
		free(buf);
		buf = NULL;
	}*/
	return 0;
}