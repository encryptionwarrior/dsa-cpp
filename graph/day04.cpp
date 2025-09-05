#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<limits.h>
#include<set>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int src, int tar) {
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

        vector<int> visisted(n, 0);
        vector<int> parent(n, 0);

        queue<int> qu;

        qu.push(src);
        visisted[src] = 1;
        parent[src] = -1;

        while(!qu.empty()){
            int currentNode = qu.front();
            qu.pop();

            for(int neighbor : adjList[currentNode]){
                if(visisted[neighbor] == 0){
                    visisted[neighbor] = 1;
                    parent[neighbor] = currentNode;
                    qu.push(neighbor);
                }
            }
        }

        vector<int> solutionPath;
        int tempTarget = tar;

        while(tempTarget != src){
            solutionPath.push_back(tempTarget);
            tempTarget = parent[tempTarget];
        }

        solutionPath.push_back(src);

        reverse(solutionPath.begin(), solutionPath.end());
        return solutionPath;

}

void shortestPathUsingUnidirectional(){
    int n, m;
    int src, tar;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<pair<int, int>> edges;

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    edges.push_back({u, v});
    }

    cout << "Enter the source and targe : ";
    cin >> src >> tar;

    vector<int> answerPath = shortestPath(edges, n, m, src, tar);

    cout << "the shortest path : " ;

    for(int node: answerPath){
        cout  << node << " ";
    }

    cout << endl;
}

void solveDFS(unordered_map<int, list<pair<int, int>>> &adjList, stack<int> &st, vector<int> &visited, int node){
    visited[node] = 1;

    for(pair<int, int> neigh: adjList[node]){
        if(visited[neigh.first] == 0){
            solveDFS(adjList, st, visited, neigh.first);
        }
    }

    st.push(node);
}

stack<int> topoSort(unordered_map<int, list<pair<int, int>>> adjList, int n){
    stack<int> st;
    vector<int> visited(n, 0);

    for(int i =0; i < n; i++){
        if(adjList.count(i) || !adjList[i].empty() || i < n){
            if(visited[i] == 0){
                solveDFS(adjList, st, visited, i);
            }
        }
    }

    return st;
}

vector<int> shortestPathDirectAcyclic(vector<vector<int>> &edges, int n, int m, int src){
    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adjList[u].push_back({v, w});
    }

    stack<int> st = topoSort(adjList, n);

    stack<int> temp = st;

    cout << "Topological sort order : ";
    vector<int> topo_order_vec;
    while(!temp.empty()){
        topo_order_vec.push_back(temp.top());
        temp.pop();
    }

    reverse(topo_order_vec.begin(), topo_order_vec.end());
    for(int node_val: topo_order_vec){
        cout << node_val << " ";
    }
    cout << endl;

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(distance[node] != INT_MAX){
            for(auto neighbor_pair: adjList[node]){
                int neighbor = neighbor_pair.first;
                int weight = neighbor_pair.second;


                if(distance[node] + weight < distance[neighbor]){
                    distance[neighbor] = distance[node] + weight;
                }
            }
        }
    }

    return distance;

}

void shortestPathUsingDirectedAcyclic(){
    int n, m;
    int src;

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

    vector<int> answer_distance = shortestPathDirectAcyclic(edges, n, m, src);

    cout << "the shortest path : " << src << " " << endl ;

    for(int i = 0; i < n; i++){
        cout  << "Node " << i << ": ";
        if(answer_distance[i] == INT_MAX){
            cout << "unreachable" << endl;
        } else {
            cout << answer_distance[i] << endl;
        }
    }

    cout << endl;
}

class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int weight){
            adjList[u].push_back(make_pair(v, weight));
        }

        void printEdge(){

            for(auto const& [node, neighbors]: adjList){
                cout << node << " -> ";
                for(auto const& neighbor_pair: neighbors){
                    cout << neighbor_pair.first << "[" << neighbor_pair.second << "]";
                }
                cout << endl;
            }
        }

        private: 
            void solveDFS(stack<int> &st, vector<int> &visisted, int node){
                visisted[node] = 1;

                for(pair<int, int> neigh: adjList[node]){
                    if(visisted[neigh.first] == 0){
                        solveDFS(st, visisted, neigh.first);
                    }
                }

                st.push(node);
            }

        public: 
            stack<int> topoSort(){
                stack<int> st;
                vector<int> visited(6, 0);

                for(int i = 0; i < 6; ++i){
                    if(visited[i] == 0){
                        if(adjList.count(i) || !adjList[i].empty() || i < 6){
                            solveDFS(st, visited, i);
                        }
                    }
                }
                return st;
            }

            vector<int> shortestPath(int src){
                vector<int> distance(6, INT_MAX);

                distance[src] = 0;

                stack<int> st = topoSort();

                while(!st.empty()){
                    int currentNode = st.top();
                    st.pop();

                    if(distance[currentNode] != INT_MAX){
                        for(auto const& neighbor_pair: adjList[currentNode]){
                            int neighbor = neighbor_pair.first;
                            int weight = neighbor_pair.second;

                            if(distance[currentNode] + weight < distance[neighbor]){
                                distance[neighbor] = distance[currentNode] + weight;
                            }
                        }
                    }
                }
                return distance;
            }
};

void shorestPathDAGClass(){
    Graph G;
    G.addEdge(0, 1, 5);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 6);
    G.addEdge(0, 2, 3);
    G.addEdge(2, 3, 7);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(4, 5, -2);
    G.addEdge(2, 5, 2);

    int sourceNode = 1;
    vector<int> shortestDistance = G.shortestPath(sourceNode);

    cout << "Shortest distance from source code " << sourceNode << ":" << endl;

    for(int i = 0; i < shortestDistance.size(); ++i){
        cout << "Node" << i << ":" ;

        if(shortestDistance[i] == INT_MAX){
            cout << "INF";
        } else {
            cout << shortestDistance[i];
        }

        cout << endl;
    }
}


vector<int> shorestPathDijkstras(vector<vector<int>> &edges, int n, int m, int src){
    unordered_map<int, list<pair<int, int>>> addjList;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        addjList[u].push_back({v, w});
        addjList[v].push_back({v, w});
    }

    vector<int> distance(n, INT_MAX);

    set<pair<int, int>> st;

    distance[src] = 0;

    st.insert({0, src});

    while(!st.empty()){
        pair<int, int> curr = *(st.begin());

        int nodeDistance = curr.first;
        int topNode = curr.second;

        st.erase(st.begin());

        for(auto neighbor_pair: addjList[topNode]){
            int neighbor = neighbor_pair.first;
            int edgeWeight = neighbor_pair.second;

            if(nodeDistance + edgeWeight < distance[neighbor]){
                auto record = st.find({distance[neighbor], neighbor});
                if(record !=  st.end()){
                    st.erase(record);
                }

                distance[neighbor] = nodeDistance + edgeWeight;

                st.insert({distance[neighbor], neighbor});
            }

        }
    }

    return distance;
}

void shortestPathUsingDijkstras(){
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

    vector<int> answer_distance = shorestPathDijkstras(edges, n, m, src);

    cout << "Shortest distance from source : " << src << ":" << endl;


    for(int i = 0; i < n; i++){
        cout << "Node " << i
 << "; ";
 if(answer_distance[i] == INT_MAX){
    cout << "INF";
 } else {
    cout << answer_distance[i];
 }
    }
        

    cout << endl;
}

int main(){
    // shortestPathUsingUnidirectional();
    // shortestPathUsingDirectedAcyclic();
    // shorestPathDAGClass();
    shortestPathUsingDijkstras();
    return 0;
}