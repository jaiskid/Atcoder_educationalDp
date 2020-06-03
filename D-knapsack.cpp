#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll knapsack(ll *wt, ll *val, ll w, ll n) {
	ll t[n + 1][w + 1];
	for (ll i = 0; i < n + 1; i++) {
		for (ll j = 0; j < w + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (ll i = 1; i < n + 1; i++) {
		for (ll j = 1; j < w + 1; j++) {
			if (wt[i - 1] <= j)
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][w];

}

int  main() {
	ll n, w;
	cin >> n >> w;
	ll wt[n], val[n];
	for (ll i = 0; i < n; i++) {
		cin >> wt[i] >> val[i];
	}
	cout << knapsack(wt, val, w, n) << endl;
}
