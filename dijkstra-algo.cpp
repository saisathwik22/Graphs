// DIJKSTRA's Algorithm - MICROSOFT, FLIPKART

// if given input is edges representing edges[i] = [u, v, wt];
// create adj list vector<vector<vector<int>>> adjList;
// adj[u].push_back({v, wt});
// adj[v].push_back({u, wt});

// use ordered set data structure
// helps us to erase a pair in the set midway through iterations using erase function.

// ****************************** JAVA ***********************************************
class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new int[]{v, wt});
            adj.get(v).add(new int[]{u, wt});
        }
        int[] result = new int[V];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[src] = 0;
        TreeSet<Pair> set = new TreeSet<>();
        set.add(new Pair(0, src));
        while(!set.isEmpty()) {
            Pair curr = set.pollFirst();
            int d = curr.dist;
            int node = curr.node;
            for(int[] neighbour : adj.get(node)) {
                int adjNode = neighbour[0];
                int dist = neighbour[1];
                if(d + dist < result[adjNode]) {
                    if(result[adjNode] != Integer.MAX_VALUE) {
                        set.remove(new Pair(result[adjNode], adjNode));
                    }
                    result[adjNode] = d + dist;
                    set.add(new Pair(d + dist, adjNode));
                }
            }
        }
        return result;
    }
    // custom class to represent pairs
     static class Pair implements Comparable<Pair> {
        int dist;
        int node;

        Pair(int dist, int node) {
            this.dist = dist;
            this.node = node;
        }

        public int compareTo(Pair other) {
            if (this.dist != other.dist) return Integer.compare(this.dist, other.dist);
            return Integer.compare(this.node, other.node);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return this.dist == p.dist && this.node == p.node;
        }

        @Override
        public int hashCode() {
            return Objects.hash(dist, node);
        }
    }
}
// ******************************** C++ **********************************************
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        set<pair<int, int>> st;
        vector<int> result(V, INT_MAX);
        vector<vector<vector<int>>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        result[src] = 0;
        st.insert({0, src});
        while(!st.empty()) {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);
            for(auto &vec : adj[node]) {
                int adjNode = vec[0];
                int dist = vec[1];
                if(d + dist < result[adjNode]) {
                    if(result[adjNode] != INT_MAX) {
                        st.erase({result[adjNode], adjNode});
                    }
                    result[adjNode] = d + dist;
                    st.insert({d + dist, adjNode});
                }
            }
        }
        return result;
    }
};

// use MinHEAP data structure;
// here data type is pair<int, int> - {distance from src to node, node};
// c++ for minHeap = priority_queue<pair, vector<pair>, greater<pair>> pq;
// java for minHeap = PriorityQueue<pair> minHeap = new PriorityQueue<>();

// ***************************** JAVA ****************************************
class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new int[]{v, wt});
            adj.get(v).add(new int[]{u, wt});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int[] result = new int[V];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[src] = 0;
        pq.offer(new int[]{0, src});
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0];
            int node = curr[1];
            for(int[] neighbour : adj.get(node)) {
                int adjNode = neighbour[0];
                int wt = neighbour[1];
                if(d + wt < result[adjNode]) {
                    result[adjNode] = d+wt;
                    pq.offer(new int[]{d + wt, adjNode});
                }
            }
        }
        return result;
    }
}
// ***************************** C++ ****************************************
// TC - O(e * logV)
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<vector<int>>> adj(V);
        // creating adj list
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);
        pq.push({0, src});
        result[src] = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec : adj[node]) {
                int adjNode = vec[0];
                int wt = vec[1];
                if(d + wt < result[adjNode])  {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        return result;
    }
