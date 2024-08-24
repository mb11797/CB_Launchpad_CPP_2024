#include<iostream>
#include<algorithm>
using namespace std;

/*
7 8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3
*/


class Edge{
public:
    int src;
    int dest;
    int weight;
};

class Set{
public:
    int parent;
    int rank;
};

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int find(Set*set, int i){
    if(set[i].parent==i)
        return set[i].parent;
    return find(set, set[i].parent);
}

void Union(Set*set, int v1, int v2){
    int v1_root = find(set, v1);
    int v2_root = find(set, v2);

    if(set[v1_root].rank > set[v2_root].rank){
        set[v2_root].parent = v1_root;
    }else if(set[v2_root].rank > set[v1_root].rank){
        set[v1_root].parent = v2_root;
    }else{
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;
    }
    return;
}

void kruskals(Edge*input, int V, int E){
    sort(input, input+E, cmp);              //sort the input array (edges array) on the basis of the wights
    Edge*output = new Edge[V-1];            //initialize an output array

    Set*set = new Set[V];                   //initialize the sets for all vertices

    for(int e=0; e<E; e++){
        set[e].parent = e;                  //assigning the parent of all the vertices as themselves as they are initially in their own sets
        set[e].rank = 0;                    //assigning initial rank of all vertices as zero
    }

    int counter = 0;
    int i = 0;
    while(counter < V-1){
        Edge current_edge = input[i];                       //extract the edge with minimum weight
        int src_parent = find(set, current_edge.src);       //find the parent of source vertex
        int dest_parent = find(set, current_edge.dest);     //find the parent of dest vertex

        if(src_parent != dest_parent){                      //if both do not lie the same set
            output[counter] = current_edge;                 //then insert the edge in mst, i.e, output array
            Union(set, src_parent, dest_parent);            //and union the sets of src and dest vertex
            counter++;
        }
        i++;
    }

    //Print MST
    int total_weight = 0;
    for(int m=0; m < V-1; m++){
        cout<<output[m].src<<"---"<<output[m].dest<<" with weight "<<output[m].weight<<endl;
        total_weight += output[m].weight;
    }
    cout<<"Total weight of MST: "<<total_weight<<endl;
    return;
}


int main(){
    int V, E;
    cin>>V>>E;
    Edge*input = new Edge[E];
    for(int i=0; i<E; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, V, E);

    return 0;
}
