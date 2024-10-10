#include <bits/stdc++.h>
using namespace std;

int incSubseq(vector<int>& arr, int cur, int prev) {

    if(cur == arr.size() ) return 0;
    int notinc = incSubseq(arr, cur+1, prev);
    int inc = 0;
    if( (prev == -1) || (arr[cur] > arr[prev]) ) {
        inc = 1 + incSubseq(arr, cur+1, cur);
    }
    
    return max(inc, notinc);
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18, 1, 19};
    // prev[i] stores best 
    vector<int> prev(arr.size(), -1);
    for(int i=arr.size()-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                prev[i] = j;
                break;
            }
        }
    }
    cout << incSubseq(arr, 0, -1);
    return 0;
}
