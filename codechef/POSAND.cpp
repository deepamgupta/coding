#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long

bool isPowerOfTwo(ll x)
{
    return !(x & (x - 1));
}

void printBeautifulPermutation(ll n)
{
    if (n == 1)
    {
        cout << 1;
        return;
    }

    if (isPowerOfTwo(n))
    {
        cout << (-1);
        return;
    }

    if (n == 3)
    {
        cout << "1 3 2";
        return;
    }

    cout << "2 3 1 5 4";

    ll i = 6;

    while (i <= n)
    {
        if (isPowerOfTwo(i))
        {
            cout << " " << i + 1 << " " << i;
            i += 2;
        }
        else
        {
            cout << " " << i;
            ++i;
        }
    }
    return;
}

int main()
{
    ll t;
    cin >> t;
    SPEED;
    while (t--)
    {
        ll n;
        cin >> n;
        printBeautifulPermutation(n);
        cout << "\n";
    }

    return 0;
}