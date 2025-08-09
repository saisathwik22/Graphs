// leetcode 133 - AMAZON, GOOGLE, META

class Solution {
    private Map<Node, Node> mp = new HashMap<>();
    private void DFS(Node node, Node clone_node) {
        for(Node n : node.neighbors) {
            if(!mp.containsKey(n)) {
                Node clone = new Node(n.val);
                mp.put(n, clone);
                clone_node.neighbors.add(clone); // add to current node's neighbors
                DFS(n, clone);
            } else {
                clone_node.neighbors.add(mp.get(n));
            }
        }
    }
    public Node cloneGraph(Node node) {
        if(node == null) {
            return null;
        }
        Node clone_node = new Node(node.val);
        mp.put(node, clone_node);
        DFS(node, clone_node);
        return clone_node;
    }
}

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null) return null;

        Map<Node, Node> mp = new HashMap<>();
        Queue<Node> q = new LinkedList<>();

        Node clone_node = new Node(node.val);
        mp.put(node, clone_node);
        q.offer(node);

        while(!q.isEmpty()) {
            Node curr = q.poll();

            for(Node n : curr.neighbors) {
                if(!mp.containsKey(n)) {
                    Node clone_neighbor = new Node(n.val);
                    mp.put(n, clone_neighbor);
                    q.offer(n);
                }
                mp.get(curr).neighbors.add(mp.get(n));
            }
        }
        return clone_node;
    }
}
