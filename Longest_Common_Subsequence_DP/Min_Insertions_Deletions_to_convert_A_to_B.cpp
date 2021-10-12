#include <bits/stdc++.h>
using namespace std;
int minOperations(string str1, string str2)
{
    // Your code goes here
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int deletions = m - dp[m][n];
    int insertions = n - dp[m][n];

    return deletions + insertions;
}
int main()
{
    string str1 = "heap", str2 = "pea";
    
    cout<<minOperations(str1,str2);
    return 0;
}