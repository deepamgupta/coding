#include <iostream>
#include <vector>
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void my_func(int n, int s[])
{
    if (n == 0)
    {
        printf("%0.6f", float(n));
        printf("\n");
        return;
    }

    if (n == 1)
    {
        printf("%0.6f", float(n));
        printf("\n");
        return;
    }
    else
    {
        double per = 1, group = 0;

        for (int i = 1; i <= n; ++i)
        {
            per *= i;
            for (int j = 1, mult = 1; j <= i; mult *= ++j)
            {
                group += (per / mult);
            }
        }

        if (n % 2 == 0)
            group--;
        group -= n;
        printf("%0.6f", group / per);
        printf("\n");
    }
}

// void findPermutations(int a[], int n)
// {
//     int count;

//     do {
//         count++;
//     } while (next_permutation(a, a + n));

//     cout<<count<<"\n";
// }

int main()
{
    map<int, int> m;
    for (int i = 0; i < b.size; ++i)
    {
        m[b][i]++;
    }
    int count = 0;
    for (auto i : m)
    {
        if (i.second >= l)
        {
            ++count;
        }
    }

    return count;
}