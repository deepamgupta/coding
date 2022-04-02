#include <bits/stdc++.h>
using namespace std;

// #define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long

ll solve(ll n, vector<ll> &v)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return v[0];
    }

    ll sum1 = 0;
    ll sum2 = 0;
    for (ll i = 0; i < n; i += 2)
    {
        sum1 += v[i];
    }
    for (ll i = 1; i < n; i += 2)
    {
        sum2 += v[i];
    }
    return max(sum1, sum2);
}

int main()
{
    ll t;
    cin >> t;
    // SPEED;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; ++i)
        {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        cout << solve(n, v) << "\n";
    }

    return 0;
}