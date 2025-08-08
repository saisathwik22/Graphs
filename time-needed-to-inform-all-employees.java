// leetcode 1376 - AMAZON

// DFS
class Solution {

    public int maxTime = 0;
    public void DFS(Map<Integer, List<Integer>> adj, int[] informTime, int curr_employee, int curr_time) {
        maxTime = Math.max(maxTime, curr_time);

        for(int employee : adj.get(curr_employee)) {
            DFS(adj, informTime, employee, curr_time + informTime[curr_employee]);
        }
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
        }
        for(int i = 0; i < manager.length; i++) {
            int employee_i = i;
            int manager_i = manager[i];

            if(manager_i != -1) {
                adj.computeIfAbsent(manager_i, k -> new ArrayList<>()).add(employee_i);
            }
        }

        DFS(adj, informTime, headID, 0);

        return maxTime;
    }
}

// BFS
class Solution {

    public int maxTime = 0;
    public void BFS(Map<Integer, List<Integer>> adj, int[] informTime, int curr_employee) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{curr_employee, 0});

        while(!q.isEmpty()) {
            int[] temp = q.poll();
            int curr_emp = temp[0];
            int curr_time = temp[1];

            maxTime = Math.max(maxTime, curr_time);

            for(int emp : adj.get(curr_emp)) {
                q.offer(new int[]{emp, curr_time + informTime[curr_emp]});
                // time at which 'v' will recieve the information
            }
        }
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
        }
        for(int i = 0; i < manager.length; i++) {
            int employee_i = i;
            int manager_i = manager[i];

            if(manager_i != -1) {
                adj.computeIfAbsent(manager_i, k -> new ArrayList<>()).add(employee_i);
            }
        }

        BFS(adj, informTime, headID);

        return maxTime;
    }
}
