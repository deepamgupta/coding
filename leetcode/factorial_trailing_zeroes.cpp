// https://leetcode.com/problems/factorial-trailing-zeroes/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        for (size_t i = 5; n / i >= 1; i*=5)
            fives += n/i;
        return fives;
    }
};

int main()
{
    int n;
    cin>>n;

    cout<< Solution().trailingZeroes(n)<<"\n";
    return 0;
}
