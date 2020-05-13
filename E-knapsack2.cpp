#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200010
#define Size 100001
ll *weight, *price;
ll dp[101][Size];
ll n, capacity;
ll knapsack2(ll max_profit) {
	ll inf = 1e11;
	for (ll N = 0; N <= n; N++) {
		for (ll profit = 0; profit <= max_profit; profit++) {
			if (N == 0 and profit == 0) {
				dp[N][profit] = 0;
			}
			else if (N == 0) {
				dp[N][profit] = inf;
			}
			else if (price[N - 1] <= profit) {
				dp[N][profit] = min(weight[N - 1] + dp[N - 1][profit - price[N - 1]], dp[N - 1][profit]);
			}
			else {
				dp[N][profit] = dp[N - 1][profit];
			}
		}
	}
	ll ans = 0;
	for (ll profit = 0; profit <= max_profit; profit++) {
		if (dp[n][profit] <= capacity)
			ans = profit;
	}
	return ans;
}

int main() {
	cin >> n >> capacity;
	weight = new ll[n];
	price = new ll[n];
	ll max_profit = 0;
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> price[i];
		max_profit += price[i];
	}

	cout << knapsack2(max_profit) << endl;
}
