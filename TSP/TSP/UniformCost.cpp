#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

class UniformCostSearchTSP {
private:
    struct State {
        int cost;
        vector<int> path;
        unordered_set<int> visited;
        int currentCity;

        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

public:
    int uniformCostSearch(const vector<vector<int>>& graph, int N, vector<int>& bestPath) {
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({ 0, {0}, {0}, 0 }); 

        int minCost = INT_MAX;

        while (!pq.empty()) {
            State state = pq.top();
            pq.pop();

            
            if (state.path.size() == N) {
                if (graph[state.currentCity][0] > 0) {
                    int totalCost = state.cost + graph[state.currentCity][0];
                    if (totalCost < minCost) {
                        minCost = totalCost;
                        bestPath = state.path;
                        bestPath.push_back(0); 
                    }
                }
                continue;
            }

         
            for (int nextCity = 0; nextCity < N; ++nextCity) {
                if (state.visited.find(nextCity) == state.visited.end() && graph[state.currentCity][nextCity] > 0) {
                    State new_state;
                    new_state.cost = state.cost + graph[state.currentCity][nextCity];
                    new_state.path = state.path;
                    new_state.path.push_back(nextCity);
                    new_state.visited = state.visited;
                    new_state.visited.insert(nextCity);
                    new_state.currentCity = nextCity;

                    pq.push(new_state);
                }
            }
        }

        return minCost;
    }
};

