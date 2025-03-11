#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    int Helper(int ind, int prev, vector<int> &nums)
    {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int notTake = Helper(ind + 1, prev, nums);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + Helper(ind + 1, ind, nums);
        }
        return dp[ind][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));
        return Helper(0, -1, nums);
    }
};
int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << obj.lengthOfLIS(arr);
}