// pure dijkstra
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new int[]{v, wt});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        int[] ans = new int[n + 1];
        Arrays.fill(ans, Integer.MAX_VALUE);
        ans[k] = 0;
        pq.offer(new int[]{0, k});
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0];
            int node = curr[1];
            for(int[] neighbour : adj.get(node)) {
                int adjNode = neighbour[0];
                int wt = neighbour[1];
                if(d + wt < ans[adjNode]) {
                    ans[adjNode] = d + wt;
                    pq.offer(new int[]{d + wt, adjNode});
                }
            }
        }
        int minTime = -1;
        for(int i = 1; i<=n; i++) {
            if(ans[i] == Integer.MAX_VALUE) return -1;
            minTime = Math.max(minTime, ans[i]);
        }
        return minTime;
    }
}
