#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int n, int *arr)
{
    int no_of_swaps = 0;
    int no_of_comparison = 0;
    for (int i = 0; i < n; i++)
    {
        no_of_comparison++;
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                no_of_swaps++;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    cout << "Number of comparison: " << no_of_comparison << endl;
    cout << "Number of swaps: " << no_of_swaps << endl;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    int *arr = new int[n];
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(n, arr);
    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}