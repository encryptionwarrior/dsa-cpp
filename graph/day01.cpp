#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(direction == false){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first << " -> ";

            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

};

void adjcencyList(){
    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    Graph G;

    cout << "Enter edges (u v) : " << endl;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    cout << "\nAdjacency list: " << endl;
    G.printAdjList();

}


template <typename T>
    class Graph2 {
        public: 
            unordered_map<T, list<T>> adj;

            void addEdge(T u, T v, bool direction){
                adj[u].push_back(v);

                if(direction == false){
                    adj[v].push_back(u);
                }
            }

        void printAdjList(){
            for(auto i : adj){
                cout << i.first << " -> ";

                for(auto j: i.second){
                    cout << j << " ";
                }
                cout << endl;
            }
        }

    };

void adjListGen(){
     int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    Graph2<int> G;

    cout << "Enter edges (u v) : " << endl;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    cout << "\nAdjacency list: " << endl;
    G.printAdjList();

}



class GraphMatrix {
    public:
        vector<vector<int>> adjMat;

        GraphMatrix(int nodeCount){
            adjMat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, 0));
        }

        void addEdge(int u, int v, bool direction){
            adjMat[u][v] = 1;

            if(direction == false){
                adjMat[v][u] = 1;
            }
        }

        void printAdjMatrix(){
            for(int i = 0; i < adjMat.size(); i++){
                cout << i << " -> ";

                for(int j = 0; j < adjMat.size(); j++){
                    cout << adjMat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

void adjacencyMatrix(){
    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    GraphMatrix G(n);

    cout << "Enter edges (u v) : " << endl;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    cout << "\nAdjacency list: " << endl;
    G.printAdjMatrix();
}

int main(){
    // adjcencyList();
    // adjListGen();
    adjacencyMatrix();
    return 0;
}