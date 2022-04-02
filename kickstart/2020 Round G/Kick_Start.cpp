#include <bits/stdc++.h>
using namespace std;
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

vector<int> getSubstringPositions(string str, string sub)
{
    vector<int> positions;

    int pos = str.find(sub, 0);
    while (pos != string::npos)
    {
        positions.push_back(pos);
        pos = str.find(sub, pos + 1);
    }
    return positions;
}

int getMaximumCoins(string &s)
{
    vector<int> kicks(getSubstringPositions(s, "KICK"));
    vector<int> starts(getSubstringPositions(s, "START"));

    int ans = 0;

    for (int i = 0; i < kicks.size(); ++i)
    {
        for (int j = 0; j < starts.size(); ++j)
        {
            if (kicks[i] < starts[j])
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    SPEED;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << getMaximumCoins(s) << "\n";
    }
}