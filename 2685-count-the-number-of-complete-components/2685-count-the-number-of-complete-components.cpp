class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            int vertex1 = edge[0];
            int vertex2 = edge[1];
            adjacencyList[vertex1].push_back(vertex2);
            adjacencyList[vertex2].push_back(vertex1);
        }
      
        vector<bool> visited(n, false);
      
    
        function<pair<int, int>(int)> dfs = [&](int currentVertex) -> pair<int, int> {
            visited[currentVertex] = true;
          
            int vertexCount = 1;
            int totalEdgeCount = adjacencyList[currentVertex].size();
          
            
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    auto [neighborVertices, neighborEdges] = dfs(neighbor);
                    vertexCount += neighborVertices;
                    totalEdgeCount += neighborEdges;
                }
            }
          
            return make_pair(vertexCount, totalEdgeCount);
        };
      
        int completeComponentCount = 0;
      
        for (int vertex = 0; vertex < n; ++vertex) {
            if (!visited[vertex]) {
                auto [componentVertices, componentEdges] = dfs(vertex);
              
               
                if (componentVertices * (componentVertices - 1) == componentEdges) {
                    ++completeComponentCount;
                }
            }
        }
      
        return completeComponentCount;
    }
};