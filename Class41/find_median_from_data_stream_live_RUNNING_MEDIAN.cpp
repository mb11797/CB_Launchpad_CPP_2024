class MedianFinder {
public:
    priority_queue<int> lft_maxPQ;
    priority_queue<int, vector<int>, greater<int>> ryt_minPQ;

    MedianFinder() {
        lft_maxPQ = priority_queue<int>();
        ryt_minPQ = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        if(lft_maxPQ.empty() or num < lft_maxPQ.top()){
            lft_maxPQ.push(num);
        }
        else{
            ryt_minPQ.push(num);
        }

        if(lft_maxPQ.size() > 1 + ryt_minPQ.size()){
            ryt_minPQ.push(lft_maxPQ.top());
            lft_maxPQ.pop();
        }
        else if(1 + lft_maxPQ.size() < ryt_minPQ.size()){
            lft_maxPQ.push(ryt_minPQ.top());
            ryt_minPQ.pop();
        }
    }
    
    double findMedian() {
        if(lft_maxPQ.size() == ryt_minPQ.size())
            return (double) ((lft_maxPQ.top() + ryt_minPQ.top()) / 2.0);
        
        if(lft_maxPQ.size() > ryt_minPQ.size())
            return lft_maxPQ.top();
        else
            return ryt_minPQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */