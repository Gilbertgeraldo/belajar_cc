#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

    void dfsHelper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << char(u + 'A') << " ";

        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] == 1 && !visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

public:
    Graph(int vertices) : numVertices(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

    // Menambahkan edge (sisi)
    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        if (!directed) {
            adjMatrix[v][u] = 1;
        }
    }

    void BFS(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Hasil BFS: ";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << char(curr + 'A') << " ";
            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                if (adjMatrix[curr][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    void DFS(int start) {
        vector<bool> visited(numVertices, false);
        cout << "Hasil DFS: ";
        dfsHelper(start, visited);
        cout << "\n";
    }

    void display() {
        cout << "Adjacency Matrix:\n   ";
        for (int i = 0; i < numVertices; i++) {
            cout << char(i + 'A') << " ";
        }
        cout << "\n";

        for (int i = 0; i < numVertices; i++) {
            cout << char(i + 'A') << ": ";
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.display();
    cout << "\n";

    g.BFS(0);
    g.DFS(0);

    return 0;
}