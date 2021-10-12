#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    if(n==1)
    return nums[0];


    vector<int> dp(n,1);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(nums[i] > nums[j] && dp[j] + 1 > dp[i])
            dp[i] = dp[j] + 1;
        }
    }


    int ans = INT_MIN;

    for(int i=0;i<n;i++)
    ans = max(ans,dp[i]);


    return ans; 


    
}
int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout<<lengthOfLIS(nums);    

    return 0;
}