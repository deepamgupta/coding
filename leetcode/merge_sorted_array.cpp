// https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>

#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m + n);
    vector<int> nums2(n);

    for (int i = 0; i < m; ++i)
        cin >> nums1[i];

    for (int i = 0; i < n; ++i)
        cin >> nums2[i];

    Solution().merge(nums1, m, nums2, n);
    for (int e : nums1)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
