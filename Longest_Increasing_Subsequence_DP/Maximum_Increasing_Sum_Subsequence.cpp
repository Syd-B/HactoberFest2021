#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int sums[n];

    for(int i=0;i<n;i++)
    sums[i] = nums[i];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i] > nums[j] && sums[j] + nums[i] > sums[i])
            sums[i] = sums[j] + nums[i];
        }
    }

    int ans = INT_MIN;

    for(int i=0;i<n;i++)
    ans = max(ans,sums[i]);

    return ans;
    
}
int main()
{
    vector<int> nums =  {1, 101, 2, 3, 100, 4, 5};

    cout<<lengthOfLIS(nums);
           

    return 0;
}