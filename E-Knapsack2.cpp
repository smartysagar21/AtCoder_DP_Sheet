#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i][j] -> min wt to make val. of j considering i unit
//Transition:  dp[i][j] -> min(wt[i - 1] + dp[i - 1][j - val[i - 1]], dp[i - 1][j])
//                         considering wt[i - 1] and with val. j or not considering it 


// for(ll i = 0; i <= n; ++i){
// 	for(ll j = 0; j <= sum; ++j){
// 		if(dp[i][j] != INF)cout<<dp[i][j]<<" ";
// 		else cout<<"INF ";
// 	}
// 	cout<<endl;
// }


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	ll n, w, sum = 0;
	cin>>n>>w;

	vector<ll> wt(n), val(n);
	for(ll i = 0; i < n; ++i){
		cin>>wt[i]>>val[i];
		sum += val[i];
	}



	ll dp[n+1][sum+1], INF = 1e18;

	//INITIALIZATION
	for(ll i = 0; i <= n; ++i){
		for(ll j = 0; j <= sum; ++j){
			dp[i][j] = INF;
		}
	}

	//BASE CASE
	for(ll i = 0; i <= n; ++i){
		for(ll j = 0; j <= sum; ++j){
			if(j == 0)dp[i][j] = 0;
		}
	}


	//TRANSITION
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= sum; ++j){
			if(j >= val[i - 1])dp[i][j] = min(wt[i - 1] + dp[i - 1][j - val[i - 1]], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}


	ll ans;
	for(ll i = sum; i >= 0; i--){
		if(dp[n][i] <= w){
			ans = i;
			break;
		}
	}


	cout<<ans<<endl;


	return 0;
}

