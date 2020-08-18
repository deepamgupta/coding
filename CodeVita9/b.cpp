#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int left = 0;
    int right = 0;

    while (m != n && (m > 1 || n > 1))
    {
        if (m > n)
            m /= 2, right++;
        else if (m < n)
            n /= 2, left++;
    }
    cout << left + right;
    return 0;
}