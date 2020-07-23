
// https://www.codechef.com/OCT19B/problems/SAKTAN
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int
#define ll long long int
#define ld long double
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

int main()
{
      SPEED;
      ll t;
      cin >> t;
      while (t--)
      {
            ll n, m, q;
            cin >> n >> m >> q;
            map<ll, ll> row;
            map<ll, ll> col;
            while (q--)
            {
                  ll a, b;
                  cin >> a >> b;
                  row[a]++;
                  col[b]++;
                  if (!(row[a] & 1))
                        row.erase(row.find(a));
                  if (!(col[b] & 1))
                        col.erase(col.find(b));
            }

            ll oddr = row.size();
            ll oddc = col.size();

            ll ans = oddr * m + oddc * n - 2 * oddr * oddc;
            cout << ans << endl;
      }
}