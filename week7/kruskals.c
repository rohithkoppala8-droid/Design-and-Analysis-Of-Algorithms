#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

void merge(struct Edge a[], int low, int mid, int high) {
    struct Edge temp[100];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i].w <= a[j].w)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(struct Edge a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int V, E;
    struct Edge edges[100];
    int i, count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (i = 0; i < V; i++)
        parent[i] = i;

    mergeSort(edges, 0, E - 1);

    printf("\nMinimum Spanning Tree:\n");

    for (i = 0; i < E && count < V - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("%d -- %d = %d\n",
                   edges[i].u, edges[i].v, edges[i].w);

            cost += edges[i].w;
            unionSet(edges[i].u, edges[i].v);
            count++;
        }
    }
    printf("Minimum Cost = %d\n", cost);
    return 0;
}