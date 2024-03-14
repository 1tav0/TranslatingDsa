package Graphs;

import java.util.ArrayList;
import java.util.List;

public class Main {
  static class Graph {
    int V;
    List<List<Integer>> adj;

    public Graph(int vertices) {
      V = vertices;
      adj = new ArrayList<>(V);
      for (int i = 0; i < V; ++i) {
        adj.add(new ArrayList<>());
      }
    }

    void addEdge(int u, int v) {
      adj.get(u).add(v);
      adj.get(v).add(u);
    }

    void dfs(int node, boolean[] vis) {
      vis[node] = true;
      for (int u : adj.get(node)) {
        if (!vis[u]) {
          dfs(u, vis);
        }
      }
    }

    int countProvinces() {
      int cnt = 0;

      boolean[] vis = new boolean[V];
      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          dfs(i, vis);
          cnt++;
        }
      }
      return cnt;
    }
  }
  

  public static void main(String[] args) {
    int V = 5;
    Graph graph = new Graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    
    int provinces = graph.countProvinces();
    System.out.println("Number of provinces is: " + provinces);
  }
}