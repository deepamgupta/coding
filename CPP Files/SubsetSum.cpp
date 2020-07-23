// https://www.codechef.com/problems/TF01
#include <bits/stdc++.h>
#include "time_duration.h"
using namespace std;
#define ll long long int
#define foi(_start, _end) for (int i = _start; i < _end; i++)
#define foj(_start, _end) for (int j = _start; j < _end; j++)
#define newl "\n";
#define tab "\t"; 
#define space " ";
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

bool subsetSum(ll sum, ll n, vector<ll> &wt)
{
    vector<vector<bool>> dp (n+1, vector<bool>(sum+1));

    auto init = [] (vector<vector<bool>> &dp){
        foi(0, dp.size()){
            dp[i][0] = true;
        }
        foi(1, dp[0].size()){
            dp[0][i] = false;
        }
    };

    init(dp);

    foi(1, n+1){
        foj(1, sum+1){
            if(wt[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else
            {
                dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
            }
            cout<<dp[i][j]<<space;
        }
        cout<<newl;
    }
    return dp[n][sum];
}

void solve()
{
    ll n;
    ll sum;
    cin >> n;
    cin >> sum;

    vector<ll> wt(n);
    foi(0, n)
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