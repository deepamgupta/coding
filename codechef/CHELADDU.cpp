#include <bits/stdc++.h>
using namespace std;

// #define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long

ll solve(ll n, ll k, vector<ll> &v)
{

    if (k == 1)
    {
        return 0;
    }

    ll ans = INT_MAX;
    sort(v.begin(), v.end());

    for (ll i = 0; i <= n - k; ++i)
    {
        ans = min(ans, v[i + k - 1] - v[i]);
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    // SPEED;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for (ll i = 0; i < n; ++i)
        {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        cout << solve(n, k, v) << "\n";
    }

    return 0;
}