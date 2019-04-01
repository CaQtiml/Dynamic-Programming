#include "bits/stdc++.h"
using namespace std;
#define INF 1e9+29;
int eggbenedict(int n,int k)
{
	int egg[n+5][k+5];
	for(int i=1;i<=n;i++)
	{
		egg[i][1] = i;
	}
	for(int i=1;i<=k;i++)
	{
		egg[1][i] = 1;
		egg[0][i] = 0;
	}
	for(int i=2;i<=k;i++)
	{
		for(int j=2;j<=n;j++)
		{
			egg[j][i] = INF;
			for(int k=1;k<=j;k++)
			{
				int res = 1+max(egg[j-k][i],egg[k-1][i-1]);
				if(res<egg[j][i]) egg[j][i] = res ;
			}
		}
	}
	return egg[n][k];
}
int main()
{
	int n,k;
	cin >> k >> n ; //k eggs n floors
	cout << eggbenedict(n,k);
}
//O(KN^2)