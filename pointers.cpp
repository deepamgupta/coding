#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 5;
    int *a;
    //  a is a pointer variable - that can store address of another variable
    a = &x;
    int **b;
    b = &a;
    cout << "x\t:\t" << x << "\n";
    cout << "&x\t:\t" << &x << "\n";
    cout << "*(&x)\t:\t" << *(&x) << "\n";
    cout << "a\t:\t" << a << "\n";
    cout << "*a\t:\t" << x << "\n";
    cout << "&a\t:\t" << &a << "\n";
    cout << "*(&a)\t:\t" << *(&a) << "\n";
    cout << "b\t:\t" << b << "\n";
    cout << "&b\t:\t" << &b << "\n";
    cout << "*(&b)\t:\t" << *(&b) << "\n";
    // cout << "*(&b)\t:\t" << *(&b) << "\n";
}