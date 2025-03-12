#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;
    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (diff == 1)
            {
                dp[i][j] = (s[i] == s[j]) ? 2 : 1;
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
            ans = dp[i][j];
        }
    }
    return ans;
}