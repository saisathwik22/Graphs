// find min spanning tree weight
// PRIM's Algorithm
class Solution {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.offer(new int[]{0, 0});
        boolean[] inMST = new boolean[V];
        int sum = 0;
        
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int wt = curr[0];
            int node = curr[1];
            
            if(inMST[node] == true) {
                continue;
            }
            inMST[node] = true; //added to MST
            sum = sum + wt;
            
            for(int[] tmp : adj.get(node)) {
                int neighbour = tmp[0];
                int neighbour_wt = tmp[1];
                
                if(inMST[neighbour] == false) {
                    pq.offer(new int[]{neighbour_wt, neighbour});
                }
            }
        }
        return sum;
    }
}
// KRUSHKAL's Algorithm
class Solution {
    static int[] parent;
    static int[] rank;
    
    
    static int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    static void Union(int x, int y) {
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
    static int Krushkal(List<List<Integer>> vec) {
        int sum = 0;
        for(List<Integer> temp : vec) {
            int u = temp.get(0);
            int v = temp.get(1);
            int wt = temp.get(2);
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v) {
                Union(u, v);
                sum = sum + wt;
            }
        }
        return sum;
    }
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        parent = new int[V];
        rank = new int[V];
        for(int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        List<List<Integer>> vec = new ArrayList<>();
        
        for(int u = 0; u < V; u++) {
            for(int[] temp : adj.get(u)) {
                int v = temp[0];
                int wt = temp[1];
                vec.add(Arrays.asList(u, v, wt));
            }
        }
        
        vec.sort(new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> vec1, List<Integer> vec2) {
                return Integer.compare(vec1.get(2), vec2.get(2));
            }
        });
        
        return Krushkal(vec);
    }
}
