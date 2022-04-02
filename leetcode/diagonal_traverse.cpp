// https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1167/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        vector<int> digonal_order;
        int m = matrix.size();
        if (m)
        {
            int n = matrix[0].size();
            int large = max(m, n);

            int k = 0;
            for (k = 0; k < large; k++)
            {
                if (k % 2)
                    for (int i = 0, j = k; i <= k && j >= 0; ++i, --j)
                    {
                        if (i < m && j < n)
                            digonal_order.push_back(matrix[i][j]);
                    }
                else
                    for (int j = 0, i = k; j <= k && i >= 0; ++j, --i)
                    {
                        if (i < m && j < n)
                            digonal_order.push_back(matrix[i][j]);
                    }
            }

            for (int down = 1; k < 2 * large - 1; k++, down++)
            {
                if (k % 2)
                    for (int j = large - 1, i = down; j >= down && i <= large - 1; --j, ++i)
                    {
                        if (i < m && j < n)
                            digonal_order.push_back(matrix[i][j]);
                    }
                else
                    for (int i = large - 1, j = down; i >= down && j <= large - 1; --i, ++j)
                    {
                        if (i < m && j < n)
                            digonal_order.push_back(matrix[i][j]);
                    }
            }
        }
        return digonal_order;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int>
        digonal_order = Solution().findDiagonalOrder(matrix);
    for (int e : digonal_order)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}