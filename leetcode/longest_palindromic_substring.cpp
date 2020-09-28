// https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;

        int gm = 1;
        string ans = s.substr(0, 1);
        string cp = "";

        int i = 2;
        int l = 0, r = 0;

        if (s[0] == s[1])
            gm = 2, ans = s.substr(0, 2);

        while (i < n)
        {
            while (!(s[i] == s[i - 1] || s[i] == s[i - 2]) && i < n)
            {
                ++i;
            }

            if (i < n && s[i] == s[i - 1])
            {
                // even palindrome
                l = i - 2,
                r = i + 1;
                while (l >= 0 && r < n && s[l] == s[r])
                {
                    --l, ++r;
                }
                cp = s.substr(l + 1, r - l - 1);
                if (gm < cp.length())
                {
                    ans = cp, gm = cp.length();
                }
            }

            if (i < n && s[i] == s[i - 2])
            {
                // odd palindrome
                l = i - 3,     // 1
                    r = i + 1; // 3
                while (l >= 0 && r < n && s[l] == s[r])
                {
                    --l, ++r;
                }
                cp = s.substr(l + 1, r - l - 1);
                if (gm < cp.length())
                {
                    ans = cp, gm = cp.length();
                }
            }

            ++i;
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << "\n";
    return 0;
}