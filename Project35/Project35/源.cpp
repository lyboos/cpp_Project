#define  _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<iostream>
#include<limits>
#include <sstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
    char bfcode[1023] = { 0 }, paper[1023] = {0};
    int pointer = 0;
    int stack[233], stp = 0;
    cin.getline(bfcode,1023);
    for (int i = 0; bfcode[i]!='\0'; i++)
    {
        switch (bfcode[i]) {
        case '+':
            paper[pointer]++;
            break;
        case '-':
            paper[pointer]--;
            break;
        case '>':
            pointer++;
            break;
        case '<':
            pointer ? pointer-- : pointer;
            break;
        case ',':
            scanf("%c", &paper[pointer]);
            break;
        case '.':
            printf("%c", paper[pointer]);
            break;
        case '[':
            if (paper[pointer] != 0) {
                stack[stp] = i; stp++;
            }
            break;
        case ']':
            if (paper[pointer] != '\0') i = stack[stp - 1];
            else {
                stack[stp - 1] = 0;
                stp--;
            }
            break;
        default:break;
        }
    }
    return 0;
}

//int main() {
//    char res[20][120] = { 0 };
//    int n;
//    char str[60];
//    cin >> str >> n;
//    int row = 0,column=0;
//    for (int i = 0; i < strlen(str); i++)
//    {
//        int index = i % (2 * n - 2);
//        bool flag = true;
//        if (index < n) flag = false;
//        index = index < n ? index : 2 * n - 2 - index;
//        char temp[] = {str[i],' ','\0'};
//        strcat(res[index], temp);
//        if(flag)
//        for (int i = 0; i < n; i++)
//        {
//            if (i != index) {
//                strcat(res[i], "  ");
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << res[i] << endl;
//    }
//    return 0;
//}
//int capacity = 0;
//int num = 0;
//void add(int** arr, char* order) {
//    int* arry = *arr;
//    if (*arr == NULL) {
//        arry =(int *)malloc(sizeof(int) * 10);
//        capacity = 10;
//        *arr = arry;
//    }
//    else if(capacity==num){
//        int n= capacity + (capacity >> 1);
//        int* temp = NULL;
//        temp=*arr;
//        arry = (int*)malloc(sizeof(int)*n);
//        for (int i = 0; i < n; i++)
//        {
//            *(arry + i) = *(temp+i);
//        }
//        capacity = capacity + (capacity >> 1);
//        *arr = arry;
//    }
//    order += 4;
//    int n = atoi(order);
//    *(arry + num) = n;
//    num++;
//    *arr = arry;
//}
//
//void remove(int** arr, char order[51]) {
//    int* arry = *arr;
//    order += 6;
//    int n = atoi(order);
//    int i = 0;
//    for (i = 0; i < num; i++)
//    {
//        if (*(arry + i) == n) {
//            break;
//        }
//    }
//    int* temp= (int*)malloc(sizeof(int) * capacity);
//    if (i < num) {
//        int j = 0;
//        for (j = 0; j < i; j++)
//        {
//            *(temp + j) = *(arry + j);
//        }
//        for (int k = i+1; k < num; k++)
//        {
//            *(temp + j + k - i-1) = *(arry+k);
//        }
//        num--;
//    }
//}
//
//void get(int** arr, char order[51]) {
//    order += 4;
//    int n = atoi(order);
//    if (n >= capacity || n >= num || n <0)
//    {
//        cout << -1 << endl;
//        return;
//    }
//    int* arry = *arr;
//    cout << *(arry + n) << endl;
//}
//
//
//void getsize(int** arr) {
//    if (*arr == NULL) {
//        cout << 0 << endl;
//    }
//    else {
//        cout << num << endl;
//    }
//}
//
//void getcapa(int** arr) {
//    if (*arr == NULL) {
//        cout << 0 << endl;
//    }
//    else {
//        cout << capacity << endl;
//    }
//}
//
//
//int main() {
//    char order[20][51] = { 0 };
//    int n;
//    int* arr= NULL;
//    scanf("%d", &n);
//    cin.get();
//    for (int i = 0; i < n; i++)
//    {
//        cin.getline(order[i], 51);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        switch (order[i][0])
//        {
//        case 'a':
//            add(&arr, order[i]);
//            break;
//        case 'r':
//            remove(&arr, order[i]);
//            break;
//        case 'g':
//            if (order[i][3] == ' ') get(&arr, order[i]);
//            else if (order[i][3] == 'S') getsize(&arr);
//            else if (order[i][3] == 'C') getcapa(&arr);
//        default:
//            break;
//        }
//    }
//    return 0;
//}

