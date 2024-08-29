
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v,e;
    cin >> v >> e;
    vector<vector<bool>> arr(v, vector<bool>(v, 0));  // Adjacency Matrix
    vector<bool> visited(v, 0);
    
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    
    deque<int> stk;
    stk.push_back(0);
    visited[0] = true;
    while(stk.size()){
        // cout << stk.back(); // Print tos
        int cur = stk.back();
        stk.pop_back();
        for(int i=0; i<v; i++){
            if(arr[cur][i] && !visited[i]){
                stk.push_back(i);
                visited[i] = true;
            }
        }
        cout << cur << " ";
    }
    return 0;
}
