#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int findkth(int l, int r, int k, vector<int>& a);
int partition(int l, int r, int q, vector<int>& a);
int selectpivot(int l, int r, vector<int>& a);
inline void swap(int a, int b, vector<int>& arr) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
//int main(void) {
//	int k, size, i, tmp;
//	cin >> k >> size;
//	vector<int> a;
//	for (i = 0; i < size; i++) {
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	int pivotl = (size - 1) / 2 - k;
//	int pivotr = (size - 1) / 2 + k;
//	findkth(0, size - 1, pivotl, a);
//	findkth(pivotl + 1, size - 1, pivotr, a);
//	sort(a.begin() + pivotl, a.begin() + pivotr);
//	int mid = (pivotl + pivotr) / 2;
//	for (i = 0; i <= 2 * k; i++) {
//		if ((i + pivotl) != mid) {
//			cout << a[i + pivotl] << " ";
//		}
//	}
//	return 0;
//}
int selectpivot(int l, int r, vector<int>& a) {
	int size = r - l + 1;
	if (size <= 5) {
		return a[(l + r) / 2];
	}
	int midsize = size / 5;
	if (size % 5 != 0) {
		size++;
	}
	int i;
	vector<int>mid;
	for (i = 0; i < midsize - 1; i++) {
		sort(a.begin() + l + i * 5, a.begin() + l + (i + 1) * 5);
		mid.push_back(a[l + 2 + 5 * i]);
	}
	sort(a.begin() + i * 5 + l, a.begin() + r + 1);
	mid.push_back(a[(l + i * 5 + r) / 2]);
	return selectpivot(0, midsize - 1, mid);
}
int partition(int l, int r, int q, vector<int>& a) {
	swap(q, r, a);
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++) {
		if (a[j] < pivot) {
			i++;
			swap(i, j, a);
		}
	}
	swap(i + 1, r, a);
	return i + 1;
}
int findkth(int l, int r, int k, vector<int>& a) {
	int pivot = selectpivot(l, r, a);
	int i = l;
	for (; i < r; i++) {
		if (a[i] == pivot) {
			break;
		}
	}
	pivot = partition(l, r, i, a);
	if (pivot == k) { return a[pivot]; }
	else if (pivot < k) { return findkth(pivot + 1, r, k, a); }
	else {
		return findkth(l, pivot - 1, k, a);
	}

}