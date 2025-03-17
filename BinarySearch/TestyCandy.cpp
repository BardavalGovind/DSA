#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool ispossible(int minTest, vector<int>& price, int k){
            int count=1;
            int prev = price[0];
            for(int i=1; i<price.size(); i++){
                if(price[i]-prev >= minTest){
                    count++;
                    prev = price[i];
                }
            }
            if(count >= k){
                return true;
            }
            return false;
        }
        int maximumTastiness(vector<int>& price, int k) {
            int n = price.size();
            sort(price.begin(), price.end());
            int mn = 1, mx = price[n-1]-price[0];
            int ans=0;
            while(mn <= mx){
                int mid = (mn+mx)/2;
                if(ispossible(mid, price, k)){
                    ans = mid;
                    mn = mid+1;
                }
                else{
                    mx = mid-1;
                }
            }
            return ans;
        }
    };