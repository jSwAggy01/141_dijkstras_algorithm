#include <iostream>
#include <vector>
#include <map>

// Compile with: g++ test.cpp -o test

using namespace std;

int main() {
    // List of edges in an adjacency list data structure
    map<int, vector<int>> edgeList = {
        {0, {1, 2, 3}},
        {1, {0, 4}},
        {2, {0, 4, 5}},
        {3, {0, 4}},
        {4, {1, 2, 3}},
        {5, {2}}
    };

    // Access and print the values in the map
    for (const auto& entry : edgeList) {
        int vertex = entry.first;                       // Access the key (vertex)
        const vector<int>& neighbors = entry.second;    // Access the value (vector of neighbors)

        cout << "Vertex " << vertex << ": ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    return 0;
}