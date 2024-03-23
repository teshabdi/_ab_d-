
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

// Vertex class
class Vertex {
public:
    int key;
    Vertex(int k) : key(k) {}
};

// Graph class
class Graph {
private:
    unordered_map<int, Vertex*> vertices;
    vector<vector<pair<int, int>>> adjList;
    int numOfEdges;

public:
    Graph() {
        numOfEdges = 0;
    }

    void addVertex(int vertKey) {
        Vertex* v = new Vertex(vertKey);
        vertices[vertKey] = v;
        vector<pair<int, int>> adj;
        adjList.push_back(adj);
    }

    void addEdge(int fromVert, int toVert) {
        addEdge(fromVert, toVert, 0);
    }

    void addEdge(int fromVert, int toVert, int weight) {
        adjList[fromVert].push_back(make_pair(toVert, weight));
        numOfEdges++;
    }

    Vertex* getVertex(int vertKey) {
        return vertices[vertKey];
    }

    vector<int> getVertices() {
        vector<int> vertKeys;
        for (auto it = vertices.begin(); it != vertices.end(); ++it) {
            vertKeys.push_back(it->first);
        }
        return vertKeys;
    }

    bool inGraph(int v) {
        return (vertices.find(v) != vertices.end());
    }

    void removeVertex(int v) {
        if (inGraph(v)) {
            vertices.erase(v);
            adjList[v].clear();
            for (auto& adj : adjList) {
                for (auto it = adj.begin(); it != adj.end(); ++it) {
                    if (it->first == v) {
                        adj.erase(it);
                        break;
                    }
                }
            }
        }
    }

    void removeEdge(pair<int, int> e) {
        int fromVert = e.first;
        int toVert = e.second;

        if (inGraph(fromVert) && inGraph(toVert)) {
            for (auto it = adjList[fromVert].begin(); it != adjList[fromVert].end(); ++it) {
                if (it->first == toVert) {
                    adjList[fromVert].erase(it);
                    numOfEdges--;
                    break;
                }
            }
        }
    }

    int numVertices() {
        return vertices.size();
    }

    int numEdges() {
        return numOfEdges;
    }

    void bfs(int startVertex) {
        unordered_map<int, bool> visited;
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it) {
                int adjVertex = it->first;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }

    void dfs(int startVertex) {
        unordered_map<int, bool> visited;
        stack<int> s;

        visited[startVertex] = true;
        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            cout << currentVertex << " ";
            s.pop();

            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); ++it) {
                int adjVertex = it->first;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    s.push(adjVertex);
                }
            }
        }
    }
};

// Example usage
int main() {
    Graph g;

    // Adding vertices
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    // Adding edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 1);

    // Testing various operations
    cout << "Vertices: ";
    vector<int> vertices = g.getVertices();
    for (int v : vertices) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Number of vertices: " << g.numVertices() << endl;
    cout << "Number of edges: " << g.numEdges() << endl;

    cout << "BFS traversal from vertex 1: ";
    g.bfs(1);
    cout << endl;

    cout << "DFS traversal from vertex 1: ";
    g.dfs(1);
    cout << endl;

    g.removeEdge(make_pair(1, 3));
    g.removeVertex(4);

    cout << "Updated number of vertices: " << g.numVertices() << endl;
    cout << "Updated number of edges: " << g.numEdges() << endl;

    return 0;
}

