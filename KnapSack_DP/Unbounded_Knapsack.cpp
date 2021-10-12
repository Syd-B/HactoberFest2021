#include<bits/stdc++.h>
using namespace std;
int UnboundedKnapsack(int wt[],int val[],int W,int n)
{
    int dp[n+1][W+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;

            else if(wt[i-1] <=j)
            dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i][j- wt[i-1]]);

            else 
            dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}
int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    cout<<UnboundedKnapsack(wt,val,W,n);
    return 0;
}