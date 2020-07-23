#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forn(n) for (int i = 0; i < n; i++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int get_bit_score_significant_digit(int num)
{
    vector<int> digit_vector(3);
    digit_vector[0] = num % 10;
    digit_vector[1] = (num / 10) % 10;
    digit_vector[2] = num / 100;

    int min = *min_element(digit_vector.begin(), digit_vector.end());
    int max = *max_element(digit_vector.begin(), digit_vector.end());

    int bit_score = 11 * max + 7 * min;
    return (bit_score / 10) % 10;
}

ll get_digit_pairs(vector<int> &nums, int &n)
{
    vector<int> bit_score_significant_digits(n);
    map<int, pair<int, int>> digits;
    int possible_pairs = 0;
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            digits[get_bit_score_significant_digit(nums[i])].first++;
        }
        for (int i = 1; i < n; i += 2)
        {
            digits[get_bit_score_significant_digit(nums[i])].second++;
        }

        for (auto digit : digits)
        {
            if (digit.second.first == 2 && digit.second.second == 2)
            {
                possible_pairs += 2;
            }
            else
            {
                int most_occurence = digit.second.first > digit.second.second ? digit.second.first : digit.second.second;
                // cout << digit.first << " : " << most_occurence << " ";
                if (most_occurence == 2)
                    possible_pairs++;
                else if (most_occurence > 2)
                    possible_pairs += 2;
            }
        }
    }
    return possible_pairs;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << get_digit_pairs(nums, n);
}

// int a;
// cin >> a;
// mp[] = a;