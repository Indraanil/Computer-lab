// #include <iostream>
// #include <vector>
// #include <queue>
// #include <list>
// using namespace std;

// class Graph{
//     int V;
//     list<int> *l; 

//     public:
//     Graph(int V){
//         this->V = V;
//         l = new list<int> [V];
        
//     }

//     void addEdge(int u , int v){
//         l[u].push_back(v);
//         l[v].push_back(u);
//     }

//     void printAdjust(){
//         for(int i =0;i <V;i++){
//             cout << i << " : ";
//             for(int neigh : l[i]){
//                 cout << neigh << " ";
//             }
//                 cout << endl;
//         }
//         cout << endl;
//     }

//     void bfs( int start ){
//         queue<int> q;
//         vector<bool> vis ( V, false);

//         q.push(start);
//         vis[start] = true;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             cout << node << " ";
//             for(int neighb : l[node]){
//                 if(!vis[neighb]){
//                     vis[neighb] = true;
//                     q.push(neighb);
//                 }
//             }
//         }
//         cout << endl;
//     }

//     void dfshelper(int node , vector<bool> &vis){
//         vis[node] = true;
//         cout << node <<" ";
//         for(int neigh: l[node]){
//             if(!vis[neigh]){
//                 dfshelper(neigh , vis);
//             }
//         }
//     }
//     void dfs(){
//         int node = 0;
//         vector <bool> vis(V , false);
//         dfshelper(node , vis);
//     }
// };

// int main(){
//     Graph g(5);

//     g.addEdge(0,1);
//     g.addEdge(1,2);
//     g.addEdge(1,3);
//     g.addEdge(2,4);
//     g.addEdge(0,4);
//     g.addEdge(1,4);
//     g.addEdge(2,4);

    
//     g.bfs(0);

//     g.dfs();

//     g.printAdjust();
    
// }





#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;
class Graph{
    public:
    int size;
    list<int> *l;

    Graph(int v){
        this->size = v;
        l = new list<int> [size];
    }
void insert(int u , int v){
    l[u].push_back (v);
    l[v].push_back(u);
}

void bfs(int start){
    queue<int> q;
    vector<bool> vis(size , false);

    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighb : l[node]){
            if(!vis[neighb]){
                vis[neighb] = true;
                q.push(neighb);
            }
        }
    }
}
void dfshelper(int node , vector<bool> & vis){
    vis[node] = true;
    cout << node << " ";
    for ( int neighb : l[node]){
        if(!vis[neighb]){
            dfshelper(neighb , vis);
        }
    }
}
void dfs(){
    int node = 0;
    vector<bool> vis(node , false);

    dfshelper(node , vis);
}
};

int main(){

}