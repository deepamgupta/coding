#include <bits/stdc++.h>
using namespace std;

int totalDistance(int &n, int &k, int &j, vector<int> &costs)
{
    int total = costs[j - 1];
    costs.erase(costs.begin() + j - 1);
    sort(costs.begin(), costs.end());

    for (int i = 0; i < k - 1; ++i)
    {
        total += costs[i];
    }
    return total;
}

int main()
{
    int n, k, j;
    cin >> n >> k >> j;
    vector<int> costs(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> costs[i];
    }

    cout << totalDistance(n, k, j, costs);
    return 0;
}
