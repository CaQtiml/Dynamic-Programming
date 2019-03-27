#include "bits/stdc++.h"
using namespace std;
int f[20000000];
int arr[300000];
int query(int idx,int n)
{
	int sum=0;
	for(int i=idx;i>0;i-=(i&-i)) sum+=f[i];
	return sum;
}
void update(int idx,int val,int n)
{
	for(int i=idx;i<=n;i+=(i&-i)) f[i]+=val;
}
int main()
{
	int n,mx=-1;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		if(mx<arr[i]) mx=arr[i];
	}
	int invcnt=0;
	for(int i=n;i>=1;i--)
	{
		invcnt += query(arr[i]-1,n);
		update(arr[i],1,n);
	}
	cout << invcnt ;
}
//not support negative integer