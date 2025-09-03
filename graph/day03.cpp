#include<iostream>
#include<vector>
#include<string>
#include<list>
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


int main(){
cycleDetectionInDirectedGraph();
    return 0;
}