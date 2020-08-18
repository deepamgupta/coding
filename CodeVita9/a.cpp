#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1

#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned long long int M = 1000000007;

string elections(string q, ll n)
{
    ll i = 0;
    ll ac = 0, bc = 0;
    while (i < n)
    {
        while (q[i] != '-' && i < n)
        {
            if (q[i] == 'A')
                ++ac;
            else
                ++bc;
            ++i;
        }
        ll left = i;
        while (q[i] == '-' && i < n)
            ++i;

        ll right = i - 1;
        if (right < left)
            continue;
        // cout << left << " " << right << "\n";
        ll count = right - left + 1;
        if (left == 0)
        {
            if (q[right + 1] == 'A')
                ac += count;
        }
        else if (right == n - 1)
        {
            if (q[left - 1] == 'B')
                bc += count;
        }
        else if (q[left - 1] == 'A' && q[right + 1] == 'A')
            ac += count;
        else if (q[left - 1] == 'B' && q[right + 1] == 'B')
            bc += count;
        else if (q[left - 1] == 'B' && q[right + 1] == 'A')
            ac += count / 2, bc += count / 2;
    }
    // cout << ac << " " << bc << "\n";
    return ac > bc ? "A" : (ac == bc ? "Coalition government" : "B");
}

int main()
{
    SPEED;
    ll n;
    cin >> n;

    string q;
    cin >> q;

    cout << elections(q, n);
}