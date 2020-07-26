// https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1161/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Solution
{
public:
    vector<int> compute_lps(string &needle) // longest proper prefix which is also suffix
    {
        vector<int> lps(needle.size());
        int i = 1, j = 0;
        lps[0] = 0;
        while (i < needle.size())
        {
            if (needle[i] == needle[j])
            {
                ++j;
                lps[i] = j;
                ++i;
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
        return lps;
    }

    int strStr(string &haystack, string &needle)
    {
        cout << compute_lps(needle) << "\n";
    }
};
int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    string sum = Solution().strStr(haystack, needle);

    cout << sum << "\n";

    return 0;
}
