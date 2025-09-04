#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
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



int main(){
    shortestPathUsingUnidirectional();
    return 0;
}