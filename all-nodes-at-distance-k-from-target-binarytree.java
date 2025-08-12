// leetcode 863 - AMAZON

class Solution {
    Map<TreeNode, TreeNode> parent = new HashMap<>();

    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        if(root.left != null) {
            parent.put(root.left, root);
        }
        inOrder(root.left);
        if(root.right != null) {
            parent.put(root.right, root);
        }
        inOrder(root.right);
    }
    public void BFS(TreeNode target, int k, List<Integer> result) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(target);

        Set<Integer> visited = new HashSet<>();
        visited.add(target.val);
        int level = 0;
        while(!q.isEmpty()) {
            int n = q.size();
            if(k == 0) {
                break;
            }
            while(n-- > 0) {
                TreeNode curr = q.peek(); //q.front()
                q.poll();
                // left
                if(curr.left != null && !visited.contains(curr.left.val)) {
                    q.offer(curr.left);
                    visited.add(curr.left.val);
                }
                // right
                if(curr.right != null && !visited.contains(curr.right.val)) {
                    q.offer(curr.right);
                    visited.add(curr.right.val); //visited.insert()
                }
                //parent
                // parent.get(curr).val in JAVA ~ parent[curr]->val
                if(parent.containsKey(curr) && !visited.contains(parent.get(curr).val)) {
                    q.offer(parent.get(curr));
                    visited.add(parent.get(curr).val);
                }
            }
            k--;
        }
        while(!q.isEmpty()) {
            TreeNode temp = q.poll();
            result.add(temp.val);
        }
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<>();

        inOrder(root);

        BFS(target, k, result);

        return result;
    }
}
