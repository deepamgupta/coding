// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
#include <bits/stdc++.h>
using namespace std;

int numOfSubArrays(vector<int> &arr, int &m)
{
    int n = arr.size();
    vector<int> xorFromStart(n);
    xorFromStart[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        xorFromStart[i] = xorFromStart[i - 1] ^ arr[i];
    }

    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (xorFromStart[i] == m)
            ++ans;

        int required = m ^ xorFromStart[i];

        if (mp.find(required) != mp.end())
        {
            ans += mp[required];
        }

        ++mp[xorFromStart[i]];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << numOfSubArrays(arr, m);
    return 0;
}
