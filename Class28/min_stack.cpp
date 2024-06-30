#define ll long long
class MinStack {
public:
    
    stack<ll> stk;
    ll minm;
    
    MinStack() {
        while(!stk.empty())
            stk.pop();
        minm = INT_MAX;
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(val);
            minm = val;
        }
        else{
            if(val < minm){
                // push encrypted value 
                stk.push(2*1ll*val - minm);
                minm = val;
                
                // val = -3
                // oldMinm = -2
                // minm = -3
            }
            else{
                stk.push(val);
            }
        }
    }
    
    void pop() {
        if(stk.top() < minm){
            // restore your old minm
            minm = 2*minm - stk.top();
            // 2*(-3) - -4
            stk.pop();
        }
        else{
            stk.pop();
        }     
    }
    
    int top() {
        // check for your identifier
        if(stk.top() < minm){
            return minm;
        }
        else{
            return stk.top();
        }
    }
    
    int getMin() {
        return minm;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */