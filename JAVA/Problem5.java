import java.util.ArrayList;

class Solution{

  public boolean dfs(int node, int parent, int[] vis, ArrayList<ArrayList<Integer>> adj){
    vis[node] = 1;
    for(Integer v: adj.get(node)){
      if(vis[v]==0){
        if(dfs(v, node, vis, adj)==true) return true;
      }else if(v != parent){
        return true;
      }
    }
    return false;
  }

  public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj){
    int[] vis = new int[V];
    for(int i=0; i<V; i++){
      if(vis[i]==0){
        if(dfs(i, -1, vis, adj)==true) return true;
      }
    }
    return false;
  }

  // Function to add an edge to the adjacency list
  public static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
      adj.get(u).add(v);
  }

  // Function to print the adjacency list
    static void printGraph(ArrayList<ArrayList<Integer>> adj) {
        for (int i = 0; i < adj.size(); i++) {
            System.out.print("Adjacency list of vertex " + i + ": ");
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.print(adj.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

  public static void main(String[] args){
    int V = 5;
    // adj.add(new ArrayList<Integer>(){{ add(1); }});          // Vertex 0
    // adj.add(new ArrayList<Integer>(){{ add(0); add(2); add(4); }}); // Vertex 1
    // adj.add(new ArrayList<Integer>(){{ add(1); add(3); }}); // Vertex 2
    // adj.add(new ArrayList<Integer>(){{ add(2); add(4); }}); // Vertex 3
    // adj.add(new ArrayList<Integer>(){{ add(1); add(3); }}); // Vertex 4
    // Initialize the 2D list
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    for (int i = 0; i < V; i++) {
       adj.add(new ArrayList<Integer>());
    }
    Solution obj = new Solution();

    // Add edges
    // vector<int> adj[V] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}; c++
    // obj.addEdge(adj, 0, 1);
    // obj.addEdge(adj, 1, 0);
    // obj.addEdge(adj, 1, 2);
    // obj.addEdge(adj, 1, 4);
    // obj.addEdge(adj, 2, 1);
    // obj.addEdge(adj, 2, 3);
    // obj.addEdge(adj, 3, 2);
    // obj.addEdge(adj, 3, 4);
    // obj.addEdge(adj, 4, 1);
    // obj.addEdge(adj, 4, 3);
    // vector<int> adj[V] = {{}, {2}, {1, 3}, {2}}; c++
    obj.addEdge(adj, 1, 2);
    obj.addEdge(adj, 2, 1);
    obj.addEdge(adj, 2, 3);
    obj.addEdge(adj, 3, 2);


    obj.printGraph(adj);
    boolean ans = obj.isCycle(V,adj);
    System.out.println("Is the graph a cycle: " + ans);

  }
}
