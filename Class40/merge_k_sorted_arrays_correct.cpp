#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

pair<int, pair<int, int>> p;
priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>> > > pq;


vector<int> merge_k_arrays(vector<vector<int>> arr){
    vector<int> output;

    for(int i=0; i<arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while(!pq.empty()){
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();

        int i = p.second.first;
        int j = p.second.second;

        output.push_back(p.first);

        if(j+1 < arr[i].size()){
            pq.push({arr[i][j+1], {i, j+1}});
        }
    }
    return output;
}

int main(){
    vector<vector<int>> arr{{2,6,12},
                            {1,9},
                            {23,34,90,200}
                            };

    vector<int> output = merge_k_arrays(arr);
    cout<<"Merged array is: "<<endl;
    for(auto x : output)
        cout<<x<<" ";
//    cout<<arr.size()<<endl;
    return 0;
}
