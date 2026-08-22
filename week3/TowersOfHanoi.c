#include <stdio.h>
typedef struct {
    int discs[50];   
    int top;          
} Stack;
void push(Stack *s, int value) {
    s->discs[++(s->top)] = value;   
}
int pop(Stack *s) {
    return s->discs[(s->top)--];    
}
int peek(Stack *s) {
    return s->discs[s->top];
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void moveDiscs(Stack *src, Stack *dest, char srcName, char destName) {
    if (isEmpty(src)) {
        int disc = pop(dest);
        push(src, disc);
        printf("Move disc %d from %c to %c\n", disc, destName, srcName);
    }
    else if (isEmpty(dest)) {
        int disc = pop(src);
        push(dest, disc);
        printf("Move disc %d from %c to %c\n", disc, srcName, destName);
    }
    else if (peek(src) > peek(dest)) {
        int disc = pop(dest);
        push(src, disc);
        printf("Move disc %d from %c to %c\n", disc, destName, srcName);
    }
    else {
        int disc = pop(src);
        push(dest, disc);
        printf("Move disc %d from %c to %c\n", disc, srcName, destName);
    }
}
void towerOfHanoiIterative(int n) {
    Stack src = { .top = -1 };
    Stack aux = { .top = -1 };
    Stack dest = { .top = -1 };
    int totalMoves = (1 << n) - 1;
    for (int i = n; i >= 1; i--)
        push(&src, i);
    Stack temp;
    if (n % 2 == 0) {
        temp = aux;
        aux = dest;
        dest = temp;
    }
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDiscs(&src, &dest, 'S', 'D');
        else if (i % 3 == 2)
            moveDiscs(&src, &aux, 'S', 'A');
        else
            moveDiscs(&aux, &dest, 'A', 'D');
    }
}
int main() {
    int n ;
    printf("enter the num of discs:\n");
    scanf("%d",&n);
    towerOfHanoiIterative(n);
    return 0;
}