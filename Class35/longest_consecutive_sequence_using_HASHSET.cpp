class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uSet;
        
        for(int el: nums){
            uSet.insert(el);
        }
        
        int maxLen = 0;
        for(int el: nums){
            if(uSet.find(el-1) == uSet.end()){
                int currentLen = 1;
                int currentNum = el;
                
                while(uSet.find(currentNum + 1) != uSet.end()){
                    currentLen++;
                    currentNum++;
                }
                
                maxLen = max(maxLen, currentLen);
            }
        }
        
        return maxLen;
    }
};