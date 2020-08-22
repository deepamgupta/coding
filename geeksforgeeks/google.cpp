#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295

#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

vector<int> maxpr(string sub)
{
    vector<int> res(2);
    stack<char> s;
    s.push(sub[0]);
    for (int i = 1; i < sub.size(); ++i)
    {
        if (s.top() == 'p' && sub[i] == 'r')
        {
            s.pop();
            ++res[0];
        }
        else
        {
            s.push(sub[i]);
        }
    }
    while (!s.empty())
    {
        char temp = s.top();
        s.pop();
        if (s.empty())
            break;

        if (temp == 'p' && s.top() == 'r')
        {
            s.pop();
            ++res[1];
        }
    }
    return res;
}

vector<int> maxrp(string sub)
{
    vector<int> res(2);
    stack<char> s;
    s.push(sub[0]);
    for (int i = 1; i < sub.size(); ++i)
    {
        if (s.top() == 'r' && sub[i] == 'p')
        {
            s.pop();
            ++res[1];
        }
        else
        {
            s.push(sub[i]);
        }
    }
    while (!s.empty())
    {
        char temp = s.top();
        s.pop();
        if (s.empty())
            break;

        if (temp == 'r' && s.top() == 'p')
        {
            s.pop();
            ++res[0];
        }
    }
    return res;
}

int maxProfit(string &str, int &prcost, int &rpcost)
{
    int i = 0;
    vector<int> pr_rp(2);
    while (i < str.size())
    {
        if (str[i] == 'r' || str[i] == 'p')
        {
            int start = i;
            int count = 0;
            while (str[i] == 'r' || str[i] == 'p')
                ++count, ++i;
            vector<int> cur_pr_rp = prcost > rpcost ? maxpr(str.substr(start, count)) : maxrp(str.substr(start, count));
            pr_rp[0] += cur_pr_rp[0];
            pr_rp[1] += cur_pr_rp[1];
        }
        else
        {
            ++i;
        }
    }
    return pr_rp[0] * prcost + pr_rp[1] * rpcost;
}


int main()
{
    SPEED;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int prcost, rpcost;
        cin >> prcost >> rpcost;
        cout << maxProfit(str, prcost, rpcost) << "\n";
    }

    return 0;
}
