#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[],int N,int sum)
{
    bool dp[N+1][sum+1];


    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            dp[i][j] = false;

            else if(j==0)
            dp[i][j] = true;

            else if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j- arr[i-1]] ||  dp[i-1][j];

            else 
            dp[i][j] = dp[i-1][j];
        }
    }

    return dp[N][sum];
}
int main()
{   
    int arr[] = {3, 34, 4, 12, 5, 2};
    cout<<solve(arr,6,9);
    return 0;
}