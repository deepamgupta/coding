// https://www.codechef.com/COOK117B/problems/KPERM
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define foi(_start, _end) for (int i = _start; i < _end; i++)
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

void kPerm(ll &n, ll inv, vector<ll> perm, set<vector<ll>> &perms)
{
    if (!inv)
    {
        perms.insert(perm);
    }
    else
    {
        foi(0, n - 1)
        {
            if (perm[i] < perm[i + 1])
            {
                swap(perm[i], perm[i + 1]);
                if (perms.find(perm) == perms.end())
                    kPerm(n, inv - 1, perm, perms);
                swap(perm[i], perm[i + 1]);
            }
        }
    }
}

vector<ll> initialize(ll n)
{
    vector<ll> v(n);

    foi(0, n)
    {
        v[i] = i + 1;
    }
    return v;
}

void solve()
{
    ll n, inv, k;
    cin >> n >> inv >> k;
    ll max = n * (n + 1) / 2;
    if (inv > max)
    {
        cout << (-1);
    }
    else
    {
        vector<ll> perm = initialize(n);
        set<vector<ll>> perms;

        kPerm(n, inv, perm, perms);

        if (k > perms.size())
        {
            cout << (-1);
        }
        else
        {
            auto it = perms.begin();
            advance(it, k - 1);
            for (ll num : *it)
            {
                cout << num << " ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    SPEED;
    int t;
    // t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}