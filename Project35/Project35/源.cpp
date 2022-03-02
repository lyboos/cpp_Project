#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<limits>
#include <sstream>
#include<stdlib.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char* dict[5000];
    for (int i = 0; i < n; i++)
    {
        cin>>*dict[i];
    }
    int f = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        int num = atoi(dict[i]);
        char gender =dict[i][3];
        if (gender == 'f') {
            f += num;
        }
        else {
            m += num;
        }
    }
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
    return 0;
}
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