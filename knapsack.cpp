#include "bits/stdc++.h"
using namespace std;
#define MAX 1000000
int dp[ MAX + 5 ] ;
int main()
{
	int sum = 0 , n ;
	scanf ( " %d " , &n ); // n=number of item
	for ( int i = 0 ; i < n ; i++ )
	{
		int w , v ;
		scanf ( " %d %d " , &w , &v ) ;
		sum += w ;
		for ( int j = sum ; j >= w ; j-- )
		{
			dp[j] = max ( dp[j] , dp[j-w] + v ) ;
		}
	}
	int maxbudget ;
	scanf ( " %d " , &maxweight ) ;
	printf ( " %d " , dp[ maxweight ] ) ;
}