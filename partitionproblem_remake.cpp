#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	int arr[n+5];
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	//sum/=2;
	bool dp[n+5][(sum/2)+5];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++)
			dp[i][j]=0;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum/2;j++)
		{
			if(j==0) dp[i][j] = true ;
			else if(i==0) dp[i][j] = false;
			else if(j-arr[i]<0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]] ;
		}
	}
	int ans = 1e9+29;
	for(int i=sum/2;i>=0;i--)
	{
		if(dp[n][i])
		{
			cout << sum-2*i;
			break;
		}
	}
	//cout << ans ;
}