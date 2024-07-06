vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> freqMapOfA;
    
    for(int el: A){
        freqMapOfA[el]++;
    }
    
    vector<int> ans;
    for(int el: B){
        if(freqMapOfA.find(el) != freqMapOfA.end()){
            if(freqMapOfA[el] > 0){
                ans.push_back(el);
                freqMapOfA[el]--;
            }
        }
    }
    
    return ans;
}
