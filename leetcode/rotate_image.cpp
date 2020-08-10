// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (int i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (size_t level = 0; level < n/2; ++level)
        {
            for (size_t round = level; round < n-level-1; ++round)
            {
                swap(matrix[level][round], matrix[round][n-level-1]);
                swap(matrix[level][round], matrix[n-level-1][n-1-round]);
                swap(matrix[level][round], matrix[n-1-round][level]);
            }

        }

    }
};
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cin>>matrix[i][j];
        }

    }

    Solution().rotate(matrix);

    cout<<"\n";
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
