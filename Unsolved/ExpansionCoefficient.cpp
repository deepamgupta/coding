#include <iostream>
#include<cmath>
using namespace std;

int main () {
   int n;
   cin>>n;

   unsigned int arr[n];

   for(int i = 0; i < n; i++){
      cin>>arr[i];
   }

  
   unsigned int max = INT32_MAX;
   for (int i = 0; i < n-1; i++)
   {
      for (int j = i+1; j < n; j++)
      {
         unsigned int k = min(arr[i], arr[j])/abs(i-j);
         if (k < max) max = k;
      }
   }

   cout<<max;
   
}
