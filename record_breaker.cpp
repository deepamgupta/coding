#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forn(n) for (int i = 0; i < n; i++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

bool is_record_breaking(vector<int> &v, int i, int n, int current_max_index)
{
    if (i == 0 && v[i] > v[i + 1])
    {
        return true;
    }
    else if (i == n - 1 && v[i] > v[current_max_index])
    {
        return true;
    }
    else if (v[i] > v[current_max_index] && v[i] > v[i + 1])
    {
        return true;
    }
    return false;
}

int count_record_breaking_days(vector<int> &v, int n)
{
    int record_breaking_days = 0;
    if (n == 1)
    {
        record_breaking_days = 1;
    }
    else
    {
        int current_max_index = 0;
        for (int i = 0; i < n; i++)
        {
            if (is_record_breaking(v, i, n, current_max_index))
            {
                current_max_index = i;
                record_breaking_days++;
            }
        }
    }

    return record_breaking_days;
}

int main()
{
    SPEED;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        cout << "Case #" << i << ": " << count_record_breaking_days(v, n) << "\n";
    }

    return 0;
}