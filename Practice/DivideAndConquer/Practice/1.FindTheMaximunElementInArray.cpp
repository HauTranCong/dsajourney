/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int length;
vector<int> arr;

void input() {
    cin >> length;
    for(int i = 0; i < length; ++i) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

int findMaximum(int i, int j, vector<int> arr) {
    if(i == j)
        return arr[i];
    int mid = (i + j) / 2;
    return max(findMaximum(i, mid, arr), 
                findMaximum(mid+1, j, arr));
}

int findMaximumElement(vector<int> arr) {
    if(arr.size() == 1)
        return arr.front();
    return findMaximum(0, length - 1, arr);
}

int main()
{
    input();
    
    std::cout << findMaximumElement(arr);

    return 0;
}

// 2
// 100 10
// 9
// 0 2 -4 3 22 5 9 10 8