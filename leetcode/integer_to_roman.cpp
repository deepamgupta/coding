// https://leetcode.com/problems/integer-to-roman/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        if (!num)
            return "";

        string ans = "";
        int placeValue = 1000;

        while (placeValue)
        {
            int digit = num / placeValue;
            ans += digit ? getValue(digit, placeValue) : "";
            num %= placeValue;
            placeValue /= 10;
        }

        return ans;
    }

    string getValue(int digit, int placeValue)
    {
        switch (placeValue)
        {
        case 1000:
            return get1000s(digit);
        case 100:
            return get100s(digit);
        case 10:
            return get10s(digit);
        case 1:
            return get1s(digit);
        }
        return "";
    }

    string get1s(int digit)
    {
        switch (digit)
        {
        case 1:
            return "I";
        case 2:
            return "II";
        case 3:
            return "III";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 6:
            return "VI";
        case 7:
            return "VII";
        case 8:
            return "VIII";
        case 9:
            return "IX";
        }
        return "";
    }

    string get10s(int digit)
    {
        switch (digit)
        {
        case 1:
            return "X";
        case 2:
            return "XX";
        case 3:
            return "XXX";
        case 4:
            return "XL";
        case 5:
            return "L";
        case 6:
            return "LX";
        case 7:
            return "LXX";
        case 8:
            return "LXXX";
        case 9:
            return "XC";
        }
        return "";
    }

    string get100s(int digit)
    {
        switch (digit)
        {
        case 1:
            return "C";
        case 2:
            return "CC";
        case 3:
            return "CCC";
        case 4:
            return "CD";
        case 5:
            return "D";
        case 6:
            return "DC";
        case 7:
            return "DCC";
        case 8:
            return "DCCC";
        case 9:
            return "CM";
        }
        return "";
    }

    string get1000s(int digit)
    {
        switch (digit)
        {
        case 1:
            return "M";
        case 2:
            return "MM";
        case 3:
            return "MMM";
        }
        return "";
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().intToRoman(n);
    return 0;
}
