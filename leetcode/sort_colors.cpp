// https://leetcode.com/problems/sort-colors/submissions/
#include <bits/stdc++.h>

#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution  
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, b = nums.size() - 1, r = 0;

        while (i <= b)
        {
            while (nums[i] == 2 && i != b)
                swap(nums[i], nums[b--]);
            while (nums[i] == 0 && i != r)
                swap(nums[i], nums[r++]);
            ++i;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    Solution().sortColors(nums);
    for (int e : nums)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
