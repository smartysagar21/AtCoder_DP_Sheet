#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i] -> max legnth from vertex i
//Transition:  dp[i] = max(1 + dp[child of i]) 


// for(ll i = 0; i <= n; ++i){
// 	for(ll j = 0; j <= sum; ++j){
// 		if(dp[i][j] != INF)cout<<dp[i][j]<<" ";
// 		else cout<<"INF ";
// 	}
// 	cout<<endl;
// }

vector<ll>adj[100005];
vector<ll>dp(100005, -1);

ll dfs(int v){

	if(dp[v] != -1)return dp[v];
	ll temp = 0;

	for(auto i: adj[v]){
		temp = max(1 + dfs(i), temp);
	}

	return dp[v] = temp;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	ll n, m;
	cin>>n>>m;

	for(ll i = 0; i < m; ++i){
		ll x, y;
		cin>>x>>y;	
		adj[x].push_back(y);
	}


	for(int i = 1; i <= n; ++i){
			dfs(i);
	}

	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = max(ans, dp[i]);
	}

	cout<<ans<<endl;
	

	return 0;
}

