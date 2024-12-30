#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;  // Adjacency list to store the graph
    int V;  // Number of vertices in the graph

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adj.resize(V);  // Resize adjacency list to hold V vertices
    }

    // Function to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Add v to u's adjacency list
        adj[v].push_back(u);  // Add u to v's adjacency list (undirected graph)
    }

    // BFS function to perform breadth-first search starting from vertex s
    // The parent array is used to track the path
    void bfs(int s, int target) {
        vector<bool> visited(V, false);  // Vector to track visited vertices
        vector<int> parent(V, -1);  // Vector to store parent of each vertex
        queue<int> q;  // Queue to perform BFS
        visited[s] = true;  // Mark the starting vertex as visited
        q.push(s);  // Add the starting vertex to the queue

        // Perform BFS
        while (!q.empty()) {
            int u = q.front();  // Get the front element of the queue
            q.pop();  // Remove the element from the queue

            // If we have reached the target vertex, stop the search
            if (u == target) {
                break;
            }

            // Visit all adjacent vertices of u
            for (int v : adj[u]) {
                if (!visited[v]) {  // If the vertex v has not been visited
                    visited[v] = true;  // Mark it as visited
                    parent[v] = u;  // Set parent of v as u
                    q.push(v);  // Add v to the queue for further exploration
                }
            }
        }

        // Print the path from s to target
        printPath(s, target, parent);
    }

    // Function to print the path from start to target using the parent array
    void printPath(int start, int target, const vector<int>& parent) {
        if (parent[target] == -1) {  // If there's no path from start to target
            cout << "No path found from " << start << " to " << target << endl;
            return;
        }

        vector<int> path;  // Vector to store the path
        for (int v = target; v != start; v = parent[v]) {
            path.push_back(v);  // Add the current vertex to the path
        }
        path.push_back(start);  // Add the start vertex to the path

        // Print the path in reverse order
        cout << "Path from " << start << " to " << target << ": ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";  // Print each vertex in the path
        }
        cout << endl;
    }
};

int main() {
    int V = 6;  // Number of vertices in the graph
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Start BFS from vertex 0 to vertex 5
    g.bfs(0, 5);

    return 0;
}
