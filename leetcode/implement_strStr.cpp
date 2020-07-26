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
    vector<int> compute_lps(string &needle) // longest proper prefix which is also suffix, in short=> kitni length tak already match kr jaaega
    {
        int n = needle.size();
        vector<int> lps(n);
        int i = 1, j = 0;
        lps[0] = 0;
        while (i < n)
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
        int m = haystack.size(), n = needle.size();
        if (!n)
            return 0;
        if (n > m)
            return -1;
        vector<int> lps = compute_lps(needle);

        int i = 0;
        int j = 0;
        while (i < m)
        {
            if (haystack[i] == needle[j])
                ++i, ++j;
            if (j == n)
                return i - j;
            else if (i < m && haystack[i] != needle[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    ++i;
            }
        }

        return -1;
    }
};
int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    int index = Solution().strStr(haystack, needle);

    cout << index << "\n";

    return 0;
}
