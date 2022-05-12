#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
long long  mergesrt(string A[], long long l, long long r);
long long  merge(string A[], long long l, long long r, long long q);
//int main(void) {
//    long long i = 0;
//    long long size = 0;
//    scanf("%lld\n",&size);
//    cin >> size;
//    if (size <= 1) {
//        return 0;
//    }
//    char ch;
//    string* A = new string[size];
//    char temp[11] = " ";
//    for (i = 0; i < size; i++) {
//        cin >> A[i];
//    }
//    //cout << i + 1<<endl;
//    //string* B = new string[size];
//    cout << "A:" << endl;
//    for (i = 0; i < size; i++) {
//        cout << A[i] << endl;
//        //    B[i] = A[i];
//    }
//    //cout << "B:"<<endl;
//    //for (i = 0;i < size;i++) {
//    //    cout << B[i] << endl;
//    //}
//    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
//    long long count = mergesrt(A, 0, size - 1);
//    cout << count << endl;
//    for (i = 0; i < size; i++) {
//        cout << A[i] << endl;
//    }
//    return 0;
//}
long long merge(string A[], long long l, long long r, long long q) {
    long long size1 = q - l + 1;
    long long size2 = r - q;
    long long i = 0, j = 0;
    long long count = 0;
    string* B = new string[size1];
    string* C = new string[size2];
    for (i = 0; i < size1; i++) {
        B[i] = string(A[l + i]);
    }
    for (i = 0; i < size2; i++) {
        C[i] = string(A[i + q + 1]);
    }
    long long p = l;
    i = 0; j = 0;
    while (p <= r) {
        if (i < size1 && j < size2) {
            if (B[i].compare(C[j]) > 0) {
                A[p] = C[j];
                count += (size1 - i);
                j++;
            }
            else {
                A[p] = B[i];
                i++;
            }


        }
        else if (i >= size1 && j < size2) {
            A[p] = C[j];
            j++;

        }
        else if (i < size1 && j >= size2) {
            A[p] = B[i];
            i++;

        }
        p++;
    }
    delete[]C;
    delete[]B;
    return count;
}
long long mergesrt(string A[], long long l, long long r) {
    if (l < r) {
        long long a = mergesrt(A, l, (l + r) / 2);
        long long b = mergesrt(A, (l + r) / 2 + 1, r);
        return a + b + merge(A, l, r, (l + r) / 2);
    }
    if (l == r) {
        return 0;
    }
}