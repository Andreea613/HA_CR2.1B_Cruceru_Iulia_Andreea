#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
class Random {
public:
    static vector<vector<int>> generateRandomGraph(int N) {
        vector<vector<int>> graph(N, vector<int>(N, 0));

        srand(time(0));

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int distance = rand() % 100000 ; 
                graph[i][j] = graph[j][i] = distance;
            }
        }

        for (int i = 0; i < N; ++i) {
            graph[i][i] = 0;
        }

        return graph;
    }
};


