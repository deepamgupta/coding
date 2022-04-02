// https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1170/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascals_triangle;
        if (numRows)
        {
            for (int row_size = 1; row_size <= numRows; ++row_size)
            {
                pascals_triangle.push_back(vector<int>(row_size, 1));
                int row_index = row_size - 1;

                for (int i = 1; i < row_size - 1; ++i)
                {
                    pascals_triangle[row_index][i] = pascals_triangle[row_index - 1][i - 1] + pascals_triangle[row_index - 1][i];
                }
            }
        }
        return pascals_triangle;
    }
};
int main()
{
    int m;
    cin >> m;

    vector<vector<int>>
        pascals_triangle = Solution().generate(m);
    for (auto row : pascals_triangle)
    {
        for (int e : row)
            cout << e << " ";
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
