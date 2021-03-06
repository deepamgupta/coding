#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define repi(n1, n2) for (size_t i = n1; i < n2; i++)
#define repj(n1, n2) for (size_t j = n1; j < n2; j++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

ull coins(int p, int x, int y, int z)
{
    pair<int, int> s_b = minmax(x, y);
    ull n = max(s_b.first*2, s_b.second);
    return n*n*p;
}

int main()
{
    SPEED;
    int t;
    cin >> t;

    while (t--)
    {
        int p, x, y, z;
        cin>>p>>x>>y>>z;
        cout<<coins(p, x, y, z)<<"\n";
    }

    return 0;
}
