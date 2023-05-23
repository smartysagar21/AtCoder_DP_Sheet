#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i] -> min cost to move to ith stone
//Transition:  dp[i] -> min(dp[k] + abs(v[i] - v[k]), where k = i-1, i-2


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	ll n;
	cin>>n;

	vector<ll>v(n);

	for(ll i = 0; i < n; ++i){
		cin>>v[i];
	}

	ll dp[n];
	memset(dp, 0, sizeof(dp));

	dp[0] = 0;
	dp[1] = abs(v[0] - v[1]);

	for(ll i = 2; i < n; i++){
		dp[i] = dp[i - 1] + abs(v[i] - v[i-1]);
		dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
	}

	cout<<dp[n - 1]<<endl;


	return 0;
}

