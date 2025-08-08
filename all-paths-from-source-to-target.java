// leetcode 797
// microsoft, amazon
class Solution {
    void DFS(int[][] graph, int u, int target, List<List<Integer>> result, List<Integer> temp) {
        temp.add(u);

        if(u == target) {
            result.add(new ArrayList<>(temp));
        } else {
            for(int v : graph[u]) {
                DFS(graph, v, target, result, temp);
            }
        }
        temp.remove(temp.size() - 1);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;

        int source = 0;
        int target = n - 1;

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        DFS(graph, source, target, result, temp);

        return result;
    }
}
