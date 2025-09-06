#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<stack>
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


void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adjList, vector<bool> &visited){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neigh : adjList[node]){
        if(neigh == parent){
            continue;
        }

        if(visited[neigh] == false){
            dfs(neigh, node, timer, disc, low, result, adjList, visited);

            low[node] = min(low[node], low[neigh]);

            if(low[neigh] > disc[node]){
                result.push_back({node, neigh});
            }
        } else {
            low[node] = min(low[node], disc[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1;
    vector<bool> visited(n, false);
    vector<vector<int>> result;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, adjList, visited);
        }
    }

    return result;

}

void BridgesInParagraphExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;                 // 'n' for nodes, 'm' for edges.

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges (u v w): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> answer_bridges = findBridges(edges, n, m);

    cout << "Bridges Edges" ;

    if(answer_bridges.empty()){
        cout << "None";
    } else {
        for(const auto& bridge_edge: answer_bridges){
            cout << "[" << bridge_edge[0] << "," << bridge_edge[1] << "]";
        }
    }

    cout << endl;
}

void dfsArticulation(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &result, unordered_map<int, list<int>> &adjList, vector<bool> &visisted){
    visisted[node] = true;
    disc[node] = low[node] = timer++;
    int childCount = 0;

    for(auto neigh: adjList[node]){
        if(neigh == parent){
            continue;
        }

        if(visisted[neigh] == false){
            childCount++;

            dfsArticulation(neigh, node, timer, disc, low, result, adjList, visisted);

            low[node] = min(low[node], low[node]);

            if(low[neigh] >= disc[node] && parent != -1){
                result.push_back(node);
            }
        } else {
            low[node] = min(low[node], disc[neigh]);
        }
    }

    if(parent == -1 && childCount > 1){
        result.push_back(node);
    }
}

vector<int> cutVertes(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visisted(n, false);
    vector<int> result;

    for(int i = 0; i < n; i++){
        if(!visisted[i]){
            dfsArticulation(i, parent, timer, disc, low, result, adjList, visisted);
        }
    }

    return result;

}

void ArticulationPointIngraphExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;                 // 'n' for nodes, 'm' for edges.

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges (u v w): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> answer_articulation_points = cutVertes(edges, n, m);
    
    sort(answer_articulation_points.begin(), answer_articulation_points.end());

    answer_articulation_points.erase(unique(answer_articulation_points.begin(), answer_articulation_points.end()), answer_articulation_points.end());


    cout << "Articulation Points : " ;

    if(answer_articulation_points.empty()){
        cout << "None";
    } else {
        for(int ap:  answer_articulation_points){
            cout << ap << " ";
        }
    }

    cout << endl;
}


void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList) {
    visited[node] = true;

    for(int neigh: adjList[node]){
        if(visited[neigh] == false){
            topoSort(neigh, visited, st, adjList);
        }
    }

    st.push(node);
}

void revDFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose){
    visited[node] = true;

    for(int neigh: transpose[node]){
        if(visited[neigh] == false){
            revDFS(neigh, visited, transpose);
        }
    }
}

int stronglyConnectedCoponents(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            topoSort(i, visited, st, adjList);
        }
    }

    unordered_map<int, list<int>> transpose;
    for(int i = 0; i < n; i++){
        visited[i] = false;
        for(int neigh: adjList[i]){
            transpose[neigh].push_back(i);
        }
    }

    int count = 0;
    while(!st.empty()){
        int top_node = st.top();
        st.pop();


        if(visited[top_node] == false){
            count++;
            revDFS(top_node, visited, transpose);
        }
    }

    return count;
}


void KosarajuAlgorithmExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;                 // 'n' for nodes, 'm' for edges.

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges (u v w): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int ssc_count = stronglyConnectedCoponents(edges, n, m);

    cout << "total Strongly Connected Componets : " << ssc_count << endl;    


    cout << endl;
}

vector<int> shortestPathBellmanFord(vector<vector<int>> &edges, int n, int m, int src){
    vector<int> distance(n, INT_MAX);

    distance[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    for(int j = 0; j < m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
            return vector<int>(n, INT_MAX);
        }
    }

    return distance;
}

void BellmanFordAlgorithmExec(){
      vector<vector<int>> edges; // Stores edges in format {u, v, w}.
    int n, m;   
    int src;              // 'n' for nodes, 'm' for edges.

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

    cout << "Enter the source node : ";
    cin >> src;

    vector<int> answer = shortestPathBellmanFord(edges, n, m, src);


    cout << "Shortest path from  " << src << " : ";

    for(int x: answer){
        if(x == INT_MAX){
            cout << "INF";
        } else {
            cout << x << " ";
        }
    }


    cout << endl;
}



int main(){

    // exePrismMST();
// DisjointSetExec();
// kruskalsMSTExec();
// BridgesInParagraphExec();
// ArticulationPointIngraphExec();
// KosarajuAlgorithmExec();
BellmanFordAlgorithmExec();
    return 0;
}