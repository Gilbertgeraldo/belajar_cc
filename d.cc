#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define INF 999;
int V, src,cost[100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];

void init() {
    for (int i = 0;i < V;i++) {
        parent[i] = i;
        dist[i] = INF;
        dist[src] = 0;
    }
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;
    for (int i = 0;i < V;i++) {
        if (!visited[i] && dist[i] < minValue) {
            minValue = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra() {
    for (int i = 0; i < V; i++) {
        int nearest = getNearest();
        visited[nearest] = true;

       for (int adj = 0;adj < V; adj++) {
        if (cost[nearest][adj] != INF && 
            dist[adj] > dist[nearest]+cost[nearest][adj]) {
            dist[adj] = dist[nearest]+cost[nearest][adj];
            parent[adj] = nearest;
        }
       }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    for (int i = 0;i < V;i++) {
        for (int j = 0;j < V;j++) {
            cin >> cost[i][j];
        }
    }
    cin >> src;
    init();
    dijkstra();
    return 0;
}