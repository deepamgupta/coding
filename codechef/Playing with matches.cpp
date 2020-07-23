// https://www.codechef.com/COOK110B/problems/MATCHES
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int arr[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
      SPEED;
      int t;
      cin >> t;
      while (t--)
      {
            int a, b;
            cin >> a >> b;
            int count(0);
            int rem;
            int sum = a + b;

            while (sum)
            {
                  rem = sum % 10;
                  sum /= 10;
                  count += arr[rem];
            }
            cout << count << endl;
      }
}
