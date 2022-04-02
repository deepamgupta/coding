// https://www.codechef.com/OCT20B/problems/CHEFEZQ

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll firstFreeDay(ll n, ll k, vector<ll> queries)
{
    ll carry = 0;

    for (ll i = 0; i < n; ++i)
    {
        ll queriesToday = queries[i] + carry;

        if (queriesToday < k)
            return i + 1;

        carry = queriesToday - k;
    }

    return n + (carry / k) + 1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> queries(n);
        for (ll i = 0; i < n; ++i)
            cin >> queries[i];
        cout << firstFreeDay(n, k, queries) << "\n";
    }

    return 0;
}