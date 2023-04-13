#include <bits/stdc++.h>

using namespace std;

class graph {
private:
  int vertice;
  vector<int> near; // to keep track of nearest nodes
  vector<vector<int>> adj;

public:
  graph(int n) {
    vertice = n;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX));
    near = vector<int>(n + 1, INT_MAX);
  }

  void insertEdge(int src, int dest, int weight) {
    adj[src][dest] = weight;
    adj[dest][src] = weight;
  }

  int Prims() {
    int src = 0, dest = 0;

    // find the minimum edge in the graph
    for (int i = 0; i <= vertice; i++) {
      for (int j = 0; j <= vertice; j++) {
        if (adj[src][dest] > adj[i][j]) {
          src = i;
          dest = j;
        }
      }
    }
    // this will store the edges we use in spannig tree
    vector<vector<int>> list(vertice + 1, vector<int>(2, 0));

    // first we add minimum edge into this list
    list[0][0] = src;
    list[0][1] = dest;

    // mark them as taken in near vector
    near[src] = 0;
    near[dest] = 0;

    int src1 = 0, dest1 = 0;
    
    // find all nearest nodes to this edge(nodes)
    for (int i = 1; i <= vertice; i++) {
      if (near[i] != 0) {
        // store nearest node in near vector
        if (adj[src][i] != adj[dest][i]) {
          near[i] = adj[src][i] > adj[dest][i] ? dest : src;
        } else {
          near[i] = max(src, dest);
        }

        // storing the overall minimum edge
        if (adj[src1][dest1] > adj[near[i]][i]) {
          src1 = near[i];
          dest1 = i;
        }
      }
    }

    

    for (int i = 1; i < vertice-1; i++) {
      list[i][0] = src1;
      list[i][1] = dest1;
      near[src1] = 0;
      near[dest1] = 0;

      int k = list[i][1];

      src1 = 0;
      dest1 = 0;
      
      // now update the near vector
      for (int u = 1; u <= vertice; u++) {
        
        if (near[u] != 0) {
          if (adj[near[u]][u] != adj[u][k]) {
            near[u] = adj[u][near[u]] > adj[k][u] ? k : near[u];
          } else {
            near[u] = max(near[u], k);
          }

          // storing the overall minimum edge
          if (adj[near[u]][u] < adj[src1][dest1]) {
            src1 = near[u];
            dest1 = u;
          }
          
        }
      }
    }
    int cost = 0;
    for(int i=0; i<vertice-1; i++){
      int u = list[i][0], v = list[i][1];
      cout << u << "->" << v << "----" << adj[u][v]<< endl;
      cost += adj[u][v];
    }
    return cost;
  }
};

int main() {

  // //One example
  graph G(7);
  G.insertEdge(1, 6, 5);
  G.insertEdge(1, 2, 25);
  G.insertEdge(2, 3, 9);
  G.insertEdge(2, 7, 6);
  G.insertEdge(3, 4, 10);
  G.insertEdge(4, 7, 11);
  G.insertEdge(4, 5, 12);
  G.insertEdge(5, 6, 18);
  G.insertEdge(5, 7, 16);
  cout << G.Prims() << endl;

  
  // // onther example
  // graph G1(3);
  // G1.insertEdge(1, 2, 5);
  // G1.insertEdge(2, 3, 3);
  // G1.insertEdge(1, 3, 1);
  // cout << G1.Prims() << endl;

  //exmaple 
  graph G2(9);
  G2.insertEdge(1, 2, 4);
  G2.insertEdge(1, 8, 8);
  G2.insertEdge(2, 8, 11);
  G2.insertEdge(2, 3, 8);
  G2.insertEdge(3, 9, 2);
  G2.insertEdge(3, 4, 7);
  G2.insertEdge(3, 6, 4);
  G2.insertEdge(4, 5, 9);
  G2.insertEdge(4, 6, 14);
  G2.insertEdge(5, 6, 10);
  G2.insertEdge(6, 7, 2);
  G2.insertEdge(7, 9, 6);
  G2.insertEdge(7, 8, 1);
  G2.insertEdge(8, 9, 7);

  cout << G2.Prims() << endl;
  
  
  
  return 0;
}