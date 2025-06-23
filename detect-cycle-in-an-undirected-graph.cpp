class Solution{
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int> > adj(V, vector<int>());
        for (vector<int> v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                continue;
            }
            queue<pair<int, int> > q;    // using a stack will traverse graph in a dfs way
            q.push(make_pair(i, -1));
            visited[i] = 1;
            while(!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();

                int node = p.first;
                int parent = p.second;

                for (int neighbour: adj[node]) {
                    if (visited[neighbour] == 1 && neighbour != parent) {
                        return true;
                    }
                    if (neighbour == parent) {
                        continue;
                    }
                    q.push(make_pair(neighbour, node));
                    visited[neighbour] = 1;
                }
            }
        }
        return false;
    }
};
