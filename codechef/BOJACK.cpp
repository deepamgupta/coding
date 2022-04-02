#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define foi(_start, _end) for (int i = _start; i < _end; i++)
#define foj(_start, _end) for (int j = _start; j < _end; j++)
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

pair<int, string> bojack(int d)
{
    // string s = "b";
    // int len = d + 1;
    // foi(0, len - 1)
    //     s += "a";
    // return pair<int, string>(len, s);

    string s = "";
    int len = 2 * d;
    foi(0, d)
        s += "a";
    foi(0, d)
        s += "b";

    return pair<int, string>(len, s);
}
int main()
{
    SPEED;
    int t;
    // t = 1;
    cin >> t;
    foi(0, t)
    {
        int d;
        cin >> d;
        pair<int, string> ans = bojack(d);
        cout << ans.first << "\n"
             << ans.second << "\n";
    }
    // cout << string::max_size();
    return 0;
}