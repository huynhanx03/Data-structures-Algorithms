#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;  // Adjacency list to store the graph
    int V;  // Number of vertices in the graph

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adj.resize(V);  // Resize the adjacency list to hold V vertices
    }

    // Function to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Add v to u's adjacency list
        adj[v].push_back(u);  // Add u to v's adjacency list (undirected graph)
    }

    // DFS function to perform depth-first search starting from vertex u
    // The parent array helps in tracking the path taken
    void dfs(int u, vector<bool>& visited, vector<int>& parent) {
        visited[u] = true;  // Mark the current node as visited
        
        // Visit all adjacent vertices of u
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;  // Set parent of v as u
                dfs(v, visited, parent);  // Recursively call dfs on v
            }
        }
    }

    // Function to print the path from the starting vertex to the current vertex
    void printPath(int start, int end, vector<int>& parent) {
        if (end == -1) {
            cout << "No path found from " << start << " to " << end << endl;
            return;
        }
        
        vector<int> path;
        for (int v = end; v != start; v = parent[v]) {
            path.push_back(v);  // Add the current vertex to the path
        }
        path.push_back(start);  // Add the start vertex to the path
        
        // Print the path in reverse order
        cout << "Path from " << start << " to " << end << ": ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";  // Print each vertex in the path
        }
        cout << endl;
    }

    // Wrapper function to start DFS from any vertex and print the path
    void startDFS(int start, int end) {
        vector<bool> visited(V, false);  // Create a visited array for all vertices
        vector<int> parent(V, -1);  // Initialize parent array with -1
        
        // Perform DFS starting from the 'start' vertex
        dfs(start, visited, parent);
        
        // Print the path from start to end
        printPath(start, end, parent);
    }
};

int main() {
    int V = 5;  // Number of vertices in the graph
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Start DFS from vertex 0 to vertex 4
    g.startDFS(0, 4);

    return 0;
}
