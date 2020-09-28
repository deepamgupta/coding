#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        s = clearExtraSpaces(s);
        s = reverseEachWordInString(s);
        return s;
    }

    string clearExtraSpaces(string s)
    {
        int i = 0, j = 0;
        int n = s.length();

        bool flag = true;

        if (s[0] != ' ')
        {
            while (true)
            {
                while (i < n && s[i] != ' ')
                    ++i;
                if (i >= n)
                    return s;
                ++i;
                if (i < n && s[i] == ' ')
                    break;
            }
        }

        j = i;

        while (j < n)
        {
            while (j < n && s[j] == ' ')
                ++j;
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            if (j < n)
                s[i++] = ' ';
        }

        return s.substr(0, i);
    }

    string reverseEachWordInString(string s)
    {
        int i = 0, j = 0;
        int n = s.length();
        while (j < n)
        {
            while (s[j] != ' ')
                ++j;
            reverseWord(s, i, j);
            i = j = j + 1;
        }
        return s;
    }

    void reverseWord(string &a, int i, int j)
    {
        while (i < j)
        {
            char t = a[i];
            a[i++] = a[j];
            a[j--] = t;
        }
    }
};

int main()
{
    string s = "";
    getline(cin, s);
    cout << Solution().reverseWords(s) << "\n";
    return 0;
}

