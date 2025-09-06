#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
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

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unioinSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(u == v){
        return;
    }

    if(rank[u] < rank[v]){
        parent[u] = v;
    } else if(rank[v] < rank[u]){
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void initializeDSU(int n, vector<int> &parent, vector<int> &rank){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

void DisjointSetExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;                 // 'n' for nodes, 'm' for edges.

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges (u v w): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // NOTE: The `calculatePrimsMST` function is empty.
    // If you intend to use DSU for Kruskal's, you'd implement Kruskal's here or in a separate function.
    // Example of DSU usage for a simple connectivity check:
    vector<int> parent(n);
    vector<int> rank(n);
    initializeDSU(n, parent, rank); // Initialize DSU for 'n' nodes.

    cout << "\nDSU Operations (Example):" << endl;
    // Let's process some edges to see DSU in action (e.g., from the input 'edges')
    for(const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2]; // Weight is ignored for connectivity, but part of edge struct.

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rootU != rootV) {
            cout << "Nodes " << u << " and " << v << " are in different components. Unioning them." << endl;
            unioinSet(u, v, parent, rank);
        } else {
            cout << "Nodes " << u << " and " << v << " are already in the same component (edge " << u << "-" << v << " forms a cycle)." << endl;
        }
    }
    cout << "\nFinal parent array (after example DSU operations):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "parent[" << i << "] = " << parent[i] << " (root: " << findParent(parent, i) << ")" << endl;
    }


    // The original `calculatePrimsMST` call, which currently returns an empty vector.
    // To complete this, you'd implement Kruskal's algorithm using the DSU functions.
    vector<pair<pair<int, int>, int>> answer = calculatePrismMST(edges, n, m);

    // This loop will print nothing if `calculatePrimsMST` is empty.
    // It's meant to print MST edges.
    cout << "\nMST Edges (if Kruskal's was implemented):" << endl;
    for(pair<pair<int, int>, int> x : answer) {
        pair<int,int> a = x.first;
        int b = x.second;
        cout << a.first << "-" << a.second << " : " << b << endl;
    }
}

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
};

int findParentKruskals(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}


void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParentKruskals(parent, u);
    v = findParentKruskals(parent, v);

    if(u == v){
        return;
    }

    if(rank[u] < rank[v]){
        parent[u] = v;
    } else if(rank[v] < rank[u]){
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int calculateKruslasMST(vector<vector<int>> &edges, int n){
    vector<int> parent(n);
    vector<int> rank(n);

    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end(), compare);

    int minWeight = 0;

    for(int i = 0; i < edges.size(); i++){
        int u_node = edges[i][0];
        int v_node = edges[i][1];
        int weight = edges[i][2];

        int rootU = findParentKruskals(parent, u_node);
        int rootV = findParentKruskals(parent, v_node);

        if(rootU != rootV){
            unioinSet(rootU, rootV, parent, rank);

            minWeight += weight;
        }
    }

    return minWeight;
}


void kruskalsMSTExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;                 // 'n' for nodes, 'm' for edges.

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges (u v w): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int minHeight = calculateKruslasMST(edges, n);

    cout << "Weigght of kruskal's MST : " << minHeight << endl;


}


int main(){

    // exePrismMST();
// DisjointSetExec();
kruskalsMSTExec();
    return 0;
}