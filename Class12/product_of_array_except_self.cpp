// Macros

#define ll long long
#define f(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lftProd(n), rytProd(n);
        
        lftProd[0] = nums[0];
        for(int i=1; i<n; i++)
            lftProd[i] = lftProd[i-1] * nums[i];
        
        rytProd[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            rytProd[i] = rytProd[i+1] * nums[i];
        
        vector<int> ans(n);
        f(i,n){
            int lftKaProd = i>0 ? lftProd[i-1] : 1;
            int rytKaProd = i+1<n ? rytProd[i+1] : 1;
            ans[i] = lftKaProd * rytKaProd;
        }
        
        return ans;
    }
};