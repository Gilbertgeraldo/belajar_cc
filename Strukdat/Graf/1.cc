#include<bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;

void bfs(int start,vector<vector<int>>& graph){
    int n = graph.size();
    
    vector<bool> visited(n,false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << char(curr + 'A') << " ";
        for(int neighbor : graph[curr]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph(6);
    graph[0] = {2,1};
    graph[1] = {0,2,3};
    graph[2] = {0,1};
    graph[3] = {1,4,5};
    graph[4] = {3,5};
    graph[5] = {3,4};
    bfs(0, graph);
}