// find min spanning tree weight

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
