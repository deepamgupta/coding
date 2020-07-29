// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        else
        {
            ll largest_index = 0;
            ll sec_largest_index = 0;
            if (nums[0] >= nums[1])
            {
                largest_index = 0, sec_largest_index = 1;
            }
            else
            {
                largest_index = 1, sec_largest_index = 0;
            }
            if (nums.size() >= 3)
            {
                for (int i = 2; i < nums.size(); i++)
                {
                    if (nums[i] > nums[sec_largest_index])
                    {
                        if (nums[i] > nums[largest_index])
                        {
                            sec_largest_index = largest_index;
                            largest_index = i;
                        }
                        else
                        {
                            sec_largest_index = i;
                        }
                    }
                }
            }

            if (nums[largest_index] >= 2 * nums[sec_largest_index])
            {
                return largest_index;
            }
            else
            {
                return -1;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution s = Solution();
    cout << s.dominantIndex(nums) << "\n";
}