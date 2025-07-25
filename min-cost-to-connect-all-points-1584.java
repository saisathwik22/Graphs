// coordinates given,
// form adjacency list and apply prims algo
// find minimum spanning tree weight
// leetcode 1584
// asked by META

// PRIMS Algorithm
class Solution {
    public int PrimsAlgo(List<List<int[]>> adj, int V) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.offer(new int[]{0, 0});
        boolean[] inMST = new boolean[V];
        int sum = 0;
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int wt = curr[0];
            int node = curr[1];
            if(inMST[node] == true) continue;
            inMST[node] = true;
            sum = sum + wt;
            for(int[] x : adj.get(node)) {
                int n = x[0];
                int n_wt = x[1];
                if(inMST[n] == false) {
                    pq.offer(new int[]{n_wt, n});
                }
            }
        }
        return sum;
    }
    public int minCostConnectPoints(int[][] points) {
        int V = points.length;
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = Math.abs(x1 - x2) + Math.abs(y1 - y2);

                adj.get(i).add(new int[]{j, dist});
                adj.get(j).add(new int[]{i, dist});
            }
        }
        return PrimsAlgo(adj, V);
    }
}

// KRUSHKALs Algorithm
class Solution {
    public int[] parent;
    public int[] rank;
    public int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    public void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent) return;
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    public int Krushkal(List<List<Integer>> vec) {
        int sum = 0;
        for(List<Integer> temp : vec) {
            int u = temp.get(0);
            int v = temp.get(1);
            int d = temp.get(2);

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v) {
                Union(u, v);
                sum += d;
            }
        }
        return sum;
    }
    public int minCostConnectPoints(int[][] points) {
        int V = points.length;

        parent = new int[V];
        rank = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        List<List<Integer>> vec = new ArrayList<>();
        
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = Math.abs(x1-x2) + Math.abs(y1-y2);

                vec.add(Arrays.asList(i, j, d));
            }
        }
        vec.sort(new Comparator<List<Integer>>(){
            @Override
            public int compare(List<Integer> vec1, List<Integer> vec2) {
                return Integer.compare(vec1.get(2), vec2.get(2));
            }
        });

        return Krushkal(vec);
    }
}
