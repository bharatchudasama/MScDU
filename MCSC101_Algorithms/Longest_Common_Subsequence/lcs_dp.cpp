// DP approach, O(m * n)
// When size of two strings are m and n
// When using in case of longest palindrome subsequence,
// s2 = reverse(s1), m = n, so complexity O(n^2)

#include <bits/stdc++.h>
using namespace std;

int lcsub(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp){
    if( (ind1==-1) || (ind2==-1) ){
        return 0;
    }
    else if( dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }
    else if(s1[ind1] == s2[ind2]){
        dp[ind1][ind2] = 1 + lcsub(s1, s2, ind1-1, ind2-1, dp);
    }
    else{
        dp[ind1][ind2] = max( lcsub(s1, s2, ind1-1, ind2, dp), lcsub(s1, s2, ind1, ind2-1, dp) );
    }
    return dp[ind1][ind2];
}
int main()
{
    // cout<<"Hello World";
    string s1 = "adebcc";
    string s2 = "dcadbzzc";
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    cout << lcsub(s1, s2, s1.size()-1, s2.size()-1, dp);

    // for (int i = 0; i < s1.size(); i++)
    // {
    //     for (int j = 0; j < s2.size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
        
    // }
    
    return 0;
}
