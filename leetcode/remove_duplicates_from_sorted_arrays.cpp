// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (!nums.size())
            return 0;

        int i = 0, j = 0;
        int n = nums.size();

        while (j < n)
        {
            int current = nums[j];
            while (j < n && nums[j] == current)
            {
                ++j;
            }
            if (j < n)
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};
