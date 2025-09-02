#include<iostream>
#include<list>
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

int main(){
    // adjcencyList();
    adjListGen();
    return 0;
}