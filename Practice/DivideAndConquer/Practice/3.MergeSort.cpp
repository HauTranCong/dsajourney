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


void merge(int l, int m, int r, vector<int>& arr) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> lArr(n1), rArr(n2);
    
    for(int i = 0; i < n1; ++i)
        lArr[i] = arr[l + i];
    for(int i = 0; i < n2; ++i)
        rArr[i] = arr[m + 1 + i];
    
    int i = 0, j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if(lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        } else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r, vector<int>& arr) {
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid, arr);
    mergeSort(mid+1, r, arr);
    merge(l, mid, r, arr);
}

int main()
{
    input();
    mergeSort(0, length - 1, arr);
    
    for(int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

// 2
// 100 10
// 9
// 0 2 -4 3 22 5 9 10 8