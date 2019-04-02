#include "bits/stdc++.h"
using namespace std;
int c[1000];
int numcoin;
int table[1000]; // table[i] will be storing the number of solutions for value i.
int solve(int make)
{
    table[0]=1;
    for(int i=1;i<=numcoin;i++)
    {
        for(int val = c[i] ; val<=make ; val++)
        {
            table[val] += table[val-c[i]];
        }
    }
    return table[make];
}
int main()
{
    int rob;
    //cin >> rob;
    //while(rob--)
    //{
    cin >> numcoin;
    for(int i=1;i<=numcoin;i++) cin >> c[i];
    int make;
    cin >> make;
    memset(table,0,sizeof(table));
    cout << solve(make) << "\n";
    //}
}