class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> edgesList(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++) {
            edgesList[edges[i][0]].push_back(edges[i][1]);
            edgesList[edges[i][1]].push_back(edges[i][0]);
        }  
        stack<int> dfs;
        dfs.push(source);
        visited[source] = true;
        while(!dfs.empty()) {
            int edge = dfs.top();
            dfs.pop();
            if(edge == destination)
                return true;
            for(const int& e : edgesList[edge]) {
                if(visited[e]) continue;
                visited[e] = true;
                dfs.push(e);
            }
        }
        return false;
    }
};