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

int findMinimum(int i, int j, vector<int> arr) {
    if(i == j)
        return arr[i];
    if(j - i == 1)
        return min(arr[i], arr[i + 1]);
    if(j - i == 2)
        return min(arr[i], min(arr[i+1], arr[i+2]));
        
    int third = (j - i) / 3;
    int midleft = i + third;
    int midRight = i + 2*third;
    
    int minLeft = findMinimum(i, midleft, arr);
    int minMid = findMinimum(midleft+1, midRight, arr);
    int minRight = findMinimum(midRight+1, j, arr);
    
    return min(minLeft, min(minMid, minRight));
}

int findMinimumElement(vector<int> arr) {
    if(arr.size() == 1)
        return arr.front();
    return findMinimum(0, length - 1, arr);
}

int main()
{
    input();
    
    std::cout << findMinimumElement(arr);

    return 0;
}

// 2
// 100 10
// 9
// 0 2 -4 3 22 5 9 10 8