//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    int arr[50][50] = { 0 };
//    int arr2[50][50] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++) {
//            scanf("%d",&arr[i][j]);
//        }
//    }
//    for (int k = 0; k < (m/90); k++)
//    {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++)
//            {
//                arr2[j][n - i-1] = arr[i][j];
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++)
//            {
//                arr[i][j] = arr2[i][j];
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//            cout << arr2[i][j]<<' ';
//        cout << '\n';
//    }
//    return 0;
//}
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    int arr[50][50] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++) {
//            cin >> arr[i][j];
//        }
//    }
//
//    int left = 0, right = m - 1, top = 0, bottom = n - 1;
//    while (true)
//    {
//        if (left > right) break;
//        for (int i = left; i <= right; i++)
//        {
//          
//            cout << arr[top][i] << ' ';
//        }
//        top++;
//
//
//        if (top > bottom) break;
//        for (int i = top; i <= bottom ; i++)
//        {
//            cout << arr[i][right] << ' ';
//        }
//        right--;
//
//
//        if (left > right) break;
//        for (int i = right; i >= left; i--)
//        {
//            cout << arr[bottom][i] << ' ';
//        }
//        bottom--;
//
//
//        if (top > bottom) break;
//        for (int i = bottom; i >= top; i--)
//        {
//            cout << arr[i][left] << ' ';
//        }
//        left++;
//    }
//
//
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++) {
//            if(j!=m-1)
//            cout << arr[i][j]<<' ';
//            else cout << arr[i][j] << '\n';
//        }
//    }
//    return 0;
//}
//int main() {
//    string pszSource;
//    char temp;
//    while (cin.get(temp)) {
//        pszSource = pszSource + temp;
//    }
//    string output;
//    int nByteSrc = pszSource.size();
//    const char* enkey = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//    std::string pszEncode(nByteSrc * 4 / 3 + 4, '\0');
//    int nLoop = nByteSrc % 3 == 0 ? nByteSrc : nByteSrc - 3;
//    int n = 0;
//    int i = 0;
//    for ( i = 0; i < nLoop; i += 3)
//    {
//           pszEncode[n] = enkey[pszSource[i] >> 2];
//               pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xF0) >> 4)];
//                pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0x0f) << 2) | ((pszSource[i + 2] & 0xc0) >> 6)];
//                 pszEncode[n + 3] = enkey[pszSource[i + 2] & 0x3F];
//              n += 4;
//    }
//   
//    switch (nByteSrc % 3)
//    {
//            case 0:
//                     pszEncode[n] = '\0';
//                     break;
//            
//             case 1:
//                     pszEncode[n] = enkey[pszSource[i] >> 2];
//                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((0 & 0xf0) >> 4)];
//                     pszEncode[n + 2] = '=';
//                   pszEncode[n + 3] = '=';
//                    pszEncode[n + 4] = '\0';
//                     break;
//            
//             case 2:
//                     pszEncode[n] = enkey[pszSource[i] >> 2];
//                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xf0) >> 4)];
//                   pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0xf) << 2) | ((0 & 0xc0) >> 6)];
//                     pszEncode[n + 3] = '=';
//                     pszEncode[n + 4] = '\0';
//                     break;
//                 }
//    
//       cout<<pszEncode;
//   
//    return 0;
//}
//    string output;
    /*string input;
    char temp;
    int num = 0, line = 0;
    while (cin.get(temp)) {
        input = input + temp;
    }
    int flag = 0;
    for (int i = 0; i < input.size(); i++)
    {
        switch (input.at(i))
        {
        case ' ':
            if (flag == 1) num++;
            flag = 0;
            break;
        case '\n':
            if (flag == 1) num++;
            flag = 0;
            line++;
            break;
        default:
            flag = 1;
            break;
        }
    }
    if (input.size() == 0) num = 0, line = 0;
    cout << input.size() << ' ' << num << ' ' << line;*/
    
/*int n;
    cin >> n;
    cin >> ws;
    string* dict=new string[5000];
    char* tmp = new char[100];
    int f = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        cin.getline(tmp, 100);
        int num = atoi(tmp);
        char* gender1 = strstr(tmp," ");
        char gender = *(gender1 + 1);
        if (gender == 'f') {
            f += num;
        }
        else if (gender == 'm') {
            m += num;
        }
    }
    cout << "f: " << f << endl;
    cout << "m: " << m << endl;*/
    /*int num = 0;
    int line = 0;
    int words = 0;
    string* dict[5000];
    int i = 0;
    while (cin.get()!='\n') {
        dict[i] = new string();
        getline(cin, *dict[i]);
        cout << *dict[i];
        i++;
    }*/
    /*int n = 0, count = 0;
    int tmp;
    int arr[10000];
    while (cin >> tmp) {
        arr[count] = tmp;
        n = arr[count] ^ n;
        count++;
    }
    cout << n;*/
    //cin >> n;
    //for (int i = 0; i < n; i++) {
    //    cin >> arr[i];
    //}
    //long long sum=1;
    //for (int i = 0; i < n; i++)
    //{
    //    sum *= arr[i];
    //    //int64_t tmp = (int64_t)sum * (int64_t)arr[i];
    //    //if ((int32_t)((int32_t)tmp) != tmp)
    //        // overflow occurred
    //    if(sum > numeric_limits<int>::max()||sum< numeric_limits<int>::min())
    //    //if(arr[i]!=0&&sum==0)
    //    {
    //        cout << -1;
    //        break;
    //    }
    //    else {
    //        cout << sum;
    //    }
    //    if (i != n - 1) cout << ' ';
    //}
        /*string numstr; long num;
        stringstream aa;
        cin >> numstr;
        aa << numstr;
        aa >> num;
        if (num >= 0) {

            num = rev(num);
            cout << num << endl;
        }
        else
        {
            num = -num;
            num = rev(num);
            if(num==0)  cout << -1<< endl;
            else cout << '-'<<num << endl;
        }*/
 /*       return 0;
}*/


int rev(long m)
{
    if (m > numeric_limits<int>::max())
        return -1;
    long t = 0;
    while (m > 0)
    {
        t = t * 10 + m % 10;
        m = m / 10;
    }
    return t;
}