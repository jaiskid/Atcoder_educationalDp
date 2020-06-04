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
ll dp[3001][3001][2];
ll solve(vector<int>&v, int i, int j, bool turn) {
	if (i > j)
		return 0;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if (turn == 1)
		return dp[i][j][turn] = max(v[i] + solve(v, i + 1, j, 0), v[j] + solve(v, i, j - 1, 0));
	else
		return dp[i][j][turn] = min(solve(v, i + 1, j, 1), solve(v, i, j - 1, 1));
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>ar;
	ar.resize(n + 1);
	ll sum = 0;
	F1(ar, n);
	for (int i = 1; i <= n; i++) {
		sum += ar[i];
	}
	memset(dp, -1, sizeof dp);
	ll scoreX = solve(ar, 1, n, 1);
	ll scoreY = (sum - scoreX);
	cout << scoreX - scoreY;
	//P1(ar, n);
}