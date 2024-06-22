#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
//    int n=8;
    cin>>n;
//    int n = 8;
    stack<int> s;
//    int hist[n] = {6,2,5,4,5,1,6};

//    int hist[n] = {2,4,5,6,6,5,4,2};
    int hist[n];
    for(int p=0; p<n; p++){
        cin>>hist[p];
    }

    int area = 0;
    int i=0;
    for(i=0; i<n; i++){
        if(!s.empty()){
            if(hist[i] < hist[s.top()]){                     //obstacle identified - so pop the top of stack
                while(hist[i]<hist[s.top()]){
                    int temp = hist[s.top()];
                    s.pop();
                    if(s.empty()){
                        area = max(area, temp*i);
                        break;
                    }
                    else{
                        area = max(area, temp*(i - s.top() - 1));
                    }
                }
                s.push(i);
            }
            else{
                s.push(i);
            }
        }
        else{
            s.push(i);
        }
    }
    //pop the remaining elements from stack while calculating the area while considering them as minimum
    while(!s.empty()){
        int temp = hist[s.top()];
        s.pop();
        if(s.empty()){
            area = max(area, temp*i);
            break;
        }
        else{
            area = max(area, temp*(i - s.top() - 1));
        }
    }

    cout<<"Area: "<<area<<endl;

    return 0;
}
