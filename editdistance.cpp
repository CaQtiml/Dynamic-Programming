#include "bits/stdc++.h"
using namespace std;
char a[2000000],b[2000000];
int n,m;
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
void editdistance() 
{
	int dp[n+5][m+5];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0) dp[i][j]=j; //insert all
			else if(j==0) dp[i][j]=i; //remove all
			else if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
			else
			{
				dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]); //min(insert,remove,replace)
			}
		}
	}
	cout << dp[n][m];
}
int main()
{
	cin >> a+1 >> b+1;
	//cout << a[1];
	n = strlen(a+1);
	m = strlen(b+1);
	//cout << n << m << "\n";
	editdistance();
}
//doesn't test with strong testcase