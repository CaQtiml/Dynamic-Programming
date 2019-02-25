#include "bits/stdc++.h"
using namespace std;
char a[100];
char b[100];
int lcs(char *a , char *b , int m , int n)
{
	int L[m+10][n+10];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0) L[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				L[i][j] = 1 + L[i-1][j-1] ;
			}
			else L[i][j]=max(L[i][j-1],L[i-1][j]);
		}
	}
	return L[m][n];
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	scanf("%s%s",a,b);
	cout << lcs(a,b,m,n);
}