#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

ll sumPairs(vector<ll> &arr)
{
    ll n = arr.size();
    ll sum = 0;
    for (ll i = n - 1; i >= 0; i--)
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    return sum;
}

ll totalDistance(string &s)
{
    ll total = 0;
    ll n = s.length();
    map<char, vector<ll>> mp;
    for (ll i = 0; i < n; ++i)
    {
        mp[s[i]].push_back(i);
    }

    for (auto it : mp)
    {
        total += sumPairs(it.second);
    }

    return total;
}

int main()
{
    SPEED;
    string s;
    cin >> s;

    cout << totalDistance(s);
    return 0;
}
