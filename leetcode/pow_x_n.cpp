// https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1.0;
        double ans=x;
        size_t i = 1;
        int mod_n = abs(n);
        while (i < mod_n)
        {
            double temp_ans = x;
            size_t remain = mod_n - i;
            size_t j = 1;
            for (; 2*j <= remain; j*=2)
            {
                temp_ans *= temp_ans;
            }
            ans *= temp_ans;
            i += j;
        }
        return n > 0 ? ans : 1/ans;
    }
};

int main()
{
    double x;
    int n;
    cin>>x>>n;

    cout<< Solution().myPow(x, n)<<"\n";
    return 0;
}
