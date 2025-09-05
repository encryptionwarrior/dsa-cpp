#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrismMST(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX);

    vector<bool> mst(n, false);

    vector<bool> parent(n, -1);

    key[0] = 0;

    for(int count = 0; count < n; count++){
        int u = -1;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            if(mst[i] == false && key[i] < mini){
                u = i;
                mini = key[i];
            }
        }

        mst[u] = true;

        for(pair<int, int> neighbor_pair: adjList[u]){
            int neighbor_node = neighbor_pair.first;
            int edge_weight = neighbor_pair.second;

            if(mst[neighbor_node] == false && edge_weight < key[neighbor_node]){
                key[neighbor_node] = edge_weight;
                parent[neighbor_node] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> answer;
    for(int i = 1; i < n; i++){
        answer.push_back({{parent[i], i}, key[i]});
    }

    return answer;

}

void exePrismMST(){
     int n, m;
    int src, tar;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
    edges.push_back({u, v, w});
    }

    cout << "Enter the source : ";
    cin >> src;

    vector<pair<pair<int, int>, int>> mst_edges = calculatePrismMST(edges, n , m);

    cout << "Shortest distance from source : " << src << ":" << endl;


    long long total_mst_weight = 0;


    for(pair<pair<int, int>, int> edge_info : mst_edges){
        int u_node = edge_info.first.first;
        int v_node = edge_info.first.second;
        int weight = edge_info.second;

        cout << u_node << "-" << v_node << " : " << weight << endl;

        total_mst_weight += weight;
     }

     cout << "Total MST Weight: " << total_mst_weight << endl;
        

    cout << endl;


}


int main(){

    exePrismMST();

    return 0;
}