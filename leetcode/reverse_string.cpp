// https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1183/
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
    void reverseString(vector<char> &s)
    {
        SPEED
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
        for (char c : s)
            cout << c << "\n";
    }
};
int main()
{
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    Solution().reverseString(s);

    return 0;
}
