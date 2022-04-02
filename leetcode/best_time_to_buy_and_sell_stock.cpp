// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (int i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int global_max = 0;
        int current_max = 0;
        foi(0, prices.size()-1) {
            int diff = prices[i+1] - prices[i];
            current_max = max(0, current_max+diff);
            global_max = max(global_max, current_max);
        }
        return global_max;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << Solution().maxProfit(nums)<<"\n";

    return 0;
}
