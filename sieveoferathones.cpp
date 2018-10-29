#include "bits/stdc++.h"
using namespace std;
void sieve(int n)
{
	bool prime[n*2];
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=n;j+=i) prime[j]=false;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(prime[i]) cout << i << "\n";
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	sieve(n);
}
//O(n*log(log(n)))