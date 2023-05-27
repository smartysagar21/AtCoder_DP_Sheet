#include <bits/stdc++.h>
using namespace std;


#define ll long long


//State:       dp[i][j] -> max happines at ith day where j = a, b, c... if j = 0, we choose a as last task 
//Transition:  dp[i][j] -> max(dp[i-1][k] + max(j[i])), where k = a, b, c and k != j  


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	ll n;
	cin>>n;

	int a[n],b[n],c[n];
	for(ll i = 0; i < n; ++i){
		cin>>a[i]>>b[i]>>c[i];
	}

	int dp[n][3];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			if(i == 0){
				if(j == 0)dp[i][j] = a[i];
				else if(j == 1)dp[i][j] = b[i];
				else dp[i][j] = c[i];
			}
			else{
				for(int k = 0; k < 3; ++k){
					if(j == k)continue;
					if(j == 0)dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i]);
					else if(j == 1)dp[i][j] = max(dp[i][j], dp[i-1][k] + b[i]);
					else dp[i][j] = max(dp[i][j], dp[i-1][k] + c[i]);

				}
			}
		}
	}

	
	cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;


	return 0;
}

