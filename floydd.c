#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V])
{
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd-Warshall algorithm for All-Pairs Shortest Paths
void floydWarshall(int graph[][V])
{
    int dist[V][V];

    // Initialize the solution matrix same as the input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[] matrix to store the shortest path between every pair of vertices
    for (int k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the solution matrix
    printSolution(dist);
}

int main()
{
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {{0, 4, INT_MAX, 5, INT_MAX},
                       {INT_MAX, 0, 1, INT_MAX, 6},
                       {2, INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 1, 0, 2},
                       {1, INT_MAX, INT_MAX, 4, 0}};

    // Call the Floyd-Warshall algorithm function
    floydWarshall(graph);

    return 0;
}
