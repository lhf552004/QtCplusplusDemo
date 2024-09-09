#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjList; // Adjacency list to represent the graph

public:
    // Add an edge between two nodes
    void addEdge(int src, int dest);

    // Find the shortest path using BFS
    void findShortestPath(int start, int end);
    // Public getter to access the adjacency list for testing
    const std::unordered_map<int, std::vector<int>>& getAdjList() const {
        return adjList;
    }
};

#endif // GRAPH_H
