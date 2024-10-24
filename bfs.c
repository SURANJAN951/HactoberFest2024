#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int queue[MAX], front = -1, rear = -1;
int visited[MAX] = {0};  // Array to track visited vertices
int adjMatrix[MAX][MAX]; // Adjacency matrix to represent the graph

// Function to insert elements into the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to delete elements from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

// Function to perform BFS
void bfs(int startVertex, int numVertices) {
    int i;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int numVertices, i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    bfs(startVertex, numVertices);

    return 0;
}
