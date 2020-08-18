#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    int open = 0;

    for (int i = 0; i < k; ++i)
    {
        string option;
        cin >> option;
        if (option == "CLICK")
        {
            int t;
            cin >> t;
            if (!v[t - 1])
            {
                v[t - 1] = 1;
                ++open;
            }
            else if (v[t - 1])
            {
                v[t - 1] = 0;
                open--;
            }
        }
        else
        {
            v = vector<int>(n);
            open = 0;
        }
        cout << open << "\n";
    }
}