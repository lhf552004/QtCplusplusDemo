#include "graph.h"

// Add an edge between two nodes (undirected graph)
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // Since the graph is undirected
}

// Find the shortest path using BFS
void Graph::findShortestPath(int start, int end) {
    std::unordered_map<int, bool> visited;          // To track visited nodes
    std::unordered_map<int, int> predecessor;       // To store the predecessor of each node
    std::queue<int> queue;                          // Queue for BFS

    // Mark the start node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    // BFS loop
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        // Stop if we reach the end node
        if (current == end) {
            break;
        }

        // Visit all adjacent nodes of the current node
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                predecessor[neighbor] = current; // Track the predecessor for shortest path
                queue.push(neighbor);

                // Stop if we find the end node
                if (neighbor == end) {
                    break;
                }
            }
        }
    }

    // If the end node is not reachable
    if (!visited[end]) {
        std::cout << "No path exists between " << start << " and " << end << std::endl;
        return;
    }

    // Reconstruct the shortest path from end to start using predecessor
    std::vector<int> path;
    for (int at = end; at != start; at = predecessor[at]) {
        path.push_back(at);
    }
    path.push_back(start);

    // Print the shortest path
    std::cout << "Shortest path between " << start << " and " << end << " is: ";
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
