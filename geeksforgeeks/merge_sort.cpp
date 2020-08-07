// { Driver Code Starts
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);
        int arr[n+1];
        for (i=0;i<n;i++)
            scanf("%d", &arr[i]);

        mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
   /*   l is for left index and r is right index of the
      sub-array of arr to be sorted
   void mergeSort(int arr[], int l, int r) {
       if (l < r)   {
           int m = l+(r-l)/2;
           mergeSort(arr, l, m);
           mergeSort(arr, m+1, r);
           merge(arr, l, m, r);
       }
   } */

   // Merges two subarrays of arr[].  First subarray is arr[l..m]
   // Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m+1, k = 0;
    int n = r-l+1;
    int ans[n];

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) ans[k++] = arr[i++];
        else if (arr[j] < arr[i]) ans[k++] = arr[j++];
        else {
            ans[k++] = arr[i++];
            ans[k++] = arr[j++];
        }
    }

    while (i <= m) ans[k++] = arr[i++];
    while (j <= r) ans[k++] = arr[j++];

    for (int p = l; p <= r; ++p) arr[p] = ans[p-l];
}