#include <stdio.h>
#include <stdlib.h>
#define v 10

int matrix[v][v];
int numVertices = 0;

void make(int matrix[][v], int numVertices) {
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void print(int matrix[][v], int numVertices) {
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int matrix[][v], int i, int j, int weight) {
    matrix[i][j] = weight;
    matrix[j][i] = weight;
}

void insert_vertex(int matrix[][v], int* numVertices) {
    if (*numVertices < v) {
        (*numVertices)++;
        make(matrix, *numVertices);
    } else {
        printf("Cannot add more vertices. The maximum limit is reached.\n");
    }
}

void delete_vertex(int matrix[][v], int* numVertices, int vertex) {
    if (vertex <= *numVertices) {
        for (int i = vertex; i < *numVertices; i++) {
            for (int j = 1; j <= *numVertices; j++) {
                matrix[i][j] = matrix[i + 1][j];
            }
        }
        for (int j = vertex; j < *numVertices; j++) {
            for (int i = 1; i <= *numVertices; i++) {
                matrix[i][j] = matrix[i][j + 1];
            }
        }
        (*numVertices)--;
    } else {
        printf("Vertex %d does not exist.\n", vertex);
    }
}

int main() {
    int choice, i, j, weight;;
    while (1) {
        printf("\nAdjacency matrix operation:\n");
        printf("1. Insert Vertex\n");
        printf("2. Delete Vertex\n");
        printf("3. Add Edge\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_vertex(matrix, &numVertices);
                break;
            case 2:
                printf("\nEnter the vertex to delete: ");
                int vertexToDelete;
                scanf("%d", &vertexToDelete);
                delete_vertex(matrix, &numVertices, vertexToDelete);
                printf("\nAdjacency matrix:\n");
                print(matrix, numVertices);
                break;
            case 3:
                
                printf("\nEnter the vertices to add an edge between (i and j) and the weight: ");
                scanf("%d %d %d", &i, &j, &weight);
                add_edge(matrix, i, j, weight);
                printf("\nAdjacency matrix:\n");
                print(matrix, numVertices);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
