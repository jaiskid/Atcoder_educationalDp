#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
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
#define inf (1LL<<60)
ll dp[3001][3001];
ll sum[3001][3001];
ll solve(vector<int>&v, int i, int j) {
	if (i == j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	ll minCost=inf;
	for (int k = i; k < j; k++) {
		minCost = min(minCost, sum[i][j] + solve(v, i, k) + solve(v, k + 1, j));
	}
	return dp[i][j] = minCost;
}
void preprocess(vector<int>&v, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j - 1]);
		} 
	}
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>v;
	memset(dp, -1, sizeof dp);
	v.resize(n + 1);
	
	F1(v, n);
	preprocess(v, n);
	// P1(v, n);
	cout << solve(v, 1, n);
}