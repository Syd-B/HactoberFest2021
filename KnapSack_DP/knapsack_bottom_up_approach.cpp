#include<bits/stdc++.h>
using namespace std;
int knap_sack(int wt[],int val[],int W,int n)
{
    


    int i,j;
    int dp[n+1][W+1];   

    // Build table K[][] in bottom up manner
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;

            else if(wt[i-1] <= j)
            dp[i][j] = max(val[i-1] + dp[i-1][j- wt[i-1]], dp[i-1][j]);

            else
            dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<knap_sack(wt,val,W,n);
    return 0;
}