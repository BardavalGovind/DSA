#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      bool possible(int mnDist, vector<int> &stalls, int k){
          int count=1;
          int prevDist = stalls[0];
          for(int i=1; i<stalls.size(); i++){
              if(stalls[i] >= prevDist+mnDist){
                  prevDist = stalls[i];
                  count++;
              }
          }
          if(count >= k) return true;
          return false;
      }
      int aggressiveCows(vector<int> &stalls, int k) {
          sort(stalls.begin(), stalls.end());
          int mn = 1, mx = stalls[stalls.size()-1]-stalls[0];
          int ans = 0;
          while(mn <= mx){
              int mid = (mn+mx)/2;
              if(possible(mid, stalls, k)){
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