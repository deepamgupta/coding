// https://practice.geeksforgeeks.org/problems/inversion-of-array/0
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define foi(_n1, _n2) for (int i = _n1; i < _n2; ++i)
#define foj(_n1, _n2) for (int j = _n1; j < _n2; ++j)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

ll countInversionsNaive(vector<ull> &v)
{
    ll count = 0;
    foi(0, v.size() - 1)
        foj(i + 1, v.size()) if (v[i] > v[j])++count;

    return count;
}

ull merge(vector<ull> &v, ull left, ull mid, ull right)
{
    ull n = right - left + 1;
    vector<ull> temp(n);
    ull inversions = 0;
    ull i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
            temp[k++] = v[i++];
        else if (v[j] < v[i])
            temp[k++] = v[j++], inversions += mid - i + 1;
        else
            temp[k++] = v[i++];
    }

    while (i <= mid)
        temp[k++] = v[i++];
    while (j <= right)
        temp[k++] = v[j++];

    for (int c = 0; c < n; ++c)
        v[left + c] = temp[c];

    return inversions;
}

ull countInversionWithMergeSort(vector<ull> &v, ull left, ull right)
{
    ull inversions = 0;
    if (left < right)
    {
        ull mid = left + (right - left) / 2;
        inversions += countInversionWithMergeSort(v, left, mid);
        inversions += countInversionWithMergeSort(v, mid + 1, right);
        inversions += merge(v, left, mid, right);
    }
    return inversions;
}

ull countInversionsFast(vector<ull> &v)
{
    return countInversionWithMergeSort(v, 0, v.size() - 1);
}

int main()
{
    // Stress Testing
    // while (true)
    // {
    //     ull n = rand() % 10 + 1;
    //     vector<ull> v(n);
    //     foi(0, n)
    //     {
    //         v[i] = rand() % 10 + 1;
    //     }
    //     for (ull c : v)
    //         cout << c << " ";
    //     cout << "\n";

    //     ull naive = countInversionsNaive(v);
    //     ull fast = countInversionsFast(v);
    //     for (ull c : v)
    //         cout << c << " ";
    //     cout << "\n";
    //     cout << naive << " " << fast << "\n";
    //     if (naive == fast)
    //         cout << "OK\n";
    //     else
    //     {
    //         cout << "Wrong Answer\n";
    //         break;
    //     }
    // }

    SPEED;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ull> v(n);
        foi(0, n) cin >> v[i];
        cout << countInversionsFast(v) << "\n";
    }

    return 0;
}
