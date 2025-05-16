//leetcode 990
// **************************************** JAVA ***********************************************88
class Solution {
    int[] parent;
    int[] rank;
    public int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    public void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent != y_parent) {
            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            }
            else if(rank[x_parent] == rank[y_parent]) {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    }
    public boolean equationsPossible(String[] equations) {
        parent = new int[26];
        rank = new int[26];

        for(int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(String s : equations) {
            if(s.charAt(1) == '=') {
                int a = s.charAt(0) - 'a';
                int b = s.charAt(3) - 'a';
                Union(a, b);
            }
        }
        for(String s : equations) {
            if(s.charAt(1) == '!') {
                int a = s.charAt(0) - 'a';
                int b = s.charAt(3) - 'a';
                if(find(a) == find(b)) {
                    return false;
                }
            }
        }
        return true;
    }
}
// ***************************************** C++ *********************************************************************
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if(x_p != y_p) {
            if(rank[x_p] > rank[y_p]) {
                parent[y_p] = x_p;
            }
            else if(rank[x_p] < rank[y_p]) {
                parent[x_p] = y_p;
            }
            else if(rank[x_p] == rank[y_p]) {
                parent[x_p] = y_p;
                rank[y_p]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(string &s : equations) {
            if(s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }
        for(string &s : equations) {
            if(s[1] == '!') {
                if(find(s[0] - 'a') == find(s[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
