#include <bits/stdc++.h>
using namespace std;

int stringAlign(vector<vector<int>>& dp, string x, string y){
    int delta = 2;
    // cout << "Enter Delta : ";
    // cin >> delta;

    vector<int> ifvow(26, 0);
    string vows = "aeiou";
    for(auto e : vows){
        ifvow[e-'a'] = 1;
    }
        
    vector<vector<int>> alph(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(i == j) alph[i][j] = 0;
            else if(ifvow[i] == ifvow[j]){
                alph[i][j] = 1;
            }
            else{
                alph[i][j] = 3;
            }
        }
        
    }
    


    // Initial Base Cases
    for(int i=0; i<=x.size(); i++){
        dp[0][i] = i * delta;
    }
    for(int j=0; j<=y.size(); j++){
        dp[j][0] = j * delta;
    }

    for(int i=1; i<=x.size(); i++){
        for (int j = 1; j < y.size(); j++)
        {
            dp[i][j] = min(dp[i-1][j-1] + alph[x[i]-'a'][y[j]-'a'], min(dp[i-1][j] + delta, dp[i][j-1] + delta));
            // if (x[i] == x[j]){
            //     dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] + delta, dp[i][j-1] + delta));
            // }
            // else{
            //     dp[i][j] = min(dp[i-1][j-1] + alph[x[i]][y[j]], min(dp[i-1][j] + delta, dp[i][j-1] + delta));
            // }
        }
        
    }
}

int main() {
    string a, b;
    cout << "Enter Two Strings : ";
    cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    // cout << dp.size() << "  " << dp[0].size() << endl;
    // cout << dp[0][b.size()];
    stringAlign(dp, a, b);
    for(int i=0; i<=a.size(); i++){
        for (int j = 0; j < b.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
        
    }
}
