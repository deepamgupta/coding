#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include<string>
using namespace std;

bool f(int x, int y)
{
  return x > y;
}
void vectorDemo()
{
  vector<int> A = {11, 3, 2, 14, 15};
  cout << A[1] << endl;

  sort(A.begin(), A.end());
  bool present = binary_search(A.begin(), A.end(), 3);

  present = binary_search(A.begin(), A.end(), 4);
  A.push_back(100);

  present = binary_search(A.begin(), A.end(), 100);

  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  A.push_back(100);

  // emplace_back() is more efficient then push_back()

  //2,3,11,14,100,100,100,100,123
  A.push_back(123);

  auto it = lower_bound(A.begin(), A.end(), 100);  //>=
  auto it2 = upper_bound(A.begin(), A.end(), 100); //>

  cout << *it << "  " << *it2 << endl;

  cout << it2 - it << endl; //5

  sort(A.begin(), A.end(), f);

  for (int &x : A)
  {
    x++;
  }
  for (int x : A)
  {
    cout << x << " ";
  }
}

void multisetDemo(){
  multiset<int> ms;
  ms.insert(10);
  ms.insert(10);
  ms.insert(10);
  ms.insert(9);
  ms.insert(5);
  ms.insert(5);
  ms.insert(2);
  ms.insert(1);
  ms.insert(-2);
  ms.insert(-2);

  for(int x : ms){
    cout<<x<<" ";
  }
  // -2 -2 1 2 5 5 9 10 10 10

    cout << endl;
  auto it = ms.find(-1);
  if (it == ms.end())
  {
    cout<<"Not Presented";
    cout<< *it <<endl;
  }
  else{
    cout<<"Present";
    cout<< *it <<endl;
  }

  auto it2 = ms.upper_bound(10);
 
  auto it3 = ms.lower_bound(10);
  cout<< *it2<< " "<<*it3<<endl;

  auto it4 = ms.upper_bound(2);
  if (it4==ms.end()) {
    cout<<"Oops!! Not found!!";
  }

  ms.erase(ms.find(5));  // -2 -2 1 2 5 9 10 10 10
  for(int x:ms){
    cout<<x<<" ";
  } 

  ms.erase(10);  // -2 -2 1 2 5 9
  for(int x:ms){
    cout<<x<<" ";
  }  
}

void setDemo()
{
  set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(-1);
  s.insert(-10);

  for (int x : s)
  {
    cout << x << " ";
  }

  cout << endl;
  //-10 -1 1 2
  auto it = s.find(-1);
  if (it == s.end())
  {
    cout<<"Not Presented";
  }
  else{
    cout<<"Present";
    cout<< *it <<endl;
  }

  auto it2 = s.upper_bound(-1);
  auto it3 = s.lower_bound(0);
  cout<< *it<< " "<<*it3<<endl;

  auto it4 = s.upper_bound(2);
  if (it4==s.end()) {
    cout<<"Oops!! Not found!!";
  }

  s.erase(-1);
  for(int x:s){
    cout<<endl<<x<<" ";
  }
  
}
void mapDemo(){
  map<int,int> A;
  A[1] = 17;
  A[2] = 31;
  A[3] = 15;
  A[1001] = 23;

  cout<<A[66]<<endl;
  cout<<A[1];

  for(auto it = A.begin(); it != A.end(); it++){
    cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
  }

  map<char, int> cnt;
  string x= "Deepam Gupta";
  for(char c : x){
    cnt[c]++;
  }
  cout<<endl<<cnt['e']<<" "<<cnt['r']<<" "<<cnt['d'];
  // bool check = A.find(1);
  cout<<endl<<A.find(44)->second;
  A[44];
  cout<<endl;
  cout<<"--->"<<A.erase(66);

  for(auto it = A.cbegin(); it != A.cend(); it++){
    cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
  }
}

void powerOfSet(){
  set< pair<int, int> > S;
  S.insert({1,3});
  S.insert({10,20});
  S.insert({30,400});
  S.insert({401, 450});

  int point = 1;
  auto it = S.upper_bound({point,__INT_MAX__});
  it--;

  if(it==S.begin()){
    cout<<"not in any of the pairs...";
    return;
  }
  pair<int,int> current = *it;
  
  if(point >=current.first && point <= current.second){
    cout<<"Element found between "<<it->first<<" and "<<it->second<<endl;
  }
  else  {
    cout<<"Element not found!!!";
  }
  
}


 
int main()
{
  // setDemo();
  // mapDemo();
  // powerOfSet();
  // cout<<endl<<__INT_MAX__;



//    // To count the digits in an integer
  cout<<floor(log10(34))+1<<endl;




// // The Iota Algorithm to initialize array with sequence
//    int arr[5] = {0};
//    iota(arr, arr+5, 15);//15 16 17 18 19
//    for(int x : arr){
//       cout<<x<<"\t";
//    }



//    vector <int> v;
//    v.emplace_back(34);
//    cout<<v[0]<<endl;

// multisetDemo();


}
