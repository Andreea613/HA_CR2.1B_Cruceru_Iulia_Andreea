#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <algorithm>
#include <random>
#include <ctime>
#include "Heuristic.cpp"
#include "UniformCost.cpp"
#include "Dfs.cpp"
#include "Random.cpp"

using namespace std;


int main() {
    
    int N1 = 8;
    int N2 = 10;
   
    vector<vector<int>> graph2 = Random:: generateRandomGraph(N2);

    vector<vector<int>> graph1 = {
        {0, 5, 0, 6, 0, 4, 0, 7},
        {5, 0, 2, 4, 3, 0, 0, 0},
        {0, 2, 0, 1, 0, 0, 0, 0},
        {6, 4, 1, 0, 7, 0, 0, 0},
        {0, 3, 0, 7, 0, 0, 6, 4},
        {4, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 6, 3, 0, 2},
        {7, 0, 0, 0, 4, 0, 2, 0},

    };
    
    
    vector<int> bestPath;
   
    
    cout << "Pentru primul exemplu: " << endl << endl;

    //DFS
    DFS dfs1;
    pair<int, vector<int>> result_Dfs1 = dfs1.Dfs_tsp(graph1);

    int costDfs1 = result_Dfs1.first;
    vector<int> pathDfs1 = result_Dfs1.second;

    cout << "Costul minim folosind Dfs: " << costDfs1 << endl;
    cout << "Traseul cel mai bun folosind Dfs: ";

    for (int city : pathDfs1) {
        cout << city << " ";
    }
    cout << endl;


    //UCS

    UniformCostSearchTSP ucs1;
    int costUcs1 = ucs1.uniformCostSearch(graph1, N1, bestPath);
   
    cout << "Costul minim folosind UCS: " << costUcs1 << endl;
    cout << "Traseul cel mai bun folosind UCS: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;
   
  
    
    // A* Search
    AStarTSP heur1(graph1);
    int min_cost_AStar1 = heur1.aStarSearch();

    cout << "Costul minim folosind A*: " << min_cost_AStar1 << endl;

    bestPath = heur1.getBestPath();
    cout << "Traseul cel mai bun folosind A*: ";
    for (int city : bestPath) {
        cout << city << " ";
    }


    cout << endl << endl;

    cout << "Pentru al doilea exemplu folosind un graf generat automat: " << endl << endl;

    for (size_t i = 0; i < graph2.size(); ++i) {
        for (size_t j = 0; j < graph2[i].size(); ++j) {
            cout << graph2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //DFS
    DFS dfs2;
    pair<int, vector<int>> result_Dfs2 = dfs2.Dfs_tsp(graph2);

    int costDfs2 = result_Dfs2.first;
    vector<int> pathDfs2 = result_Dfs2.second;

    cout << "Costul minim folosind Dfs: " << costDfs2 << endl;
    cout << "Traseul cel mai bun folosind Dfs: ";
    for (int city : pathDfs2) {
        cout << city << " ";
    }
    cout << endl;

    //UCS

    UniformCostSearchTSP ucs2;
    int costUcs2 = ucs2.uniformCostSearch(graph2, N2, bestPath);

    cout << "Costul minim folosind UCS: " << costUcs2 << endl;
    cout << "Traseul cel mai bun folosind UCS: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

 

    // A* Search
    AStarTSP heur2(graph2);
    int min_cost_AStar = heur2.aStarSearch();

    cout << "Costul minim folosind A*: " << min_cost_AStar << endl;

    bestPath = heur2.getBestPath();
    cout << "Traseul cel mai bun folosind A*: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    
    return 0;
}
