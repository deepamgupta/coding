// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int ans = 0;

        while (left <= right)
        {
            maxLeft = max(height[left], maxLeft);
            maxRight = max(height[right], maxRight);
            if (maxLeft < maxRight)
            {
                ans += maxLeft - height[left];
                left++;
            }
            else
            {
                ans += maxRight - height[right];
                right--;
            }
        }
        return ans;
    }
};