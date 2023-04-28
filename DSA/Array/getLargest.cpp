#include <bits/stdc++.h>
using namespace std;
int getLargest(int arr[], int n)
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[idx])
		{
			idx = i;
		}
	}
	return idx + 1;
}
// time complexity theta n

int main()
{

	int arr[] = {5, 8, 20, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "position: " << getLargest(arr, n);
	return 0;
}
