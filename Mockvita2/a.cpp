#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forn(n) for (int i = 0; i < n; i++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int pairs_left(string brides, string grooms, int n)
{
    ll married = 0;
    ll i = 0;
    ll j = 0;
    ll groom_left = n;
    for (i = 0; i < n; i++)
    {
        int groom_passed = 0;
        bool is_married = false;
        for (; groom_passed != groom_left; j = (j + 1) % n)
        {
            if (grooms[j] != '0')
            {
                if (brides[i] == grooms[j])
                {
                    grooms[j] = '0';
                    groom_left--;
                    married++;
                    is_married = true;
                    break;
                }
                else
                {
                    groom_passed++;
                }
            }
        }
        if (!is_married && groom_passed == groom_left)
        {
            break;
        }
    }
    return n - married;
}

int main()
{
    SPEED;
    ll n;
    cin >> n;
    string brides;
    string grooms;
    cin >> brides >> grooms;

    cout << pairs_left(brides, grooms, n);

    return 0;
}