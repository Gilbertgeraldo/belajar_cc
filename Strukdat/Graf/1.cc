#include<bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;

// memakai vektor
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

//memakai queue(implementasi bread-first-search)
vector<int>adj[6];
void bfsq(int start){
    bool vis[6] = {};
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(auto neighbor : adj[temp]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

//memakai vektor
void dfs(int start,vector<vector<int>>& graph){
    int n = graph.size();

    vector<bool> vis(n,false);
    stack<int> st;

    vis[start] = true;
    st.push(start);

    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout << char(curr + 'A') << " ";
        for(auto neighbor : graph[curr]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}

//Implementasi dfs menggunakan stack
void dfst(int start){
    bool vis[6] = {};
    stack<int> st;

    vis[start] = true;
    st.push(start);

    while(!st.empty()){
        int temp = st.top();
        st.pop();
        for(auto neigh : adj[temp]){
            if(!vis[neigh]){
                vis[neigh] = true;
                st.push(neigh);
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
    cout << endl;
    bfsq(0);
    cout << endl;
    dfs(0,graph);
    cout << endl;
    dfst(0);
    return 0;
}