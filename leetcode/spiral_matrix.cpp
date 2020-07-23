// https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        SPEED;
        vector<int> spiral_order;

        int m = matrix.size();
        if (m)
        {
            int n = matrix[0].size();
            int c = n, r = m - 1;
            int i = 0, j = 0;
            int direction = 0;
            while (spiral_order.size() < m * n)
            {
                switch (direction)
                {
                case 0:
                    for (int step = 0; step < c; ++step, ++j)
                        spiral_order.push_back(matrix[i][j]);
                    --j,
                        ++i,
                        --c,
                        direction = 1;
                    break;
                case 1:
                    for (int step = 0; step < r; ++step, ++i)
                        spiral_order.push_back(matrix[i][j]);
                    --i,
                        --j,
                        --r,
                        direction = 2;
                    break;

                case 2:
                    for (int step = 0; step < c; ++step, --j)
                        spiral_order.push_back(matrix[i][j]);
                    ++j,
                        --i,
                        --c,
                        direction = 3;
                    break;

                case 3:
                    for (int step = 0; step < r; ++step, --i)
                        spiral_order.push_back(matrix[i][j]);
                    ++i,
                        ++j,
                        --r,
                        direction = 0;
                    break;
                }
            }
        }
        return spiral_order;
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
        spiral_order = Solution().spiralOrder(matrix);
    for (int e : spiral_order)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
