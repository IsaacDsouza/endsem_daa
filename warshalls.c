#include <stdio.h>

#define MAX_VERTICES 100

void warshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }
}

void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Transitive Closure:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    warshall(graph, n);

    printGraph(graph, n);

    return 0;
}

