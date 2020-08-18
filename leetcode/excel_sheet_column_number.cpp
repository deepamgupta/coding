// https://leetcode.com/problems/excel-sheet-column-number/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution {
public:
    int titleToNumber(string s) {
        int colNum = 0;
        int len = s.size();
        long long powerOf26 = 1;
        for (size_t i = 0; i < len; ++i)
        {
            colNum += powerOf26 * int(s[len-i-1] - 'A' + 1);
            powerOf26 *= 26;
        }
        return colNum;

    }
};

int main()
{
    string s;
    cin >> s;

    cout<< Solution().titleToNumber(s)<<"\n";
    return 0;
}
