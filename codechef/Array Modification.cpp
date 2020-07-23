// https://www.codechef.com/OCT19B/problems/MARM
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define repi(n1, n2) for (size_t i = n1; i < n2; i++)
#define repj(n1, n2) for (size_t j = n1; j < n2; j++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

int manipulate(vector<int> &a, int n, int times, int remain)
{
      for (int i = 0; i < times; i++)
      {
            for (int j = 0; j < n; j++)
            {

                  int temp = j % n;
                  a[temp] = a[temp] ^ a[n - temp - 1];
            }
      }
      for (int i = 0; i < remain; i++)
      {
            int temp = i % n;
            a[temp] = a[temp] ^ a[n - temp - 1];
      }
      if (n & 1)
            a[(n - 1) / 2] = 0;
      return 0;
}

int main()
{
      SPEED;
      int t;
      cin >> t;

      while (t--)
      {
            int n;
            ull k;
            cin >> n >> k;
            vector<int> a(n);

            for (int i = 0; i < n; i++)
            {
                  cin >> a[i];
            }

            if (n == 1)
                  a[0] = 0;
            else if (k <= n)
            {
                  for (int i = 0; i < k; i++)
                  {
                        a[i % n] = a[i % n] ^ a[n - i % n - 1];
                  }
            }
            else
            {
                  int times = (int)(k / n) % 3;
                  int remain = (int)(k % n);

                  manipulate(a, n, times, remain);
            }

            for (int i = 0; i < n; i++)
            {
                  cout << a[i] << " ";
            }
            
            cout << endl;
      }

      return 0;
}
