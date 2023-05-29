#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long
 
 
//State:       dp[i][j] -> max len. of substr considering i len. s and j len. t
//Transition:  dp[i][j] -> max({s[i - 1] == t[j - 1] + dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) 
 
 
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
 
	
	string s, t;
	cin>>s>>t;
 
	ll n = s.size(), m = t.size();
 
 
 
 
	ll dp[n+1][m+1];
 
	//INITIALIZATION
	memset(dp, 0, sizeof(dp));
 
	//BASE CASE
	for(ll i = 0; i <= n; ++i){
		for(ll j = 0; j <= m; ++j){
			if(j == 0 || i == 0)dp[i][j] = 0;
		}
	}
 
 
	//TRANSITION
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= m; ++j){
			if(s[i - 1] == t[j - 1])dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
 
 
	//cout<<dp[n][m]<<endl;
 
	ll i = n, j = m;
	string ans = "";
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i - 1][j])i--;
		else if(dp[i][j] == dp[i][j - 1])j--;
		else{
			ans = s[i-1] + ans;
			i--;
			j--;
		}
	}
 
	cout<<ans<<endl;
 
 
	return 0;
}
