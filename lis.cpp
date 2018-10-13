#include "bits/stdc++.h"
using namespace std;
int tree[1000005];
int lis[1000005];
int main()
{
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> tree[i];
	}
	//memset(lis,-1,sizeof lis);
	for(int i=0;i<1000005;i++) lis[i]=-1000000;
	for(int i=1;i<=n;i++){
		int f=1;
		int l=n;
		while(f<=l){ //f=first l=last
			int m=(f+l)/2;
			if( lis[m]==-1000000 || ( lis[m]!=-1000000 && tree[i]<=lis[m]) ) {
				l=m-1;
			}
			else f=m+1;
		}
		lis[f]=tree[i];
		ans=max(ans,f);
	}
	cout << ans ;

}
//find size of lis
