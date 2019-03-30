#include "bits/stdc++.h"
using namespace std;
int dp[1000][1000];
int ncr(int n,int k)
{
	if(k==0 || k==n) return 1;
	if(k<0 || k>n) return 0;
	if(dp[n][k]>0) return dp[n][k];
	return dp[n][k] = ncr(n-1,k-1)+ncr(n-1,k);
}
int main()
{
	int n,k;
	cin >> n >> k;
	cout << ncr(n,k);
}