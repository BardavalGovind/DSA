#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool possible(int candy, vector<int> &candies, long long k)
    {
        long long count = 0;
        for (int c : candies)
        {
            count += (c / candy);
        }
        if (count >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int mn = 1, mx = INT_MIN;
        for (int num : candies)
        {
            mx = max(num, mx);
        }
        int ans = 0;
        while (mn <= mx)
        {
            int mid = (mn + mx) / 2;
            if (possible(mid, candies, k))
            {
                ans = mid;
                mn = mid + 1;
            }
            else
            {
                mx = mid - 1;
            }
        }
        return ans;
    }
};