#include <bits/stdc++.h>
using namespace std;
int equalPartition(int arr[],int N)
{

    int n = N;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    if (sum % 2 != 0)
        return false;

    else if (sum % 2 == 0)
    {
        int x = sum / 2;
        bool dp[n + 1][sum + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < x + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;

                else if (j == 0)
                    dp[i][j] = true;

                else if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];

                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][x];
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << equalPartition(arr, n);
    return 0;
}