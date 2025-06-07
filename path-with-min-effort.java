// leetcode 1631 - GOOGLe
class Solution {
    int[][] directions = {
        {-1, 0}, {1,0}, {0, -1}, {0, 1}
    };
    public boolean isSafe(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    public int minimumEffortPath(int[][] heights) {
      int m = heights.length;
      int n = heights[0].length;

      int[][] result = new int[m][n];
      for(int i = 0; i < m; i++) {
        Arrays.fill(result[i], Integer.MAX_VALUE);
      }
      PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
      pq.offer(new int[]{0, 0, 0});
      result[0][0] = 0;

      while(!pq.isEmpty()) {
        int[] curr = pq.poll();
        int diff = curr[0];
        int x = curr[1];
        int y = curr[2];

        if(x == m-1 && y == n-1) return diff;
        for(int[] dir : directions) {
            int x_ = x + dir[0];
            int y_ = y + dir[1];

            if(isSafe(x_, y_, m, n)) {
                int newDiff = Math.max(diff, Math.abs(heights[x][y] - heights[x_][y_]));
                if(result[x_][y_] > newDiff) {
                    result[x_][y_] = newDiff;
                    pq.offer(new int[]{result[x_][y_], x_, y_});
                }
            }
        }
      }
      return result[m-1][n-1];
    }
}
