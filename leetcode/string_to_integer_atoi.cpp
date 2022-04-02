// https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {

        int n = str.length();

        if (n == 0)
        {
            return 0;
        }

        int i = 0;

        while (i < n && str[i] == ' ')
        {
            ++i;
        }

        // now i is at first non-whitespace character

        if (i == n || (str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')))
        {
            return 0;
        }

        bool is_negative;

        if (str[i] == '+' || str[i] == '-')
        {
            is_negative = (str[i] == '-') ? true : false;
            ++i;

            if (i == n || !(str[i] >= '0' && str[i] <= '9'))
            {
                return 0;
            }
        }

        while (i < n && str[i] == '0')
        {
            ++i;
        }

        if (i == n)
        {
            return 0;
        }

        int j = i;

        while (j < n && str[j] >= '0' && str[j] <= '9')
        {
            ++j;
        }

        string num_str = str.substr(i, j - i);

        if (num_str.length() > 10)
        {
            if (is_negative)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }

        i = num_str.length() - 1;
        long long place_value = 1;

        long long ans = 0;

        while (i >= 0)
        {
            ans += (num_str[i] - '0') * place_value;
            --i;
            place_value *= 10;
        }

        ans *= is_negative ? -1 : 1;

        if (ans < INT_MIN)
        {
            return INT_MIN;
        }
        else if (ans > INT_MAX)
        {
            return INT_MAX;
        }

        return ans;
    }
};

int main()
{
    string s = "";
    getline(cin, s);
    cout << Solution().myAtoi(s) << "\n";
    return 0;
}
