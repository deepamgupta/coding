// https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1162/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    string commonInTwo(string a, string b)
    {
        int min_size = min(a.size(), b.size());
        for (size_t i = 0; i < min_size; ++i)
        {
            if (a[i] != b[i])
                return a.substr(0, i);
        }
        return a.size() < b.size() ? a : b;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
            return "";
        string lcp = strs[0];
        for (int i = 0; i < strs.size() - 1; ++i)
        {
            string common_in_two = commonInTwo(strs[i], strs[i + 1]);
            if (!common_in_two.size())
                return "";
            if (common_in_two.size() < lcp.size())
                lcp = common_in_two;
        }
        return lcp;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
        cin >> strs[i];
    string lcp = Solution().longestCommonPrefix(strs);

    cout << lcp << "\n";

    return 0;
}
