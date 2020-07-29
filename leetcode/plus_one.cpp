// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> digits_plus_one = vector<int>(digits);
        ll size = digits.size();

        ll digit_index = size - 1;
        while (digit_index != -1 && digits_plus_one[digit_index] + 1 == 10)
        {
            digits_plus_one[digit_index] = 0;
            digit_index--;
        }
        if (digit_index != -1)
        {
            digits_plus_one[digit_index] += 1;
        }
        else
        {
            digits_plus_one.insert(digits_plus_one.begin(), 1);
        }
        return digits_plus_one;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    vector<int> plusOneVector = Solution().plusOne(digits);
    for (int e : plusOneVector)
    {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}