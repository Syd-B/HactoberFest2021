#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int diff)
{
    int sum=0;

    for(int i=0;i<n;i++)
    sum = sum + arr[i];

    int s1 = (diff+sum)/2;

    // Reduced to 'count of Subset Sum"

    int dp[n+1][s1+1];

    for(int j=0;j<s1+1;j++)
    dp[0][j] = 0;

    for(int i=0;i<n+1;i++)
    dp[i][0] = 1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s1+1;j++)
        {
            if(arr[i-1] <=j)
            dp[i][j] = dp[i-1][j] + dp[i-1][j -arr[i-1]];

            else 
            dp[i][j] = dp[i-1][j];
        }
    }


    return dp[n][s1];

}
int main()
{   
    int arr[] ={1,1,1,1,1};
    int n =sizeof(arr)/sizeof(arr[0]);

    cout<<solve(arr,n,3);
    return 0;
}