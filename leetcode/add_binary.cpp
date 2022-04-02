// https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/
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
    string addBinary(string a, string b)
    {
        SPEED;
        if (a == "0")
            return b;
        else if (b == "0")
            return a;
        string sum = "";
        pair<string, string> small_large = a.size() > b.size() ? pair<string, string>(b, a) : pair<string, string>(a, b);
        bool carry = false;
        int i, j;
        int small_size = small_large.first.size();
        int large_size = small_large.second.size();
        for (i = small_size - 1, j = large_size - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (small_large.first[i] == '1' && small_large.second[j] == '1')
            {
                if (carry)
                    sum = '1' + sum;
                else
                    sum = '0' + sum;
                carry = true;
            }
            else if (small_large.first[i] == '1' || small_large.second[j] == '1')
            {
                if (carry)
                    sum = '0' + sum;
                else
                    sum = '1' + sum, carry = false;
            }
            else
            {
                if (carry)
                    sum = '1' + sum;
                else
                    sum = '0' + sum;
                carry = false;
            }
        }
        int remain = i >= 0 ? i : j;
        if (remain >= 0)
            for (; remain >= 0; --remain)
            {
                if (small_large.second[remain] == '1')
                {
                    if (carry)
                        sum = '0' + sum;
                    else
                        sum = '1' + sum;
                }
                else
                {
                    if (carry)
                        sum = '1' + sum, carry = false;
                    else
                        sum = '0' + sum;
                }
            }

        if (carry)
            sum = '1' + sum;
        return sum;
    }
};
int main()
{
    string a, b;
    cin >> a >> b;
    string sum = Solution().addBinary(a, b);

    cout << sum << "\n";

    return 0;
}
