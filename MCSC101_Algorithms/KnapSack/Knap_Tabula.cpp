#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> v(n);
    for(ll i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
    for(ll ww=0; ww<=W; ww++){
        for(ll i=0; i<n; i++){
            if(w[i] > ww){
                dp[i+1][ww] = dp[i][ww];
            }
            else{
                dp[i+1][ww] = max(dp[i][ww], v[i] + dp[i][ww - w[i]]);
            }
        }
    }

    cout << dp[n][W];
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
