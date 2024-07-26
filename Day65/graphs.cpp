#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void insertNode(int u, int v, bool direction){
            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void display(){
            for(auto i: adj){
                cout<<i.first<< " -> ";
                for(auto j: i.second){
                    cout<<j<< ", ";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n;
    cout<< "Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<< "Enter number of edges : ";
    cin>>m;

    Graph g;
    
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;

        g.insertNode(u, v, 0);
    }
    g.display();

    return 0;
}