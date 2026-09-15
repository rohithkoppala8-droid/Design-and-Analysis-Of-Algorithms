#include <stdio.h>
struct result {
    int min;
    int max;
};
struct result minmax(int arr[], int low, int high) {
    struct result res, left, right;
    if (low == high) {
        res.min = arr[low];
        res.max = arr[low];
        return res;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            res.min = arr[low];
            res.max = arr[high];
        } else {
            res.min = arr[high];
            res.max = arr[low];
        }
        return res;
    }
    int mid = (low + high) / 2;
    left = minmax(arr, low, mid);
    right = minmax(arr, mid + 1, high);
    res.min = (left.min < right.min) ? left.min : right.min;
    res.max = (left.max > right.max) ? left.max : right.max;
    return res;
}
int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct result final = minmax(arr, 0, n - 1);
    printf("Max: %d, Min: %d\n", final.max, final.min);
    return 0;
}
