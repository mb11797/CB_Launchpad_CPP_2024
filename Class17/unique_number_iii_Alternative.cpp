class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int el: nums){
            xorr = xorr ^ el;
        }
        
        int mask = (xorr & ((unsigned long long)xorr-1)) ^ xorr;
        int A = 0, B = 0;
        for(int el: nums){
            if((el & mask) > 0)
                A = A ^ el;
            else
                B = B ^ el;
        }
        
        return {A,B};
    }
};