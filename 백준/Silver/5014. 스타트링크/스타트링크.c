#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int visited[MAX];

typedef struct {
    int floor;
    int count;
} Node;

typedef struct {
    Node data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int floor, int count) {
    q->data[q->rear].floor = floor;
    q->data[q->rear].count = count;
    q->rear++;
}

Node dequeue(Queue* q) {
    return q->data[q->front++];
}

int main() {
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    if (S == G) {
        printf("0\n");
        return 0;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, S, 0);
    visited[S] = 1;

    while (!isEmpty(&q)) {
        Node cur = dequeue(&q);

        // 위로 이동
        int up = cur.floor + U;
        if (U > 0 && up <= F && !visited[up]) {
            if (up == G) {
                printf("%d\n", cur.count + 1);
                return 0;
            }
            visited[up] = 1;
            enqueue(&q, up, cur.count + 1);
        }

        // 아래로 이동
        int down = cur.floor - D;
        if (D > 0 && down >= 1 && !visited[down]) {
            if (down == G) {
                printf("%d\n", cur.count + 1);
                return 0;
            }
            visited[down] = 1;
            enqueue(&q, down, cur.count + 1);
        }
    }

    printf("use the stairs\n");
    return 0;
}
