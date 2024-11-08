#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


typedef struct {
    int items[MAX];
    int front, rear;
} Queue;


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
}


int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; 
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1; 
    } else {
        q->front++;
    }
    return item;
}


void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};


    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

   
    bfs(graph, visited, start, n);

    return 0;
}

