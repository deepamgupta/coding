// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int i = 0;
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> mp;
        while (i < n)
        {
            while (i < n && (mp.find(s[i]) == mp.end() || mp[s[i]] < start))
            {
                mp[s[i]] = i;
                ++i;
            }
            maxLen = max(maxLen, i - start);
            start = mp[s[i]] + 1;
        }
        return maxLen;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s) << "\n";
}
