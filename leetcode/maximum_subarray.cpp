// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (size_t i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int localMax = nums[0];
        int globalMax = nums[0];

        foi(1, nums.size())
        {
            localMax = max(nums[i], localMax + nums[i]);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << Solution().maxSubArray(nums);
    cout << "\n";

    return 0;
}
