#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
            unordered_map<int, vector<int>> mp;
            vector<int> ans;
            for(int i=0; i<nums.size(); i++){
                mp[nums[i]].push_back(i);
            }
            for(int q : queries){
                if(mp[x].size() < q) ans.push_back(-1);
                else ans.push_back(mp[x][q-1]);
            }
            return ans;
        }
};