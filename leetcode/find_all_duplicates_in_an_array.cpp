// https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int key = abs(nums[i]);
            bool is_encountered = nums[key - 1] < 0 ? true : false;
            if (is_encountered)
                ans.push_back(key);
            else
                nums[key - 1] = -nums[key - 1];
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> ans = Solution().findDuplicates(nums);
    for (int e : ans)
    {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}
