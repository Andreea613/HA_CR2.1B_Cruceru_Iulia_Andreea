#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class DFS {
private:
    void Dfs(int currentCity, int n, vector<vector<int>>& graph, vector<bool>& visited, int currentCost, int& minCost, vector<int>& path, vector<int>& bestPath) {
        if (path.size() == n) {
            if (graph[currentCity][0] > 0) {
                int totalCost = currentCost + graph[currentCity][0];
                if (totalCost < minCost) {
                    minCost = totalCost;
                    bestPath = path;
                }
            }
            return;
        }

       
        vector<pair<int, int>> nextCities;
        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (!visited[nextCity] && graph[currentCity][nextCity] > 0) {
                nextCities.push_back({ graph[currentCity][nextCity], nextCity });
            }
        }

   
        sort(nextCities.begin(), nextCities.end());

       
        for (const auto& nextCityPair : nextCities) {
            int cost = nextCityPair.first;
            int nextCity = nextCityPair.second;
            visited[nextCity] = true;
            path.push_back(nextCity);
            int newCost = currentCost + cost;
            Dfs(nextCity, n, graph, visited, newCost, minCost, path, bestPath);
            visited[nextCity] = false;
            path.pop_back();
        }
    }

public:
    pair<int, vector<int>> Dfs_tsp(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> path, bestPath;
        int minCost = INT_MAX;

        visited[0] = true;
        path.push_back(0);
        Dfs(0, n, graph, visited, 0, minCost, path, bestPath);

        bestPath.push_back(0);

        return make_pair(minCost, bestPath);
    }
};

