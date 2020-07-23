// https://www.codechef.com/problems/TF01
#include <bits/stdc++.h>
#include "time_duration.h"
using namespace std;
#define ll long long int
#define foi(_start, _end) for (int i = _start; i < _end; i++)
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

/*************************************start*******************************************/

bool subsetSum(ll sum, ll n, vector<ll> &wt)
{
    if (sum == 0)
    {
        return true;
    }
    if(sum != 0 & n == 0){
        return false;
    }
    if(wt[n] > sum){
        return subsetSum(sum, n-1, wt);
    }else
    {
        return subsetSum(sum-wt[n], n-1, wt) || subsetSum(sum, n-1, wt);
    }
}

/**************************************end*******************************************/

void solve()
{
    ll n;
    ll sum;
    cin >> n;
    cin >> sum;

    vector<ll> wt(n+1);
    foi(1, n+1)
    {
        cin >> wt[i];
    }

    TimeDuration::start();
    cout << subsetSum(sum, n, wt) ? 1 : 0;
    cout<<TimeDuration::duration_micro();
    cout<<"\n";
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