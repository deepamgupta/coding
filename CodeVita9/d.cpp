#include <bits/stdc++.h>
using namespace std;

#define ull long long unsigned int
const unsigned long long int M = 1000000007;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

ull getMaxArea(vector<ull> hist, ull n)
{
    stack<ull> s;

    ull max_area = 0;
    ull tp;
    ull area_with_top;

    ull i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else
        {
            tp = s.top();
            s.pop();

            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

ull largestGoldIngot(ull n, ull w, ull h, vector<ull> lengths)
{
    ull maxiArea = getMaxArea(lengths, n);
    ull wh = w * h;
    ull maxiCuboidMod = ((maxiArea % M) * (wh % M)) % M;
    ull netVolumeMod = 0;
    for (ull length : lengths)
        netVolumeMod += ((length % M) * (wh % M)) % M;
    return (netVolumeMod - maxiCuboidMod) % M;
}

int main()
{
    FAST;

    ull n;
    cin >> n;

    ull w, h;
    cin >> w >> h;

    vector<ull> lengths(n);

    for (ull i = 0; i < n; ++i)
        cin >> lengths[i];

    cout << largestGoldIngot(n, w, h, lengths);
    return 0;
}