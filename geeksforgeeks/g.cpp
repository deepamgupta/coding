// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0
#include <bits/stdc++.h>
using namespace std;
#define ull long long unsigned int //0 to 18,446,744,073,709,551,615
#define ll long long int           //-(2^63) to (2^63)-1
#define ld long double             //12 bytes
#define ul unsigned long int       //0 to 4,294,967,295
#define us unsigned short int      //0 to 65,535
#define si short int               //	-32,768 to 32,767
#define fori(_n1, _n2) for (size_t i = _n1; i < _n2; ++i)
#define forj(_n1, _n2) for (size_t j = _n1; j < _n2; ++j)
#define SPEED ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const unsigned int M = 1000000007;

vector<int> repeatingAndMissing(vector<int> &v)
{
      set<int> repeating;
      set<int> missing;

      int n = v.size();
      fori(0, n)
      {
            int key = abs(v[i]);
            bool not_encountered = v[key - 1] > 0 ? true : false;
            if (not_encountered)
                  v[key - 1] = -v[key - 1];
            else
                  repeating.insert(key);
      }

      fori(0, n) if (v[i] > 0) missing.insert(i + 1);

      return {*(repeating.begin()), *(missing.begin())};
}

int main()
{
      SPEED;
      int t;
      cin >> t;

      while (t--)
      {
            int n;
            cin >> n;
            vector<int> v(n);
            fori(0, n) cin >> v[i];
            vector<int> ans = repeatingAndMissing(v);
            cout << ans[0] << " " << ans[1] << "\n";
      }

      return 0;
}
