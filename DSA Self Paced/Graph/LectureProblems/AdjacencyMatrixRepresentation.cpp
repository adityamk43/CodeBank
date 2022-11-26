/**
 * @file AdjacencyMatrixRepresentation.cpp
 * @author ADITYA BHARDWAJ
 * @brief
 * 
 * PROPERTIES OF ADJACENCY MATRIX REPRENTATION:
 * 
 * Space Required: ⊝(V X V)
 * 
 * Operations:
 *      Check if u and v are adjacent: ⊝(1)
 *      Find all vertices adjacent to u: ⊝(v)
 *      Find degree of u: ⊝(v)
 *      Add/Remove an Edge: ⊝(1)
 *      Add/Remove a Vertex: ⊝(v^2)
 *  
 * 
 *  ADJACENCY MATRIX OF UNDIRECTED GRAPH ARE SYMMETRIC
 * AND
 * ADJACENCY MATRIX OF DIRECTED GRAPH ARE NOT SYMMETRIC
 * 
 * THAT'S FOR OBVIOUS REASONS :)
 * 
 * *****If we have vertex value in the form of strings for example like city names then we can store them in hash tables or arrays and give them numeric values which can be used to access their names for respective numeric vertex integer values.
 * 
 * @version 0.1
 * @date 2022-11-26 02:40 PM
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjMatrix;
    int numVertices;

public:
    // Initialize the matrix to zero
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edges
    void addEdge(int i, int j)
    {
        if ((i >= 0 && i < numVertices) && (j >= 0 && j < numVertices))
        {
            adjMatrix[i][j] = true;
            adjMatrix[j][i] = true;
        }
        else
        {
            cout << "Enter a valid edge case" << endl;
        }
    }

    // Remove edges
    void removeEdge(int i, int j)
    {
        if ((i >= 0 && i < numVertices) && (j >= 0 && j < numVertices))
        {
            adjMatrix[i][j] = false;
            adjMatrix[j][i] = false;
        }

        else
        {
            cout << "Enter a valid edge case" << endl;
        }
    }

    // Print the martix
    void toString()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 3);

    g.toString();
}