vector<int> Solution::lszero(vector<int> &A) {
    map<int, int> m;
    // vector<int> prefix_sums;
    
    int k = 0, l = 0, prefix_sum = 0;
    
    m.insert({prefix_sum, -1});
    for(int i=0; i<A.size(); i++){
        prefix_sum += A[i];
        if(m.find(prefix_sum) != m.end()){
            if(i - m[prefix_sum] > l - k){
                k = m[prefix_sum];
                l = i;
            }
        }
        else{
            m.insert({prefix_sum, i});
        }
    }
    
    vector<int> ans;
    for(int i=k+1; i<=l; i++){
        ans.push_back(A[i]);
    }
    return ans;
}
