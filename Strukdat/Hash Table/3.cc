#include<bits/stdc++.h>
using namespace std;

vector<int> adj[6];

void dfs(int start){
    bool vis[6] = {};
    stack<int> st;

    st.push(start);

    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(vis[u]) continue;
        vis[u] = true;

        cout << u << " ";
        for(int v : adj[u]){
            if(!vis[v]){
                st.push(v);
            }
        }
    }
}

void bfs(int start){
    bool vis[6] = {};
    queue<int> qu;

    qu.push(start);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        if(vis[u]) continue;
        vis[u] = true;

        cout << u << " ";
        for(int v : adj[u]){
            if(!vis[v]){
                qu.push(v);
            }
        } 
    }
}

