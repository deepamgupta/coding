#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forn(n) for (int i = 0; i < n; i++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

ll get_no_of_squares(int a, int b)
{
    ll count = 0;

    while (a && b)
    {
        if (a > b)
        {
            a -= b;
        }
        else if (a < b)
        {
            b -= a;
        }
        else
        {
            a = b = 0;
        }
        count++;
    }
    return count;
}

ll total_children(int p, int q, int r, int s)
{
    ll square_choclates = 0;
    for (int i = p; i <= q; i++)
    {
        for (int j = r; j <= s; j++)
        {
            square_choclates += get_no_of_squares(i, j);
        }
    }
    return square_choclates;
}

int main()
{
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    cout << total_children(p, q, r, s);
}