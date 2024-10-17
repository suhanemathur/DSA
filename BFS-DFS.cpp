#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

    // Helper function for DFS
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    // Function to add an edge
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        // Uncomment the next line for an undirected graph
        // adjList[dest].push_back(src);
    }

    // Function to perform DFS traversal
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    // Function to perform BFS traversal
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ":";
            for (auto v : adjList[i]) {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List:" << endl;
    g.printGraph();

    cout << "DFS starting from vertex 0:" << endl;
    g.DFS(0);

    cout << "BFS starting from vertex 0:" << endl;
    g.BFS(0);

    return 0;
}
