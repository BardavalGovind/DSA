#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cutRod(vector<int> &price)
    {

        int n = price.size();
        vector<int> dp(n + 1, 0);

        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i < len; i++)
            {
                dp[len] = max(dp[len], price[i] + dp[len - (i + 1)]);
            }
        }
        return dp[n];
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.cutRod(arr);
}