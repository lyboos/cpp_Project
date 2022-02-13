#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

enum SEX {
	male=7,
	female=5,
	unknown=4
};

union age
{
	char a;
	int b;
	char c[40];
};
int main()
{
	enum SEX a = female;
	enum SEX b = unknown;
	union age x = { 6 };
	printf("%d\n", sizeof(x));
	printf("%d %d", a, b);
	return 0;
}
//#include <stdio.h>
//
//int main() {
//	int i, j, bx, by, mx, my;
//	long m[21][21] = { 0 }, f[21][21] = { 0 };
//	scanf(" % d % d % d % d", &bx, &by, &mx, &my);
//	m[mx][my] = 1;
//	m[mx + 1][my + 2] = 1;
//	m[mx + 2][my + 1] = 1;
//	m[mx + 2][my - 1] = 1;
//	m[mx + 1][my - 2] = 1;
//	m[mx - 1][my - 2] = 1;
//	m[mx - 2][my - 1] = 1;
//	m[mx - 2][my + 1] = 1;
//	m[mx - 1][my + 2] = 1;
//	f[0][0] = 1;
//	for (i = 1; i <= bx; i++) if (m[i][0] == 0) f[i][0] = f[i - 1][0];
//	for (j = 1; j <= by; j++) if (m[0][j] == 0) f[0][j] = f[0][j - 1];
//	for (i = 1; i <= bx; i++)
//		for (j = 1; j <= by; j++) {
//			if (m[i][j]) continue;
//			f[i][j] = f[i - 1][j] + f[i][j - 1];
//		}
//	printf("%ld", f[bx][by]);
//	return 0;
//}
//#include <stdio.h>
//int map[21][21] = { 0 };
//int n, m, x, y;
//
//int main() {
//    int i, j;
//    long long count;
//    long long way(int x1, int y1);
//    scanf("%d%d%d%d", &n, &m, &x, &y);
//
//    for (i = 0; i <= n; i++)
//    {
//        for (j = 0; j <= m; j++)
//        {
//            map[i][j] = 1;
//        }
//    }
//    map[x][y] = 0;
//    map[x - 1][y - 2] = 0;
//    map[x - 1][y + 2] = 0;
//    map[x + 1][y - 2] = 0;
//    map[x + 1][y + 2] = 0;
//    map[x - 2][y - 1] = 0;
//    map[x - 2][y + 1] = 0;
//    map[x + 2][y - 1] = 0;
//    map[x + 2][y + 1] = 0;
//    count = way(n, m);
//
//    printf("%lld", count);
//    return 0;
//
//}
//
//long long way(int x1, int y1)
//{
//    long long result;
//
//    if (map[x1][y1] == 1)
//    {
//        if (y1 == 0 && x1 > 0)
//        {
//            result = way(x1 - 1, 0);
//        }
//        if (x1 == 0 && y1 > 0)
//        {
//            result = way(0, y1 - 1);
//        }
//        if (x1 > 0 && y1 > 0)
//        {
//            result = way(x1 - 1, y1) + way(x1, y1 - 1);
//        }
//        if (x1 == 0 && y1 == 0)
//        {
//            result = 1;
//        }
//    }
//    else
//    {
//        result = 0;
//    }
//    return(result);
//}
/*int main()
{
	int arr[10000], i, n, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] = arr[j] ^ arr[j + 1];
				arr[j + 1] = arr[j] ^ arr[j + 1];
				arr[j] = arr[j] ^ arr[j + 1];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}*/
//int len;
//int ans;
//char* tmp;
//struct Word {
//    char s[1000];
//    int childnum;
//    struct Word* n[22];
//    int childlen[22];
//    int AccurNum;
//}word[22];
//
//int Strstr(char* a, char b, int t) {
//    for (int i = t; i > 0; i--)
//        if (a[i] == b)
//            return i;
//    return -1;
//}
//
//void dfs(struct Word* w, int len) {
//    for (int i = 0; i < w->childnum; i++) {
//        if (w->n[i]->AccurNum >= 2)continue;
//
//        w->n[i]->AccurNum++;
//        len += w->childlen[i];
//        if (len > ans) {
//            ans = len;
//        }
//
//        dfs(w->n[i], len);
//
//        w->n[i]->AccurNum--;
//        len -= w->childlen[i];
//
//
//    }
//    if (len > ans)
//        ans = len;
//}
//
//
//
//void judge(struct Word* a, struct Word* b) {
//    int s;
//    s = Strstr(b->s, (a->s)[0], (int)strlen(b->s) - 1);
//    while (s > 0) {
//        int flag = 1;
//        int j = 0;
//        int i;
//        for (i = s; i < strlen(b->s) && j < strlen(a->s); i++) {
//            if (b->s[i] != a->s[j++]) {
//                flag = 0;
//                break;
//            }
//        }
//        if (flag && j != strlen(a->s)) {
//            b->childlen[b->childnum] = (int)strlen(a->s) - j;
//            b->n[b->childnum++] = a;
//            return;
//        }
//        s = Strstr(b->s, (a->s)[0], s - 1);
//    }
//
//
//}
//
//int main() {
//    int n; char l;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%s", word[i].s);
//        word[i].AccurNum = word[i].childnum = 0;
//    }
//
//    scanf("%c", &l);
//    scanf("%c", &l);
//
//    for (int i = 0; i < n; i++) {
//        judge(&word[i], &word[i]);
//        for (int j = i + 1; j < n; j++) {
//            judge(&word[i], &word[j]);
//            judge(&word[j], &word[i]);
//        }
//    }
//    ans = 0;
//    for (int i = 0; i < n; i++) {
//        if (word[i].s[0] == l) {
//
//            word[i].AccurNum++;
//            dfs(&word[i], (int)strlen(word[i].s));
//            word[i].AccurNum--;
//        }
//
//    }
//    printf("%d", ans);
//
//
//}



//char* mystrcat(char* dest, char* src,char* ly)
//{
//	while (*dest!=*src)
//	{
//		if (*dest == '\0')
//			return ly;
//		*ly++ = *dest++;
//	}
//	do{
//	      *ly++=*src;
//	}while (*dest++ == *src++);
//	while (*ly++=*src++)
//	{
//		;
//	}
//	return ly;
//}
//
//int main()
//{
//	char a[20][50];
//	char ly[1000]="\0";
//	char* lpn=ly;
//	int n, m,t=0;
//	scanf("%d", &n);
//	for ( m = 0; m < n; m++)
//	{
//		scanf("%s", a[m]);
//	}
//	
//	printf("%d", strlen(ly));
//	return 0;
//}