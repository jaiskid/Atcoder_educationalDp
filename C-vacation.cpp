#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
struct activity
{
	int A, B, C;
};
int solve(vector<activity>ar, int n) {
	int dp[n + 1][3];
	dp[1][0] = ar[1].A;
	dp[1][1] = ar[1].B;
	dp[1][2] = ar[1].C;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = ar[i].A + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = ar[i].B + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = ar[i].C + max(dp[i - 1][0], dp[i - 1][1]);
	}
	return max({dp[n][0], dp[n][1], dp[n][2]});
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<activity>ar;
	ar.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].A;
		cin >> ar[i].B;
		cin >> ar[i].C;
	}
	cout << solve(ar, n);
}