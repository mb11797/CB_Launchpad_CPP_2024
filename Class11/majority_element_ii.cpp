class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int trappedEl_1 = -1;
        int trappedEl_2 = -1;
        
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] == trappedEl_1)
                count1++;
            else if(nums[i] == trappedEl_2)
                count2++;
            else if(count1 == 0){
                trappedEl_1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                trappedEl_2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        
        for(int el: nums){
            if(el == trappedEl_1)
                count1++;
            else if(el == trappedEl_2)
                count2++;
        }
        
        vector<int> ans;
        if(count1 > n/3)
            ans.push_back(trappedEl_1);
        if(count2 > n/3)
            ans.push_back(trappedEl_2);
        return ans;
    }    
};