#include <bits/stdc++.h>
using namespace std;
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

#define ll long long

ll getMaximumCoins(ll n, vector<vector<ll>> &v)
{
    ll ans = 0;
    for (ll k = 0; k < n; ++k)
    {
        ll cur = 0;
        ll i = 0, j = k;
        while (i < n && j < n)
        {
            cur += v[i][j];
            ++i, ++j;
        }
        ans = max(ans, cur);
    }
    for (ll k = 0; k < n; ++k)
    {
        ll cur = 0;
        ll i = k, j = 0;
        while (i < n && j < n)
        {
            cur += v[i][j];
            ++i, ++j;
        }
        ans = max(ans, cur);
    }

    return ans;
}

int main()
{
    SPEED;
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> v(n, vector<ll>(n));
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < n; ++j)
            {
                cin >> v[i][j];
            }
        }

        cout << "Case #" << i << ": " << getMaximumCoins(n, v) << "\n";
    }
}