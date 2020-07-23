// https://codeforces.com/blog/entry/67081
#include<bits/stdc++.h>
using namespace std;

long long absoulte(long long x){
   return -x ? x < 0 : x;
}

int main () {
   int n;
   cin>>n;
   long long a[n];

   for (size_t i = 0; i < n; i++)
   {
      long long t;
      cin>>t;
      a[i] = abs(t);
   }

   long long count = 0;



   for (size_t i = 0; i < n-1; i++)
   {
      for (size_t j = i+1; j < n; j++)
      {
         long long ax = absoulte(a[i]);
         long long ay = absoulte(a[j]);
         long long vx = absoulte(a[i] - a[j]);
         long long vy = absoulte(a[i] + a[j]);
         long long biga, smalla, bigv, smallv;


         if(ax > ay) biga = ax, smalla = ay;
         else biga = ay, smalla = ax;


         if(vx > vy) bigv = vx, smallv = vy;
         else bigv = vy, smallv = vx;

         if((smallv <= smalla) && bigv >= biga) count++;

      }
      
   }
   
   cout<<count;
   
}
