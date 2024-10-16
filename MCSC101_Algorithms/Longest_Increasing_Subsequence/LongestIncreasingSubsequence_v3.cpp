#include <bits/stdc++.h>
using namespace std;

// ind is current index, last is last included element
// from right side
int Opt(vector<int>& arr, int ind) {
    if (ind == 0) return 1;

    // Case 1: Not including the current element
    // int notinc = Opt(arr, ind - 1);

    // Case 2: Including the current element
    int inc = 1;
    for(int i=0; i<ind; i++){
        if(arr[ind] > arr[i]) inc = max(inc, 1+Opt(arr, i));
    }

    // Return the maximum of including, not including
    return max(inc, notinc);
}

int main() {
    // vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18, 1, 19};
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    // last = arr.size() means no element added till now
    cout << Opt(arr, arr.size() - 1) << endl;
    return 0;
}
