#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    // Take Input
    // -----

    auto start = std::chrono::steady_clock::now();
    int ans = yourFunction();  // Call the function you want

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;
    cout << "Judgement of Chronos : ";
    std::cout << std::chrono::duration<double, std::nano>(diff).count() << " nano-second" << std::endl;
}

int main() {
	// your code goes here
	ll t=1;
	// cin>>t;
	while(t--){
	    solve();
	    if(t) cout << endl;
	}
	
	return 0;
}
