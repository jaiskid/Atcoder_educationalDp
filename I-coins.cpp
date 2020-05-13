#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 3005;
double dp[N][N];
double p[N];
ll n;
double Func(ll coins, ll heads) {
	if (heads == 0)
		//if head become zero and we have some coins so, probability of atleast 0 head is 1
		return 1;
	if (coins == 0)
		//head are required are greater than 0 and coins are zero thus prob =0
		return 0;
	if (dp[coins][heads] > -1) {
		return dp[coins][heads];
	}
	double op1 = p[coins] * Func(coins - 1, heads - 1);
	double op2 = (1 - p[coins]) * Func(coins - 1, heads);
	dp[coins][heads] = op1 + op2;
	return dp[coins][heads];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	cout << fixed << setprecision(10) << Func(n, (n + 1) / 2) << endl;
}
