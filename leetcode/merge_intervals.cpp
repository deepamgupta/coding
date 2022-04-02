// https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (size_t i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    static bool sortCol1(const vector<int> &v1, const vector<int> &v2) { return v1[0] < v2[0]; }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), sortCol1);
        vector<int> newInterval = intervals[0];
        int i = 1;
        while (true)
        {
            while (i < intervals.size() && intervals[i][0] <= newInterval[1])
                newInterval[1] = max(newInterval[1], intervals[i][1]), ++i;

            ans.push_back(newInterval);

            if (i == intervals.size())
                break;

            newInterval = intervals[i];
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> intervals[i][0] >> intervals[i][1];

    vector<vector<int>> ans = Solution().merge(intervals);
    for (vector<int> interval : ans)
    {
        cout << interval[0] << " " << interval[1] << "\n";
    }

    return 0;
}
