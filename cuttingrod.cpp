#include "bits/stdc++.h"
using namespace std;
int p[100000];
const int INF = 1e9+29;
int dp[100000];
int cut(int n)
{
	for(int j=1;j<=n;j++) //length of rod that we are considering
	{
		int mx=-INF;
		for(int i=1;i<=j;i++)
		{
			mx=max(mx,p[i]+dp[j-i]);
		}
		dp[j]=mx;
	}
	return dp[n];
}
int main()
{
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++) cin >> p[i];
	cout << cut(n);
}