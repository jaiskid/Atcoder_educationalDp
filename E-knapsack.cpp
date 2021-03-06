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
#define inf 1e9+1;
struct item
{
	int wt, val;
};

int solve(vector<item>&ar, int n, int w) {
	ll maxval = n * 1000;
	ll dp[n + 1][maxval + 1];
	for (int val = 0; val <= maxval; val++)
		dp[1][val] = inf;
	dp[1][0] = 0;
	dp[1][ar[1].val] = ar[1].wt;
	for (int i = 2; i <= n; i++) {
		for (int v = 0; v <= maxval; v++) {
			dp[i][v] = dp[i - 1][v];
			if (ar[i].val  > v) {
				continue;
			}
			dp[i][v] = min(dp[i][v], ar[i].wt + dp[i - 1][v - ar[i].val]);
		}

	}
	int ans = 0;
	for (int x = 0; x <= maxval; x++) {
		if (dp[n][x] <= w) {
			ans = x;
		}
	}
	return ans;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int W;
	cin >> W;
	vector<item>ar;
	ar.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].wt >> ar[i].val;
	}
	cout << solve(ar, n, W) << endl;
}