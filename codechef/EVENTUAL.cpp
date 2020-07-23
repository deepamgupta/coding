#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fori(_start, _end) for (int i = _start; i < _end; i++)
#define forj(_start, _end) for (int j = _start; j < _end; j++)
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

string eventual(string &s, int &n)
{
    map<char, int> occurences;
    fori(0, n)
    {
        // cout << typeid(s[i]).name()<<" ";
        occurences[s[i]]++;
    }

    for (auto occurence : occurences)
    {
        if (occurence.second % 2)
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    SPEED;
    int t;
    // t = 1;
    cin >> t;
    fori(0, t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << eventual(s, n) << "\n";
    }
    return 0;
}