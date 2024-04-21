class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int trappedEl = nums[0];
        int count = 1;
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i] == trappedEl){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    trappedEl = nums[i];
                    count = 1;
                }
            }
        }
        
        count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == trappedEl)
                count++;
        }
        
        // if(count > n / 2)
        //     return trappedEl;
        
        return (count > n/2) ? trappedEl : -1;
    }
};