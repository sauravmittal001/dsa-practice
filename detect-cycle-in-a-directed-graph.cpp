class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> in_edges(V, 0);
        vector<vector<int> > out_edges(V, vector<int>());
        
        for (vector<int> v: edges) {
            int child = v[1];
            int parent = v[0];
            
            in_edges[parent]++;
            out_edges[child].push_back(parent);
        }
        
        priority_queue<int> pq; // using queue or stack will topo sort but with different ordering
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (in_edges[i] == 0) {
                pq.push(i);
                visited[i] = 1;
            }
        }
        
        vector<int> topo;
        
        while (!pq.empty()) {
            int parent = pq.top();
            pq.pop();
            topo.push_back(parent);
            
            for (int child: out_edges[parent]) {
                if (!visited[child]) {
                    if (--in_edges[child] == 0) {
                        pq.push(child);
                        visited[child] = 1;
                    }
                }
            }
            
        }
        
        return topo.size() != V;
    }
};
