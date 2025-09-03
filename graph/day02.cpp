#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void traversal(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &answer, int node){
    queue<int> Q;

    Q.push(node);

    visited[node] = 1;

    while(!Q.empty()){
        int frontVal = Q.front();
        Q.pop();

        answer.push_back(frontVal);

        for(auto neighbour: adjList[frontVal]){
            if(!visited[neighbour]){
                Q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}


vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, list<int>> adjList;
    vector<int> answer;
    unordered_map<int, bool> visited;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            traversal(adjList, visited, answer, i);
        }
    }

    return answer;
}

void BFSTraversal(){
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<pair<int, int>> edges(m);

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    vector<int> solution = BFS(n, edges);

    cout << "BFS Traversal" " ";

    for(auto node : solution){
        cout << node << " ";
    }

    cout << endl;
}


void traversalDFS(unordered_map<int, list<int>> &adjList, unordered_map<int,bool> &visited, vector<int>&component, int node) {
    component.push_back(node);
    visited[node] = 1;

    for(auto neighbor : adjList[node]){
        if(!visited[neighbor]){
            traversal(adjList, visited, component, neighbor);
        }
    }
}

vector<vector<int>> DFS(int V, int E, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adjList;

    vector<vector<int>> answer;

    unordered_map<int, bool> visited;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            traversal(adjList, visited, component, i);
            answer.push_back(component);
        }
    }

    return answer;
}


void DFSTraversal(){
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> edges(m, {0, 0});

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector<vector<int>> solution = DFS(n, m, edges);

    cout << "DFS Traversal" " ";
    int component_idx = 0;
    for(auto component : solution){
        cout << "Component " << ++component_idx << ": ";
        for(auto node_val: component){
            cout << node_val << " ";
        }
        cout << endl;
    }

}

bool isCyclicBFS(unordered_map<int, list<int>>&adjList, unordered_map<int, bool> &visited, int Node){
    unordered_map<int, int> parent;
    parent[Node] = -1;

    visited[Node] = true;

    queue<int> Q;
    Q.push(Node);

    while(!Q.empty()){
        int Frontval = Q.front();
        Q.pop();

        for(int neighbor: adjList[Frontval]){
            if(visited[neighbor] == true && parent[Frontval] != neighbor){
                return true;
            }

            if(visited[neighbor] == false){
                visited[neighbor] = true;
                parent[neighbor] = Frontval;
                Q.push(neighbor);
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            bool ans = isCyclicBFS(adjList, visited, i);

            if(ans){
                return "YES";
            }
        }
    }

    return "NO";
}


void cycleDetectionUsingBFS(){
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    edges.push_back({u, v});
    }

    string ans = cycleDetection(edges, n, m);

    cout << "Cycle Detection Result : " << ans << endl;

}

bool isCyclicDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool>&visited, int Node, int parent){
    visited[Node] = true;

    for(auto neighbor: adjList[Node]){
        if(visited[neighbor] == false){
            bool isCycleFound = isCyclicDFS(adjList, visited, neighbor, Node);
            if(isCycleFound){
                return true;
            }
        } else if(neighbor != parent){
            return true;
        }
    }

    return false;
}

string cycleDetectionDFS(vector<vector<int>>&edges, int n, int m){
    unordered_map<int, list<int>> adjList;

    unordered_map<int, bool> visited;

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            bool ans = isCyclicDFS(adjList, visited, i, -1);

            if(ans){
                return "YES";
            }
        }
    }

    return "NO";
}


void cycleDetectionUsingDFS(){
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;


    cout << "Enter the number of edges : ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter the edges (u, v) : " << endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    edges.push_back({u, v});
    }

    string ans = cycleDetectionDFS(edges, n, m);

    cout << "Cycle Detection Result : " << ans << endl;

}

int main(){
    // BFSTraversal();
    // DFSTraversal();
    // cycleDetectionUsingBFS();
    cycleDetectionUsingDFS();
    return 0;
}