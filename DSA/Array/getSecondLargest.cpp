#include <bits/stdc++.h>
using namespace std;
// naive: getLargest and find largest among remaining elements : two traversals
// int getLargest(int arr[], int n)
// {
//     int idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > arr[idx])
//         {
//             idx = i;
//         }
//     }
//     return idx;
// }

// int secondLargestNaive(int arr[], int n)
// {
//     int largestIdx = getLargest(arr, n);
//     int res = -1; // as it may happen that all elen=ments are same thus no second largest element exist
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != arr[largestIdx])
//         {
//             if (res == -1)
//             {
//                 res = i;
//             }
//             else if (arr[i] > arr[res])
//             {
//                 res = i;
//             }
//         }
//     }

//     return res;
// }

// efficient solution: one traversal
int secondLargest(int arr[], int n)
{
    int res = -1, largest = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{

    int arr[] = {10, 10, 10, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << secondLargest(arr, n);
    return 0;
}