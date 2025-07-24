// Disjoint Set Union - Union and find.
// FAANG & MAANG
// sets are said to be disjoint if their intersection is NULL
// every set has a parent, initially all nodes parents are itself, gradually parents change when we apply union.
// find() refers to algo to find the ultimate parent of a node.
// if find(a) == find(b) then a & b belong to same set.
// (a) and (b) are two nodes.
// union(a, b) == (a)--->(b), b is parent of a;
// parent array stores parents of all nodes.
// union(a, b) == (a)--->(b) means, parent[a] = b;

// *******************  JAVA ********************************************************
class DisjointSet {
    int[] parent;
    int[] rank;

    public DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];

        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Path Compression
    public int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]); // Recursively compress path
        }
        return parent[i];
    }

    // Union by Rank
    public void union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent) return; // Already in the same set

        if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        } else if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        } else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
}

// ***********************************  C++ *********************************************************
int find(int i, vector<int>& parent) {
  if(i == parent[i]) 
    return i;
  return find(parent[i], parent);
}

void union(int x, int y, vector<int>& parent) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);
  if(x_parent != y_parent) {
    parent[x_parent] = y_parent;
  }
}

// worst case we visit every node - O(n)
// optimization for union - using rank;
// optimization for find - using path compression.

// PATH COMPRESSION : 
// while we iterate over nodes to find ultimate parent of a node, when we find it, we return that node.
// while returing back from that node, make sure to assign the ultimate parent to every node along the return way.
int find(int i, vector<int>& parent) {
  if(i == parent[i])
    return i;
  return parent[i] = find(parent[i], parent);
}
// example: 6 --> 5 --> 4 --> 3 --> 0
// // we apply find(6) to find the ultimate parent of 6 which is 0;
// find(6) {
//   parent[6] = find(parent[6] = 5) {
//     parent[5] = find(parent[5] = 4) {
//       parent[4] = find(parent[4] = 3) {
//         parent[3] = find(parent[3] = 0) {
//           parent[0] = find(parent[0] = 0) {
//             0 == parent[0];
//             return 0;
//             now every parent[i] along the return way is assigned 0 as parent;
//           }
//         }
//       }
//     }
//   }
// }

// UNION - RANK :
// every node has inital rank as 0;
// when two nodes(a, b) are about to be merged and their ranks are equal, (a) ---> (b), parent[a] = b, and rank(b)++;

// Among two nodes a & b to be unioned, if their ranks are equal , then make any one of them parent of the other and increase its rank by 1;
// parent[a] = b; rank(b)++;
// if ranks are unequal then node with more rank is made parent.
// RANK equal agar hai tho, kisi ek ko parent bana dho aur uska rank++ kardo;
// RANK agar not equal hai tho, jiska rank jyada hai usko parent bana dho;

// if we assign parents according to RANKS, tree depth is minimal.
// Tree depth minimal, fast querying, fast union and find.

void unionRANK(int x, int y, vector<int>& parent, vector<int>& rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if(x_parent == y_parent) return;
  if(rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if(rank[x_parent] < ranl[y_parent]) {
    parent[x_parent] = y_parent;
  }
  else if(rank[x_parent] == rank[y_parent]) {
    parent[x_parent] = y_parent;
    rank[y_parent] += 1;
  }
}
