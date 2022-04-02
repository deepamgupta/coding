#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fori(_start, _end) for (int i = _start; i < _end; i++)
#define forj(_start, _end) for (int j = _start; j < _end; j++)
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

string orthodox(vector<ll> a, int n)
{
    map<ll, ll> values;

    fori(0, n)
    {
        ll ors = 0;
        forj(i, n)
        {
            ors |= a[j];
            if (!values[ors])
                values[ors] = 1;
            else
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    SPEED;
    int t;
    // t = 1;
    cin >> t;
    fori(0, t)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        fori(0, n) cin >> a[i];
        cout << orthodox(a, n) << "\n";
    }
    return 0;
}