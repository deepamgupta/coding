// https://leetcode.com/problems/largest-number/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (size_t i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (!nums.size())
            return "0";

        vector<string> nums_string(nums.size());

        for (int i = 0; i < nums.size(); ++i)
            nums_string[i] = to_string(nums[i]);

        sort(nums_string.begin(), nums_string.end(), [](string &s1, string &s2) -> bool { return s1 + s2 > s2 + s1; });

        if (nums_string[0] == "0")
            return "0";

        string ans = "";
        for (string num_string : nums_string)
            ans += num_string;
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

    cout << Solution().largestNumber(nums) << "\n";

    return 0;
}
