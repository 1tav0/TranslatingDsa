import java.util.ArrayList;

public class Problem1 {
  static void dfs(int node, int vis[], ArrayList<ArrayList<Integer>> adjList) {
    vis[node] = 1;
    for (Integer v : adjList.get(node)) {
      if (vis[v] == 0) {
        dfs(v, vis, adjList);
      }
    }
  }
  static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
    ArrayList<ArrayList<Integer>> adjList = new ArrayList<>(V);
    for (int i = 0; i < V; i++) {
      adjList.add(new ArrayList<Integer>());
    }
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (adj.get(i).get(j) == 1 && i != j) {
          adjList.get(i).add(j);
          adjList.get(j).add(i);
        }
      }
    }
    int vis[] = new int[V];
    int cnt = 0;
    for (int i = 0; i < V; i++) {
      if (vis[i] == 0) {
        dfs(i, vis, adjList);
        cnt++;
      }
    }
    return cnt;
  }
  public static void main(String[] args) {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    adj.add(new ArrayList<Integer>());
    adj.get(0).add(0, 1);
    adj.get(0).add(1, 0);
    adj.get(0).add(2, 1);
    adj.add(new ArrayList<Integer>());
    adj.get(1).add(0, 0);
    adj.get(1).add(1, 1);
    adj.get(1).add(2, 0);
    adj.add(new ArrayList<Integer>());
    adj.get(2).add(0, 1);
    adj.get(2).add(1, 0);
    adj.get(2).add(2, 1);
    // adj.add(new ArrayList<>(List.of(1, 0, 1)));
    // adj.add(new ArrayList<>(List.of(0, 1, 0)));
    // adj.add(new ArrayList<>(List.of(1, 0, 1)));
    Problem1 obj = new Problem1();
    int result = obj.numProvinces(adj, 3);
    System.out.println("number of provinces: " + result);
  }
}
