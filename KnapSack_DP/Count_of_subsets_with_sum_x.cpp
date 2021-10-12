#include<bits/stdc++.h>
using namespace std;
int count_of_subsetsum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
        
    for(int j=0;j<sum+1;j++)
        dp[0][j] =false;

    for(int i=0;i<n+1;i++)
        dp[i][0] =true;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j] + dp[i-1][j -arr[i-1]];

            else 
            dp[i][j] = dp[i-1][j];
        }

    }

    return dp[n][sum];


}
int main()
{
    
    int a[] = {3,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int sum = 9;
 
    cout << (count_of_subsetsum(a, n, sum));
    return 0;
}