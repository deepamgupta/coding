// https://www.codechef.com/JUNE19B/problems/PROXYC

#include <bits/stdc++.h>
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int howMuchProxy(string s, int n){
  int P = count(s.begin(), s.end(), 'P');
  int required = ceil(0.75*n);
  return required-P > 0 ? required-P : 0;
}

int proxyPossible(string s, int n){
  int count = 0;
  for(int i = 2; i < n-2; i++){
    if((s[i] == 'A') && (s[i-2] == 'P' or s[i-1] == 'P') && (s[i+1] == 'P' or s[i+2] == 'P')) count++;
  }
  return count;
}

int main()
{
  SPEED;
  int t;
  cin>>t;

  while (t--)
  {
    int d;
    cin>>d;

    string s;
    cin>>s;

    int remain = howMuchProxy(s, d);

    if(remain){
      int avail = proxyPossible(s, d);
      if(avail < remain){
        cout<<"-1"<<endl;
      }
      else{
        cout<<remain<<endl;
      }
    }
    else{
      cout<<"0"<<endl;
    }
  }
  
}

