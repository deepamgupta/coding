// https://leetcode.com/problems/set-matrix-zeroes/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (size_t i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (!m) return;

        int n = matrix[0].size();
        if (!n) return;

        bool isRow0=false, isCol0 = false;

        // is first column to be zeroed
        for (int i = 0; i < m; ++i)
            if (!matrix[i][0]) isCol0 = true;

        // is first row to be zeroed
        for (int j = 0; j < n; ++j)
            if (!matrix[0][j]) isRow0 = true;

        // checking the matrix except first col and first row
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;

        // processing first col
        if (isCol0) for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;

        // processing first row
        if (isRow0) for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }
};

int main()
{
    int n, m;
    cin >> m >> n;

    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> nums[i][j];

    Solution().setZeroes(nums);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << nums[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
