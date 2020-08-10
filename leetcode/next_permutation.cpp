// https://leetcode.com/problems/next-permutation/
#include <bits/stdc++.h>
#define ll long long
#define foi(_start, _end) for (size_t i = _start; i < _end; ++i)
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while (i > 0) {
            if (nums[i-1] < nums[i])
            {
                sort(nums.begin() + i, nums.end());
                auto upper = upper_bound(nums.begin() + i, nums.end(), nums[i-1]);
                swap(nums[i-1], *upper);
                break;
            }
            --i;
        }

        if (!i) sort(nums.begin(), nums.end());
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    Solution().nextPermutation(nums);


    for (int i = 0; i < n; ++i)
        cout << nums[i] << " ";
    cout << "\n";


    return 0;
}
