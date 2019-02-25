#include "bits/stdc++.h"
using namespace std;
char a[100];
char b[100];
int lcs(char *a , char *b , int m , int n)
{
	if(m==0||n==0) return 0;
	if(a[m-1]==b[n-1])
	{
		return 1+lcs(a,b,m-1,n-1);
	}
	else return max(lcs(a,b,m,n-1),lcs(a,b,m-1,n));
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	scanf("%s%s",a,b);
	cout << lcs(a,b,m,n);
}