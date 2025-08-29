
#include <bits/stdc++.h>
using namespace std;

//------------------------BFS------------------
vector<int> bfs_order(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<int> order;
    vector<int> visited(n, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return order;

}

// ------------------------- DFS (recursive) ---------------
void dfs_rec_util(int u, const vector<vector<int>>& adj, vector<int>& visited, vector<int>& order) {
    visited[u] = 1;
    order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_rec_util(v, adj, visited, order);
        }
    }
}

vector<int> dfs_recursive(const vector<vector<int>>& adj, int start) {
    int n = (int)adj.size();
    vector<int> visited(n, 0), order;
    dfs_rec_util(start, adj, visited, order);
    return order;
}

// --------------- Shortest Path using BFS --------------------
vector <int> bfs_shortest_path(const vector<vector<int>>& adj, int start, int target) {
    int n = (int)adj.size();
    vector<int> visited(n, 0), parent(n, -1);
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) break;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    if (!visited[target]) return path;
    for (int cur = target; cur != -1; cur = parent[cur]) {
        path.push_back(cur);

    }

    reverse(path.begin(), path.end());
    return path;
}

// ---------------- Count Components ----------------
int count_components(const vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> visited(n, 0);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            visited[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return components;
}

// -------------- Cycle Detection (Undirected) -------------
bool dfs_cycle_util(int u, int parent, const vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs_cycle_util(v, u, adj, vis)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool has_cycle_undirected(const vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (dfs_cycle_util(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

// -------------- Main -------------------
int main() {
    int n = 7;
    vector<vector<int>> adj(n);
    auto add_edge = [&] (int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);

    };

    add_edge(0, 1);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(4, 5);
    add_edge(4, 6);

    // BFS order
    auto b = bfs_order(adj, 0);
    cout << "BFS: ";
    for (int X : b) cout << X << ' '; cout << '\n';
     
    // DFS (recursive)
    auto d = dfs_recursive(adj, 0);
    cout << "DFS(rec): ";
    for (int X : d) cout << X << ' '; cout << '\n';

    // Shortest path 0 -> 6
    auto path = bfs_shortest_path(adj, 0, 6);
    cout << "Shortest 0->6: ";
    for (int X : path) cout << X << ' '; cout << '\n';

    // Connected components
    cout << "Components: " << count_components(adj) << '\n';

    // Cycle Detection
    cout << "Has cycle? " << (has_cycle_undirected(adj) ? "Yes" : "No") << '\n';

    return 0;

}
