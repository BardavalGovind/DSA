class Solution {
    public:
        int Helper(int i, int j, string &s){
            if(i > j) return 0;
            if(i == j) return 1;
    
            int take = 0, nottake=0;
            if(s[i] == s[j]){
                take = 2+Helper(i+1, j-1, s);
            }
            else{
                nottake = 0;
            }
            return max(take, nottake);
        }
        int longestPalindrome(string s) {
            int n = s.size();
            return Helper(0, n-1, s)<<endl;
           
        }
    };