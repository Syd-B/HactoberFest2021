#include <bits/stdc++.h>
using namespace std;
//Using HashMap, O(n) runtime
int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();

    unordered_map<int, int> mp;
    mp[arr[0]] = 1;

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (mp.find(arr[i] - difference) != mp.end())
        {
            mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - difference] + 1);

            ans = max(ans, mp[arr[i]]);
        }

        else
            mp[arr[i]] = 1;
    }

    return ans;
}
int main()
{

    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;

    cout << longestSubsequence(arr, difference);
    return 0;
}
