// Problem Link: https://www.hackerrank.com/contests/vit-bhopal/challenges/dfs-traversal-1-1



#include <bits/stdc++.h>
using namespace std;

void dfSolve(vector<vector<bool>>& arr, vector<bool>& visited, int v,int key){
    deque<int> stk;
    stk.push_back(key);
    visited[key] = true;
    while(stk.size()){
        // cout << stk.back(); // Print tos
        int cur = stk.back();
        stk.pop_back();
        // for(int i=0; i<v; i++){
        for(int i=v-1; i>=0; i--){
            if(arr[cur][i] && !visited[i]){
                stk.push_back(i);
                visited[i] = true;
            }
        }
        cout << cur << " ";
    }
    int unv = -1;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            unv = i;
            break;
        }
    }
    if(unv != -1){
        dfSolve(arr, visited, v, unv);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v,e;
    cin >> v >> e;
    if(v < 1){
        return 0;
    }
    vector<vector<bool>> arr(v, vector<bool>(v, 0));  // Adjacency Matrix
    vector<bool> visited(v, 0);
    
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    dfSolve(arr, visited, v, 0);
    return 0;
}
