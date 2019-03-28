#include "bits/stdc++.h"
using namespace std;
#define ll long long
//ll f[1000000];
int arr[200010];
int n;
ll query(int idx,ll f[])
{
	ll sum=0;
	for(int i=idx;i>0;i-=(i&-i)) sum+=f[i];
	return sum;
}
void update(int idx , ll val , ll f[])
{
	for(int i=idx;i<=n;i+=(i&-i)) f[i]+=val;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rob;
	cin >> rob;
	while(rob--)
	{
		ll invcnt=0;
		int temp[200010];
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> arr[i];
			temp[i]=arr[i];
		}
		sort(temp+1,temp+1+n);
		for(int i=1;i<=n;i++)
		{
			arr[i]=lower_bound(temp+1,temp+1+n,arr[i]) - temp ;
		}
		ll f[n+10];
		memset(f,0,sizeof(f));
		for(int i=n;i>0;i--)
		{
			invcnt+=query(arr[i]-1,f);
			update(arr[i],1,f);
		}
		cout << invcnt << "\n";
	}
}