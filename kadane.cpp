#include "bits/stdc++.h"
using namespace std;
#define INF -1e9
int main()
{
	int a[100];
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int gmax =INF , lmax=0;
	for(int i=1;i<=n;i++)
	{
		int lmax=max(a[i],a[i]+lmax);
		if(lmax>gmax)
		{
			gmax=lmax;
		}
	}
	cout << gmax;
}
//kadane algorithm
//Maximum Subarray Problem
//https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
