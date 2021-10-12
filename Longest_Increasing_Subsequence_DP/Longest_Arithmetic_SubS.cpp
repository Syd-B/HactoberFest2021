#include <bits/stdc++.h>
using namespace std;

// O(n*n) approach, based on LIS(Longest Increasing SubSeqsequnce)
int longestSubsequence(vector<int> &arr, int difference)
{

    int n = arr.size();

    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] - arr[j] == difference && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    return ans;
}

int main()
{
    vector<int> nums = {1,5,7,8,5,3,4,2,1};
    int difference = -2;

    cout<<longestSubsequence(nums,difference);

    
    return 0;
}