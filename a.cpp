#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    SPEED;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << *max_element(arr.begin(), arr.end()) << "\n";

    return 0;
}
