// find shortest weighted path between node 1 and n
// return an array where array[0] = shortest wt, and rest of elements are nodes along the path from 1 to n;
// FLIPKART, MICROSOFT
// BFS will not work because the edges are weighted
// Dijkstra will work.
// to obtain the nodes along the chosen path, create a parent array to store parent of each node corresponding to the distance[node]

// ************************************* JAVA *********************************************************************************
class Solution {
    public List<Integer> shortestPath(int n, int m, int edges[][]) {
        //  Code Here.
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new int[]{v, wt});
            adj.get(v).add(new int[]{u, wt});
        }
        
        int[] distance = new int[n + 1];
        int[] parent = new int[n + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        distance[1] = 0;
        pq.offer(new int[]{0, 1});
        
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[1];
            int d = curr[0];
            for(int[] neighbour : adj.get(node)) {
                int adjNode = neighbour[0];
                int dist = neighbour[1];
                
                if(d + dist < distance[adjNode]) {
                    distance[adjNode] = d + dist;
                    pq.offer(new int[]{d + dist, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(distance[n] == Integer.MAX_VALUE) {
            return Arrays.asList(-1);
        }
        List<Integer> path = new ArrayList<>();
        int destNode = n;
        while(parent[destNode] != destNode) {
            path.add(destNode);
            destNode = parent[destNode];
        }
        path.add(1);
        path.add(distance[n]);
        Collections.reverse(path);
        
        return path;
    }
}
// ************************************* C++ **********************************************************************************
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<vector<int>>> adj(n + 1);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n+1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        distance[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[node]) {
                int adjNode = it[0];
                int dist = it[1];
                if(d + dist < distance[adjNode]) {
                    distance[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        int destNode = n;
        if(distance[n] == INT_MAX) {
            return {-1};
        }
        vector<int> path;
        while(parent[destNode] != destNode) {
            path.push_back(destNode);
            destNode = parent[destNode];
        }
        path.push_back(1);
        path.push_back(distance[n]);
        
        reverse(path.begin(), path.end());
        
        return path;
    }
};
