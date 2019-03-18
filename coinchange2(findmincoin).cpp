#include "bits/stdc++.h"
using namespace std;
const int N = 1e6+5;
const int INF = 1e9+10; 
int dp[N],par[N]; //dp[i]=amount of coin to make "i" baht
int c[12];
int ans[3][12];
//pair<int,int> p[11];
#define f first
#define s second
int main()
{

	memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int price  , N;
	cin >> price >> N ;
	dp[0]=0;
	for(int i=1;i<=N;i++) cin >> c[i] ;
	for(int i=1;i<=price;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(c[j]<=i)
			{
				if(dp[i]==-1 || dp[i]!=-1 && dp[i]>dp[i-c[j]]+1)
				{
					dp[i]=dp[i-c[j]]+1;
				}
			}
		}
	}
	for(int i=1;i<=price;i++)
	{
		cout << dp[i] << " ";
	}
	cout << "\n";
}

//wrong implementation
// for(int i=1;i<=N;i++)
	// {
	// 	int w;
	// 	cin >> w;
	// 	c[i]=w;
	// 	for(int j=w ; j<limit ; j++)
	// 	{
	// 		//dp[j]=min(dp[j] , dp[j-w]+1);
	// 		if(dp[j-w]+1<dp[j])
	// 		{
	// 			dp[j]=dp[j-w]+1;
	// 			par[j]=j-w;
	// 		}
	// 	}
	// }
