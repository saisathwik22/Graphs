// leetcode 3203 HARD
class Solution {
    public Map<Integer, List<Integer>> buildAdjList(int[][] edges) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for(int[] edge : edges) {
            adjList.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adjList.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        return adjList;
    }
    public List<Integer> BFS(Map<Integer, List<Integer>> adjList, int srcNode) {
        Queue<Integer> q = new LinkedList<>();
        Map<Integer, Boolean> visited = new HashMap<>();
        q.add(srcNode);
        visited.put(srcNode, true);
        int maxDist = 0, farthestNode = srcNode;
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int currNode = q.poll();
                farthestNode = currNode;
                for(int v : adjList.getOrDefault(currNode, new ArrayList<>())){
                    if(!visited.getOrDefault(v, false)) {
                        visited.put(v, true);
                        q.add(v);
                    }
                }
            }
            if(!q.isEmpty()) {
                maxDist++;
            }
        }
        return Arrays.asList(farthestNode, maxDist);
    }
    public int findDiameter(Map<Integer, List<Integer>> adjList) {
        List<Integer> farthestNode = BFS(adjList, 0);
        farthestNode = BFS(adjList, farthestNode.get(0));
        return farthestNode.get(1);
    }
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        Map<Integer, List<Integer>> adj1 = buildAdjList(edges1);
        Map<Integer, List<Integer>> adj2 = buildAdjList(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1 + 1)/2 + (d2 + 1)/2 + 1;
        
        return Math.max(Math.max(d1, d2), combined);
    }
}
