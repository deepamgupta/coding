// https://www.codechef.com/SEPT19B/problems/FIBEASY
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int
#define ld long double
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)

vector<short int> a(60);

ull fibo(ull number)
{
      if (number == 0)
            return 0;
      else if (number == 1 or number == 2)
            return 1;

      if (a[number])
            return a[number];

      return a[number] = (fibo(number - 1) + fibo(number - 2)) % 10;
}

int main()
{
      SPEED;
      int t;
      cin>>t;

      while (t--)
      {
            ull n;
            cin >> n;
            ull power = floor(log2l(n));
            ull number = pow(2, power);
            // cout<<number;

            cout << fibo(number%60 - 1) << endl;
      }
}