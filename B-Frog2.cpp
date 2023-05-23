#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i] -> min cost to move to ith stone
//Transition:  dp[i] -> min(dp[k] + abs(v[i] - v[k]), where k = i-1, i-2, ...k 


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	ll n,k;
	cin>>n>>k;

	vector<ll>v(n);

	for(ll i = 0; i < n; ++i){
		cin>>v[i];
	}

	ll dp[n];
	memset(dp, 0, sizeof(dp));

	for(ll i = 1; i < n; ++i){

		dp[i] = dp[i-1] + abs(v[i] - v[i-1]);
		for(ll j = 2; j <= k; ++j){
			if(i - j < 0)continue;
			dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i-j]));
		}
	}

	cout<<dp[n - 1]<<endl;


	return 0;
}

