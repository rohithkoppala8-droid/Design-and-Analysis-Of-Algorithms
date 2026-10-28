
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};
struct Node *heap[MAX];
int size = 0;
struct Node* createNode(char ch, int freq) {
    struct Node *node = malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void swap(int i, int j) {
    struct Node *temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}
void insert(struct Node *node) {
    int i = size;
    heap[size++] = node;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent]->freq <= heap[i]->freq)
            break;
        swap(parent, i);
        i = parent;
    }
}
struct Node* extractMin() {
    struct Node *minNode = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < size &&
            heap[left]->freq < heap[smallest]->freq)
            smallest = left;
        if (right < size &&
            heap[right]->freq < heap[smallest]->freq)
            smallest = right;
        if (smallest == i)
            break;
        swap(i, smallest);
        i = smallest;
    }
    return minNode;
}
struct Node* buildHuffman(char chars[], int freq[], int n) {
    for (int i = 0; i < n; i++)
        insert(createNode(chars[i], freq[i]));
    while (size > 1) {
        struct Node *left = extractMin();
        struct Node *right = extractMin();
        struct Node *parent =
            createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        insert(parent);
    }
    return extractMin();
}
void printCodes(struct Node *root, int code[], int depth) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->ch);
        if (depth == 0)
            printf("0");
        for (int i = 0; i < depth; i++)
            printf("%d", code[i]);
        printf("\n");
        return;
    }
    code[depth] = 0;
    printCodes(root->left, code, depth + 1);
    code[depth] = 1;
    printCodes(root->right, code, depth + 1);
}
int main() {
    char chars[] = {'a', 'c', 'd', 'e', 'o',
                    'm', 's', 't', 'u'};
    int freq[] = {20, 11, 2, 10, 15,
                  8, 10, 22, 2};
    int n = sizeof(chars) / sizeof(chars[0]);
    struct Node *root = buildHuffman(chars, freq, n);
    int code[MAX];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);
    return 0;
}
