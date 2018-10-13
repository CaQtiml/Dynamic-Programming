#include "bits/stdc++.h"
using namespace std;
int c[52];
int numcoin;
long long table[52][252];
bool calculated[52][252];
long long solve(int i , int make)
{
	if(make==0) return 1; //one way, use nothing
	if(make<0) return 0; //impossible
	if(i>numcoin) return 0;
	if(calculated[i][make]==false)
	{
		table[i][make]=solve(i+1,make) + solve(i,make-c[i]);
		//ans of table[i][make] = if we ignore this coin type + if we use this coin type
		calculated[i][make] = true ;
	}
	return table[i][make];
}
int main()
{
	int make;
	cin >> make >> numcoin ; 
	for(int i=1;i<=numcoin;i++)
	{
		scanf("%d",&c[i]);
	}
	cout << solve(1,make);
}