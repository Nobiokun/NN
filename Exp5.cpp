#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

void backtrack(int node, unordered_map<int, vector<pair<int, int>>>& graph, int n, vector<int>& path, vector<int>& bestPath, int& minCost, int currentCost, vector<int>& visited) {
    if (path.size() == n) {
        for (auto& edge : graph[path.back()]) {
            if (edge.first == path.front()) {
                currentCost += edge.second;
                break;
            }
        }
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = path;
        }
        return;
    }
    
    for (auto& edge : graph[node]) {
        if (visited[edge.first] == -1) {
            visited[edge.first] = 1;
            path.push_back(edge.first);
            backtrack(edge.first, graph, n, path, bestPath, minCost, currentCost + edge.second, visited);
            visited[edge.first] = -1;
            path.pop_back();
        }
    }
}

void solve() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    unordered_map<int, vector<pair<int, int>>> graph;
    cout << "Enter edges (src, dest, cost), enter -1 for src to stop:" << endl;

    while (true) {
        int src, dest, cost;
        cout << "Enter src: ";
        cin >> src;
        if (src == -1) break;
        
        cout << "Enter dest: ";
        cin >> dest;
        
        cout << "Enter cost: ";
        cin >> cost;
        
        graph[src].push_back({dest, cost});
        graph[dest].push_back({src, cost});
    }

    vector<int> path, bestPath;
    int minCost = INT_MAX;
    vector<int> visited(n, -1);
    visited[0] = 1;
    path.push_back(0);
    
    backtrack(0, graph, n, path, bestPath, minCost, 0, visited);

    cout << "Best path: ";
    for (auto node : bestPath) {
        cout << node << " ";
    }
    cout << bestPath.front() << endl;
    cout << "Minimum cost: " << minCost << endl;
}

int main() {
    solve();
    return 0;
}

