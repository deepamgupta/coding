// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        int i = 0;
        int n = heights.size();
        stack<int> s;
        while (i < n)
        {
            if (s.empty() || heights[i] >= heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int tp = s.top();
                s.pop();
                int curArea = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, curArea);
            }
        }

        while (!s.empty())
        {
            int tp = s.top();
            s.pop();
            int curArea = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    cout << Solution().largestRectangleArea(heights) << "\n";
}
