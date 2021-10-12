#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s)
{

    string b = s;
    reverse(b.begin(), b.end());

    int n = s.length();
    int m = b.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
int main()
{
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s);
    return 0;
}