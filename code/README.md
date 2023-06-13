# Dijkstra's Algorithm

## Introduction
This project implements Dijkstra's algorithm for solving single-source and all-source shortest path problems. The algorithm is a greedy approach that finds the shortest paths from a given source vertex to all other vertices in a graph. This README provides an overview of the project, its background, implementation details, and the expected output.

## Background
Dijkstra's algorithm is widely used for finding the shortest paths in a graph. It operates on a graph G = (V, E, W), where V represents the vertices, E represents the edges, and W represents the weights associated with the edges. The algorithm works for both directed and undirected graphs but does not handle negative edge weights. The steps of the algorithm are as follows:

Initialize the source vertex with a distance of 0.
Select the vertex with the smallest distance from the set of vertices not yet processed.
Perform relaxation for all the edges connected to the selected vertex.
Update the distances of the vertices in the graph based on the relaxation step.
Repeat steps 2-4 until all vertices have been processed.

## Implementation
The implementation of Dijkstra's algorithm in this project utilizes the adjacency list data structure to optimize the runtime complexity. The program includes separate functions to print the predecessor list, the distance list, and the adjacency list for the graph and shortest path tree topology.

In the main function, a series of elementary tests are performed to ensure the correctness of the implemented algorithm. The adjacency list is constructed to represent the graph, and the edge weights are assigned accordingly. The algorithm initializes the predecessor list as empty and the distance list with all values set to infinity, indicating unknown distances.

The algorithm begins by retrieving the values from the first entry in the adjacency list and initializes the distance list for the directly connected edges to the source vertex. Then, it iterates through each element of the adjacency list, considering the neighbors of each vertex and performing relaxation for the corresponding edges.

After executing the algorithm, the program outputs the initial adjacency list, the shortest path tree topology, and the shortest paths to each vertex from the source.

## Usage
To run the program, follow these steps:

Compile the source code using a C++ compiler:

Copy code
g++ dijkstra.cpp -o dijkstra
Execute the compiled program:

bash
Copy code
./dijkstra
The program prompts the user to input the graph information, such as the number of vertices, the adjacency list representation, and the edge weights. After the algorithm execution, the program displays the predecessor list, the distance list, and the adjacency list.

## Example Output
Here's an example of the expected output:

Initial Adjacency List:
0 -> 1 2 3
1 -> 0 4
2 -> 0 4 5
3 -> 0 4
4 -> 1 2 3
5 -> 2

Shortest Path Tree Topology:
  0 -> -1
  1 -> 0
  2 -> 0
  3 -> 0
  4 -> 1
  5 -> 2

Shortest Paths:
  0 -> 0
  1 -> 3
  2 -> 2
  3 -> 2
  4 -> 4
  5 -> 4
  
This output is a short demo of the adjacency list representation of the graph, the shortest path tree topology (predecessor list), and the shortest paths (distance list) from the source vertex.

## Conclusion
Overall, it was fascinating to see Dijkstra’s algorithm being implemented using an adjacency list data structure and how the entire algorithm on paper and theory from lecture, worked in practice during the implementation.
