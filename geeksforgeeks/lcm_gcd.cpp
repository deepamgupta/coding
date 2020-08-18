// https://practice.geeksforgeeks.org/problems/inversion-of-array/0
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define foi(_n1, _n2) for (int i = _n1; i < _n2; ++i)
#define foj(_n1, _n2) for (int j = _n1; j < _n2; ++j)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

ull get_gcd(ull a, ull b)
{
    pair<ull, ull> small_large = minmax(a, b);
    ull remain = small_large.second % small_large.first;
    while (remain)
        small_large.second = small_large.first,
        small_large.first = remain,
        remain = small_large.second % small_large.first;
    return small_large.first;
}

ull get_lcm(ull a, ull b, ull gcd)
{
    return (a * b) / gcd;
}

pair<ull, ull> calculateGCDLCM(ull a, ull b)
{
    ull gcd = get_gcd(a, b);
    ull lcm = get_lcm(a, b, gcd);
    return pair<ull, ull>(gcd, lcm);
}

int main()
{
    SPEED;
    int t;
    cin >> t;

    while (t--)
    {
        ull a, b;
        cin >> a >> b;
        pair<ull, ull> gcd_lcm;
        gcd_lcm = calculateGCDLCM(a, b);
        cout << gcd_lcm.second << " " << gcd_lcm.first << "\n";
    }

    return 0;
}
