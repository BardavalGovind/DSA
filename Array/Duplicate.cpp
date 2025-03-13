class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            for(int i=0; i<nums.size(); i++){
                while(nums[i]-i != 1){
                    int pos = nums[i]-1;
                    if(nums[pos]-pos == 1) return nums[pos];
                    swap(nums[i], nums[pos]);
                }
            }
            return -1; 
        }
};