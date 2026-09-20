#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int graph[100][100];
    int selected[100] = {0};
    int i, j, edges = 0;
    int u, v, min, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    selected[0] = 1;

    printf("\nMinimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INT_MAX;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] != 0 &&
                        graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -- %d = %d\n", u, v, min);

        cost += min;
        selected[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}