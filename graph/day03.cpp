#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

bool isCyclicDFS(unordered_map<int, list<int>> &adjList, vector<int>&visited, vector<int>&dfsVisited, int Node){
    visited[Node] = 1;
    dfsVisited[Node] = 1;

    for(int neighbor: adjList[Node]){
        if(visited[neighbor] == 0){
            bool ans = isCyclicDFS(adjList, visited, dfsVisited, neighbor);

            if(ans){
                return true;
            }
        } else if(dfsVisited[neighbor] == 1){
            return false;
        }
    }

    dfsVisited[Node] = 0;
    return false;
}

bool detectedCyclicIndirectedGraph(int n, vector<pair<int, int>>&edges){
    unordered_map<int, list<int>> adjList;
    for(int i = 9; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> dfsVisited(n, 0);

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            bool ans = isCyclicDFS(adjList, visited, dfsVisited, i);

            if(ans){
                return ans;
            }
        }
    }

    return false;
}

void cycleDetectionInDirectedGraph(){
    int n, m;

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

    bool ans = detectedCyclicIndirectedGraph(n, edges);

    if(ans){
        cout << "Cycle is present" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }


}


void solveDFS(unordered_map<int, list<int>> &adjList, stack<int> &st, vector<bool> &visited, int node){
    visited[node] = true;

    for(auto neighbor: adjList[node]){
        if(!visited[neighbor]){
            solveDFS(adjList, st, visited, neighbor);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    vector<int> solution;
    stack<int> st;
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            solveDFS(adjList, st, visited, i);
        }
    }

    while(!st.empty()){
        solution.push_back(st.top());
        st.pop();
    }

    return solution;
}


void topologicalSortDFS(){
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

    vector<int> topSort = topologicalSort(edges, n, m);

  cout << "Topological Sort : ";
  for(int x : topSort){
    cout << x << " ";
  }
  cout << endl;
}

void solveDFSKahns(vector<int> &solution, unordered_map<int, list<int>>&adjList, queue<int>&qu, vector<int>&indegree, vector<bool> &visited ){
    if(qu.empty()){
        return;
    }

    int frontval = qu.front();
    qu.pop();

    solution.push_back(frontval);
    visited[frontval] = 1;

    for(int neighbor : adjList[frontval]){
        indegree[neighbor]--;

        if(!visited[neighbor] && indegree[neighbor] == 0){
            qu.push(neighbor);
        }
    }

    solveDFSKahns(solution, adjList, qu, indegree, visited);
}

vector<int> topologicalSortKanhs(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(v, 0);

    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v_node = edges[i][1];

        adjList[u].push_back(v_node);
        indegree[v_node]++;
    }

    queue<int> qu;
    vector<bool> visited(v, false);
    vector<int> solution;

    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            qu.push(i);
        }
    }

    solveDFSKahns(solution, adjList, qu, indegree, visited);

    return solution;

}

void topologicalSortKanhs(){
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

    vector<int> topSort = topologicalSortKanhs(edges, n, m);

  cout << "Topological Sort : ";
  for(int x : topSort){
    cout << x << " ";
  }
  cout << endl;
}


bool detectCyclicInDirectedGraph(int n, vector<pair<int, int>> &edges){
    unordered_map<int, list<int>> adjList;

    vector<int> indegree(n, 0);

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> qu;

    int count = 0;

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            qu.push(i);
        }
    }

    while(!qu.empty()){
        count++;

        int frontVal = qu.front();
        qu.pop();

        for(int neighbor: adjList[frontVal]){
            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0){
                qu.push(neighbor);
            }
        }
    }

    return (count == n) ? false : true;
}


void topologicalSortKanhs(){
    int n, m;

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

    bool answer = detectedCyclicIndirectedGraph( n, edges);

    if(answer){
        cout << "Cycle is present" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }
}

int main(){
// cycleDetectionInDirectedGraph();
// topologicalSortDFS();
topologicalSortKanhs();
    return 0;
}