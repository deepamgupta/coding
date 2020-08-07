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

int pump(vector<int> &fuel, vector<int>& cost)
{
    int n = fuel.size();
    vector<int> travel(n);
    for (size_t i = 0; i < n; ++i)
    {
        travel[i] = fuel[i] - cost[i];
    }
    int sum = accumulate(travel.begin(), travel.end(), 0);
    if (sum < 0) return -1;

    for (size_t i = 0; i < n; ++i)
    {
        int path = i+1;
        int csum = travel[i];
        int count = 1;
        for (; count < n && csum>0; ++count, path=(path+1)%n)
        {
            csum+=travel[path];
        }
        if (count == i)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    SPEED;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;
        vector<int> fuel(n), cost(n);
        for (size_t i = 0; i < n; ++i)
        {
            cin>>fuel[i];
        }
        for (size_t i = 0; i < n; ++i)
        {
            cin>>cost[i];
        }
        cout<<pump(fuel, cost)<<"\n";
    }

    return 0;
}
