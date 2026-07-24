#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct Edge {
    string to;
    int w;
};

struct NodePQ {
    int f_score;
    string name;

    bool operator>(const NodePQ& other) const {
        return f_score > other.f_score;
    }
};

void starSearch(
    unordered_map<string,vector<Edge>>& graph,
    unordered_map<string,int>& heuristic,
    string start,
    string goal
) {
    priority_queue<NodePQ,vector<NodePQ>,greater<NodePQ>> open_set;
    unordered_map<string,int> g_score;
    
    for (const auto& pair : heuristic) {
        g_score[pair.first] = INT_MAX;
    }
    g_score[start] = 0;

    unordered_map<string,string> came_from;

    open_set.push({0 + heuristic[start], start});

    while (!open_set.empty()) {
        string current = open_set.top().name;
        open_set.pop();

        if (current == goal) {
            vector<string> path;
            string temp = current;

            while(came_from.find(temp) != came_from.end()) {
                path.push_back(temp);
                temp = came_from[temp];
            }
            path.push_back(start);
            reverse(path.begin(),path.end());

            cout << "Result of A* Search in c++ : " << endl;
            cout << "Rute tercepat : " << endl; 
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i] << (i == path.size() - 1 ? "" : "->");
            }
            cout << "\nTotal jarak : " << g_score[goal] << "km" << endl;
            return;
        }

        for (const auto& edge : graph[current]) {
            int tentative_g_score = g_score[current] + edge.w;
            if (tentative_g_score < g_score[edge.to]) {
                came_from[edge.to] = current;
                g_score[edge.to] = tentative_g_score;
                int f_score = tentative_g_score + heuristic[edge.to];
                
                open_set.push({f_score, edge.to});
            }
        }
    }
    cout << "Jalur tidak ditemukan" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string,vector<Edge>> graph;
    graph["Start"] = {{"A", 2}, {"B", 5}};
    graph["A"]     = {{"Finish", 6}};
    graph["B"]     = {{"Finish", 2}};
    graph["Finish"] = {};

    unordered_map<string,int> heuristic = {
        {"Start", 7},
        {"A", 6},
        {"B", 2},
        {"Finish", 0}
    };

    starSearch(graph, heuristic, "Start", "Finish");
    return 0;
}