#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

class AStarTSP {
private:
    struct State {
        int cost;
        vector<int> path;
        set<int> visited;
        int currentCity;
        int heuristic;

        bool operator>(const State& other) const {
            return cost + heuristic > other.cost + other.heuristic;
        }
    };

    vector<vector<int>> graph;
    int N;
    vector<int> bestPath;

    int heuristic(int currentCity, const set<int>& visited) {
        int minDist = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (visited.find(i) == visited.end() && graph[currentCity][i] > 0) {
                minDist = min(minDist, graph[currentCity][i]);
            }
        }
        return minDist;
    }

public:
    AStarTSP(const vector<vector<int>>& distances) : graph(distances) {
        N = distances.size();
    }

    int aStarSearch() {
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({ 0, {0}, {0}, 0, heuristic(0, {0}) });

        int minCost = INT_MAX;

        while (!pq.empty()) {
            State state = pq.top();
            pq.pop();

            if (state.path.size() == N) {
                if (graph[state.currentCity][0] > 0) {
                    state.path.push_back(0);
                    int totalCost = state.cost + graph[state.currentCity][0];
                    if (totalCost < minCost) {
                        minCost = totalCost;
                        bestPath = state.path;
                    }
                }
                continue;
            }

            for (int nextCity = 0; nextCity < N; ++nextCity) {
                if (state.visited.find(nextCity) == state.visited.end() && graph[state.currentCity][nextCity] > 0) {
                    State new_state = state;
                    new_state.currentCity = nextCity;
                    new_state.visited.insert(nextCity);
                    new_state.path.push_back(nextCity);
                    new_state.cost = state.cost + graph[state.currentCity][nextCity];
                    new_state.heuristic = heuristic(nextCity, new_state.visited);

                    pq.push(new_state);
                }
            }
        }

        return minCost;
    }

    vector<int> getBestPath() const {
        return bestPath;
    }
};

