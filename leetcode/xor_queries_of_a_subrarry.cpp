// https://leetcode.com/problems/xor-queries-of-a-subarray/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size(), q = queries.size();
        vector<int> xors(n);
        vector<int> ans(q);

        xors[0] = arr[0];

        for (int i = 1; i < n; ++i)
        {
            xors[i] = xors[i - 1] ^ arr[i];
        }

        for (int i = 0; i < q; ++i)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            if (left == 0)
            {
                ans[i] = xors[right];
            }
            else
            {
                ans[i] = xors[right] ^ xors[left - 1];
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = Solution().xorQueries(arr, queries);
    for (int i = 0; i < q; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
