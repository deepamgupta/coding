// https://www.codechef.com/OCT20B/problems/CVDRUN

#include <bits/stdc++.h>
using namespace std;

string infected_city(int total_city, int jump, int start, int my_city)
{
    if (total_city == 1 || start == my_city)
    {
        return "YES";
    }

    if (jump == 0)
    {
        return "NO";
    }

    int i = (start + jump) % total_city;
    while (!(i == start || i == my_city))
    {
        i = (i + jump) % total_city;
    }
    if (i == my_city)
        return "YES";
    else
        return "NO";
}

int main()
{
    int start, my_city, jump, total_city, t;
    cin >> t;
    while (t--)
    {
        cin >> total_city >> jump >> start >> my_city;
        cout << infected_city(total_city, jump, start, my_city);
        cout << "\n";
    }
    return 0;
}