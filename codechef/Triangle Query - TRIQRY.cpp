// https://www.codechef.com/LTIME83B/problems/TRIQRY
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define foi(_start, _end) for (long long i = _start; i < _end; i++)
#define foj(_start, _end) for (long long j = _start; j < _end; j++)
#define newl "\n";
#define tab "\t";
#define space " ";
#define SPEED                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

ll inside_triangle(pair<int, int> triangle, vector<pair<int, int>> &points)
{

    ll count = 0;
    foj(0, points.size())
    {
        ll x0 = points[j].first;
        ll y0 = points[j].second;
        if (y0 <= x0 - triangle.first && y0 <= -x0 + triangle.second)
            count++;
    }
    return count;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> points(n);
    foi(0, n)
    {
        cin >> points[i].first;
        cin >> points[i].second;
    }

    vector<pair<int, int>> triangles(q);
    foi(0, q)
    {
        cin >> triangles[i].first;
        cin >> triangles[i].second;
    }

    foi(0, q)
    {
        cout << inside_triangle(triangles[i], points) << space;
    }
    cout << newl;

    return;
}

int main()
{
    SPEED;
    int t;
    // t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}