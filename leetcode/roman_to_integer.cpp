https : //leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
        using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.length();
        if (!n)
        {
            return 0;
        }

        int sum = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            int cur = getValue(s[i]);

            if (cur < getValue(s[i + 1]))
            {
                sum -= cur;
            }
            else
            {
                sum += cur;
            }
        }
        return sum + getValue(s[n - 1]);
    }

    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};