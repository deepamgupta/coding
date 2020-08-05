#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int maxSum(vector<vector<int>> &v)
{
    int max_sum = 0;
    int rows = v.size();
    int cols = v[0].size();

    for (int row = 0; row < rows; ++row)
    {
        int newSum = 0;
        for (int i = row, j = 0; j < cols && i >= 0; --i, ++j)
        {
            newSum += v[i][j];
        }
        max_sum = max(newSum, max_sum);
    }
    for (int col = 1; col < cols; ++col)
    {
        int newSum = 0;
        for (int i = rows - 1, j = col; j < cols && i >= 0; --i, ++j)
        {
            newSum += v[i][j];
        }
        max_sum = max(newSum, max_sum);
    }

    return max_sum;
}

int main()
{
    SPEED;
    int n, m;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    cout << maxSum(v) << "\n";

    return 0;
}
