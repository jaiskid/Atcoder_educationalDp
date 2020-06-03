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
bool DONE(vector<int>&v , int n) {
	for (int i = 1; i <= n; i++) {
		if (v[i] != 0)
			return 0;
	}
	return 1;
}
int experiment(vector<int>&v, int n) {
	if (DONE(v, n)) {
		return 0;
	}
	else {
		int dish = (rand() % n) + 1;
		v[dish] = max(0, v[dish] - 1);
		return 1 + experiment(v, n);
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
	vector<int>dishes, temp;
	dishes.resize(n + 1);
	temp.resize(n + 1);
	F1(dishes, n);
	temp = dishes;
	double total_ops = 0;
	int conduct_exp = 1000000;
	for (int i = 1; i <= conduct_exp; i++) { 
		total_ops += experiment(dishes, n);
		dishes = temp;
	}
	cout  << total_ops / conduct_exp << endl;
	return 0;
}
