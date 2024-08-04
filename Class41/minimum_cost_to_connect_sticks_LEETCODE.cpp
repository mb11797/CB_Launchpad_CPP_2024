class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for(int stick: sticks){
            minPQ.push(stick);
        }

        int ans = 0;
        while(minPQ.size() > 1){
            int stick1 = minPQ.top();
            minPQ.pop();
            int stick2 = minPQ.top();
            minPQ.pop();

            ans += stick1 + stick2;
            minPQ.push(stick1 + stick2);
        }

        return ans;
    }
};