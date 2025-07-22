// coordinates given,
// form adjacency list and apply prims algo
// find minimum spanning tree weight
// leetcode 1584
// asked by META

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
