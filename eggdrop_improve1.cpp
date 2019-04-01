#include "bits/stdc++.h"
using namespace std;
map<int,int> memo;
//int memo[10010][10010];
int egg(int n,int k)
{
	if(memo[n*100+k]==0)
	{
		if(n==0||n==1) return n;
		if(k==1) return n;
		int st=1,ed=n;
		while(st<ed)
		{
			int mid = (st+ed)>>1;
			int t1 = egg(mid-1,k-1);
			int t2 = egg(n-mid,k);
			if(t1<t2) st=mid+1;
			else if(t1>t2) ed=mid;
			else 
			{
				st=mid;
				ed=mid;
			}
		}
		int ans = 1+min( max(egg(st-1,k-1),egg(n-st,k)) , max(egg(ed-1,k-1),egg(n-ed,k)) );
		memo[n*100+k] = ans;
	}
	return memo[n*100+k];
}
int main()
{
	int n,k;
	cin >> k >> n;
	cout << egg(n,k);
}