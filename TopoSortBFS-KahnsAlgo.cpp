// indegree : No. of incoming edges to a node.
// 1. put Nodes with indegree = 0 to queue
// 2. pop front node, visit neighbors of that node, indegree[neighbors]--
// 3. if indegree[neighbors] = 0, push to queue
// the popping order gives you the valid topo sort order.
// KAHN's Algorithm
// ********************************************** C++ *******************************************************
vector<int> KahnsAlgoTopoSort(int V, vector<vector<int>> edges) {
  vector<vector<int>> adj(V);
  for(auto &i : edges) {
    adj[i[0]].push_back(i[1]);
  }
  queue<int> q;
  vector<int> indegree(V, 0);
  for(int u = 0; u < V; u++) {
    for(int &v : adj[u]) {
      indegree[v]++;
    }
  }
  for(int i=0; i < V; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> ans;
  while(!q.empty()) {
    int u = q.front();
    ans.push_back(u);
    q.pop();
    for(int &v : adj[u]) {
      indegree[v]--;
      if(indegree[v] == 0) {
        q.push(v);
      }
    }
  }
  return ans;
}
// ************************************************* JAVA ****************************************************
class Solution {
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }
        int[] indegree = new int[V];
        for(int u = 0; u < V; u++ ){
            for(int v : adj.get(u)) {
                indegree[v]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < V; i++ ){
            if(indegree[i] == 0 ){
                q.offer(i);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        while(!q.isEmpty()) {
            int u = q.poll();
            ans.add(u);
            for(int v : adj.get(u)) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return ans;
    }
}
