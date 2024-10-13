// BETTER APPROACH
#include <bits/stdc++.h>
using namespace std;

// ind is current index, last is last included element
// from right side
int Opt(vector<int>& arr, int ind, int last) {
    if (ind == -1) return 0;

    // Case 1: Not including the current element
    int notinc = Opt(arr, ind - 1, last);

    // Case 2: Including the current element
    int inc = 0;
    if (last == arr.size() || arr[ind] < arr[last]) {
        inc = 1 + Opt(arr, ind - 1, ind);
    }

    // Return the maximum of including, not including
    return max(inc, notinc);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18, 1, 19};
    // last = arr.size() means no element added till now
    cout << Opt(arr, arr.size() - 1, arr.size()) << endl;
    return 0;
}




// BAD APPROACH
// #include <bits/stdc++.h>
// using namespace std;

// int incSubseq(vector<int>& arr, int cur, int prev) {

//     if(cur == arr.size() ) return 0;
//     int notinc = incSubseq(arr, cur+1, prev);
//     int inc = 0;
//     if( (prev == -1) || (arr[cur] > arr[prev]) ) {
//         inc = 1 + incSubseq(arr, cur+1, cur);
//     }
    
//     return max(inc, notinc);
// }

// int main()
// {
//     vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18, 1, 19};
//     cout << incSubseq(arr, 0, -1);
//     return 0;
// }
