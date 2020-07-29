// https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1153/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    // When numbers are sorted
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        for (;;) // since, there is always an answer
        {
            int sum = numbers[i] + numbers[j];
            if (sum > target)
                --j;
            else if (sum < target)
                ++i;
            else
                return {i + 1, j + 1};
        }
        return {0, 0};
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int target;
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cin >> target;
    vector<int> ans = Solution().twoSum(nums, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
