#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i][j] -> max value considering i elements and j wt. of knapsack 
//Transition:  dp[i][j] -> max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j])
//                         considering val[i - 1] and with wt. j or not considering it 


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	ll n, w;
	cin>>n>>w;

	vector<ll> wt(n), val(n);
	for(ll i = 0; i < n; ++i){
		cin>>wt[i]>>val[i];
	}

	ll dp[n+1][w+1];
	memset(dp, 0, sizeof(dp));

	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= w; ++j){
			if(j >= wt[i - 1])dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}


	cout<<dp[n][w]<<endl;


	return 0;
}

