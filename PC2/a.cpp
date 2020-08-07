#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define repi(n1, n2) for (size_t i = n1; i < n2; i++)
#define repj(n1, n2) for (size_t j = n1; j < n2; j++)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

int maxDigitSum(string num)
{
    ull odd = 0, even = 0;
    for (size_t i = 0; i < num.size(); ++i)
    {
        int digit = num[i] - '0';
        bool is_even = digit%2 ?false:true;
        if (is_even) even += digit;
        else odd+= digit;
    }
    return max(odd+2*even, even+2*odd);
}

int main()
{
    SPEED;
    int t;
    cin >> t;

    while (t--)
    {
        string num;
        cin>>num;
        cout<<maxDigitSum(num)<<"\n";
    }

    return 0;
}
