#include <bits/stdc++.h>
using namespace std;

int* checkFirst(array<int> arr, int n){
    int d = arr[n-1] - arr[n-2];
    array<int> brr(n);
    copy(begin(arr), end(arr), begin(brr));
    brr[0] = arr[n-1] - (n-1)*d;
    return (arr == brr) : arr ? brr;
}

int* checkLast(int* arr, int n){
    int d = arr[1] - arr[0];
    int brr[n];
    copy(begin(arr), end(arr), begin(brr));
    brr[n] = arr[0] + (n-1)*d;
    return equal(begin(arr), end(arr), begin(brr)) : brr ? arr;
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int n;
    cin>>n;

    array<int> arr(n);
    array<int> temp(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    temp = checkFirst(arr, n);
    if(temp == arr){
        temp = checkLast(arr, n);
        if(temp == arr){
            int d = (arr[n-1]-arr[0])/(n-1);

            for (size_t i = 0; i < n-1; i++)
            {
                arr[i] = arr[0]+i*d;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n"
    



    
   
   
}