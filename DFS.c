#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX], stack[MAX];
int vertices, top = -1;
bool visited[MAX];

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

bool isEmpty() {
    return top == -1;
}

void initialize() {
    top = -1;
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }
}

void depthFirstSearch(int start) {
    push(start);
    visited[start] = true;

    while (!isEmpty()) {
        int current = pop();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    initialize();
    depthFirstSearch(start);

    return 0;
}
