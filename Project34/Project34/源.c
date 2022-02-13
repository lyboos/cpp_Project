#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int findMax(int arr[], int n) {
	if (n == 1) {
		return arr[0];
	}
	else
	{
		int temp = findMax(arr, n - 1);
		return temp > arr[n - 1] ? temp : arr[n - 1];
	}
}


double findAverage(int arr[], int n) {
	if (n == 1) {
		return (double)arr[0];
	}
	else
	{
		double sum = (double)(arr[n - 1] + (findAverage(arr, n - 1) * (n - 1))) / n;
		return sum;
	}
}

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%d",&arr[i]);
		//printf("%d", arr[i]);
	}
	double sum = findAverage(arr, 3);
	printf("\n%d\n",findMax(arr,3));
	printf("%lf\n",sum);
	return 0;
}

