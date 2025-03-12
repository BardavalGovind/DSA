#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int dp[101][101];
    bool isSafe(int i, int prev_ind, vector<vector<int>> &cuboids)
    {
        if (cuboids[i][0] >= cuboids[prev_ind][0] && cuboids[i][1] >= cuboids[prev_ind][1] &&
            cuboids[i][2] >= cuboids[prev_ind][2])
            return true;
        return false;
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev_ind = i - 1; prev_ind >= -1; prev_ind--)
            {
                int notTake = dp[i + 1][prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || isSafe(i, prev_ind, cuboids))
                {
                    take = cuboids[i][2] + dp[i + 1][i + 1];
                }
                dp[i][prev_ind + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cuboids;
    for (int i = 0; i < n; i++)
    {
        vector<int> cube(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> cube[j];
        }
        cuboids.push_back(cube);
    }
    Solution sol;
    cout << sol.maxHeight(cuboids);
}