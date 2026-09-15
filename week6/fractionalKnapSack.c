#include <stdio.h>
struct Item {
    int profit;
    int weight;
    float ratio;
};
int main() {
    int n, W, i, j;
    float totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (W >= item[i].weight) {
            W -= item[i].weight;
            totalProfit += item[i].profit;
        } else {
            totalProfit += item[i].ratio * W;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}