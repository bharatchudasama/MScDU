#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll KnapSack(vector<ll>& w, vector<ll>& v, ll W, ll ind, ll n, vector<vector<ll>>& dp)
{
    if(ind == n || W == 0){
        return 0;
    }
    if(dp[ind][W] == -1){
        ll a = KnapSack(w, v, W, ind+1, n, dp);
        ll b = LLONG_MIN;
        if(W - w[ind] >= 0){
            b = v[ind] + KnapSack(w, v, W-w[ind], ind+1, n, dp);
        }
        dp[ind][W] = max(a, b);
    }
    return dp[ind][W];
    
}

void solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> v(n);
    vector<vector<ll>> dp(n, vector<ll>(W+1, -1));
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    cout << KnapSack(w, v, W, 0, n, dp);
}

int main() {
	// your code goes here
	ll t=1;
// 	cin>>t;
	while(t--){
	    solve();
	    if(t) cout << endl;
	}
	
	return 0;
}
