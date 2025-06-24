class DisjointUnionSet {
public:
    
    vector<int> rank;
    vector<int> parent;

    DisjointUnionSet(int n) {
        for (int i = 0; i <= n ;i++) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int par_u = findUPar(u);
        int par_v = findUPar(v);
        if (par_u == par_v) {
            return false;
        }
        if (rank[par_u] > rank[par_v]) {
            parent[par_u] = par_v;
        } else if (rank[par_u] < rank[par_v]) {
            parent[par_v] = par_u;
        } else if (rank[par_u] == rank[par_v]) {
            parent[par_u] = par_v;
            rank[par_v]++;
        } else {
            cout << "Code should not reach here!\n";
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointUnionSet union_set(edges.size());
        for (auto const &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if (!union_set.unionByRank(u, v)) {
                return edge;
            }
        }
        return {};
    }
};
