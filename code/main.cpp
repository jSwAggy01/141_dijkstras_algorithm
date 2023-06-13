#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <limits>

// Compile with: g++ main.cpp -o a

using namespace std;

/* Declarations */
void DijkstraShortestPath(map<int, vector<int>>, map<pair<int, int>, float>, vector<int>&, vector<float>&);
void printPredecessorList(const vector<int>&);
void printDistanceList(const vector<float>&);
void printAdjacencyList(const map<int, vector<int>>&);


int main() {
    const float INF = std::numeric_limits<float>::infinity();

    /* tests */
    cout << "Beginning tests...\n\n";
    {
        cout << "Initializing an edge list\n\n";
        map<int, std::vector<int>> edgeList = 
        {
            {0, {1, 2, 3}},
            {1, {0, 4}},
            {2, {0, 4, 5}},
            {3, {0, 4}},
            {4, {1, 2, 3}},
            {5, {2}}
        };

        cout << "Printing adjacency list" << "\n\n";
        printAdjacencyList(edgeList);

        cout << "\nInitializing edge weights\n\n";
        map<pair<int, int>, float> edgeWeights = 
        {
            {{0, 1}, 3},
            {{0, 2}, 2},
            {{0, 3}, 2},
            {{1, 0}, 3},
            {{1, 4}, 1},
            {{2, 0}, 2},
            {{2, 4}, 3},
            {{2, 5}, 2},
            {{3, 0}, 2},
            {{3, 4}, 1},
            {{4, 1}, 1},
            {{4, 2}, 1},
            {{4, 3}, 1},
            {{5, 2}, 2}
        };

        cout << "Initializing predecessor list\n\n";
        vector<int> predecessorList = {};

        // Assume all d(v) unknown by setting = INF
        cout << "Initializing distance list\n\n";
        vector<float> distanceList = {INF, INF, INF, INF, INF, INF};

        cout << "Calling Dijkstra function with the parameters\n\n";
        DijkstraShortestPath(edgeList, edgeWeights, predecessorList, distanceList);

        cout << "Printing shortest path tree topography\n\n";
        printPredecessorList(predecessorList);

        cout << "\nPrinting shortest path distance to each vertex\n\n";
        printDistanceList(distanceList);
    }   

    return 0;
}

/* Definitions */
void DijkstraShortestPath(map<int, vector<int>> adjacencyListEdges, map<pair<int, int>, float> edgeWeights, vector<int>& SPT_predecessorList, vector<float>& SPT_distanceList) {
    const float INF = std::numeric_limits<float>::infinity();
    vector<bool> selected(adjacencyListEdges.size(), false);

    /* INITIAL CONDITION: Sps. src = 1st vertex in list.
       Then, initialize d(s) = π = 0 AND d(v) = w(s, v), π(v) = s for all s — v
    */
    auto entry = adjacencyListEdges.begin();
    int currVertex = entry->first;
    const vector<int>& neighbors = entry->second;

    SPT_distanceList.at(currVertex) = 0;
    SPT_predecessorList.assign(adjacencyListEdges.size(), -1);
    SPT_predecessorList.at(currVertex) = currVertex;

    for (int neighbor : neighbors) {
        float weight = edgeWeights[{currVertex, neighbor}];
        SPT_distanceList.at(neighbor) = weight;
        SPT_predecessorList.at(neighbor) = currVertex;
    }

    /* Algorithm:
       (1) Mark starting vertex as selected
       (2) Select vertex with smallest d(v) from SPT_distanceList
       (3) Perform relaxation for all E(u,v)
       (4) Update d(v) in SPT_distanceList
       (5) Repeat from (2) for all vertices
    */
    selected[currVertex] = true;
    int numSelected = 1;

    while (numSelected < adjacencyListEdges.size()) {
        // Select vertex with smallest d(v) from SPT_distanceList
        float minDistance = INF;
        int minVertex = -1;

        for (int v = 0; v < adjacencyListEdges.size(); ++v) {
            if (!selected[v] && SPT_distanceList[v] < minDistance) {
                minDistance = SPT_distanceList[v];
                minVertex = v;
            }
        }

        if (minVertex == -1) {
            // No reachable vertices left
            break;
        }

        selected[minVertex] = true;
        ++numSelected;

        // Perform relaxation for all neighbors of minVertex
        const vector<int>& minVertexNeighbors = adjacencyListEdges[minVertex];

        for (int neighbor : minVertexNeighbors) {
            float weight = edgeWeights[{minVertex, neighbor}];
            float newDistance = SPT_distanceList[minVertex] + weight;

            if (newDistance < SPT_distanceList[neighbor]) {
                SPT_distanceList[neighbor] = newDistance;
                SPT_predecessorList[neighbor] = minVertex;
            }
        }
    }
}

void printPredecessorList(const vector<int>& SPT_predecessorList) {
    cout << "Predecessor List: ";
    for (int predecessor : SPT_predecessorList) {
        cout << predecessor << " ";
    }
    cout << endl;
}

void printDistanceList(const vector<float>& SPT_distanceList) {
    cout << "Distance List: ";
    for (float distance : SPT_distanceList) {
        cout << distance << " ";
    }
    cout << endl;
}

void printAdjacencyList(const map<int, vector<int>>& adjacencyListEdges) {
    cout << "Adjacency List:" << endl;
    for (const auto& entry : adjacencyListEdges) {
        int vertex = entry.first;
        const vector<int>& neighbors = entry.second;

        cout << vertex << " -> ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}