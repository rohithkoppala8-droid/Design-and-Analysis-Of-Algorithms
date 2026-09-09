#include <stdio.h>
void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bucketSort(float arr[], int n)
{
    float bucket[n][n];
    int count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }
    for (int i = 0; i < n; i++)
    {
        insertionSort(bucket[i], count[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}
int main()
{
    float arr[] = {
        0.42, 0.32, 0.73, 0.25,
        0.52, 0.65, 0.12, 0.37
    };
    int n = 8;
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    return 0;
}