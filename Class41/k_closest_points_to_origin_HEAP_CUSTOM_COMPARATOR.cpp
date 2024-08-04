#define ll long long
class Point{
public:
    ll distSquare;
    int x;
    int y;

    Point(int distSquare, int x, int y){
        this->distSquare = distSquare;
        this->x = x;
        this->y = y;
    }
};

class Solution {
public:

    // bool meraComparator(string a, string b){
    //     //...
    // }

    // sort(arr.begin(), arr.end(), meraComparator);
    // // meraComparator -> functor

    class MyComparator{
    public:
        bool operator()(Point p1, Point p2){
            return p1.distSquare < p2.distSquare;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, MyComparator> maxPQ;

        for(int i=0; i<k; i++){
            int x = points[i][0];
            int y = points[i][1];
            ll distSquare = x * x * 1l + y * y * 1l;
            maxPQ.push(Point(distSquare, x, y));
        }

        int n = points.size();
        for(int i=k; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            ll distSquare = x*x*1l + y*y*1l;
            if(distSquare < maxPQ.top().distSquare){
                maxPQ.pop();
                maxPQ.push(Point(distSquare, x, y));
            }
        }

        vector<vector<int>> ans;
        while(!maxPQ.empty()){
            Point p = maxPQ.top();
            maxPQ.pop();
            ans.push_back({p.x, p.y});
        }

        return ans;
    }
};