#include <stdio.h>
#include <stdlib.h>

// Adjacency Matrix Representation
#define MAX 10
int adjMatrix[MAX][MAX];
int visited[MAX];

// Adjacency List Representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Function prototypes
void BFSMatrix(int start, int vertices);
void DFSMatrix(int start, int vertices);
void BFSList(Graph* graph, int startVertex);
void DFSList(Graph* graph, int vertex);

// Adjacency List Functions
Node* createNode(int v);
Graph* createGraph(int vertices);
void addEdgeList(Graph* graph, int src, int dest);

int main() {
    int vertices, edges, i, j, src, dest, choice, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency matrix
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
    }

    // Adjacency List Graph
    Graph* graph = createGraph(vertices);
    for (i = 0; i < edges; i++) {
        addEdgeList(graph, src, dest);
        addEdgeList(graph, dest, src); // For undirected graph
    }

    printf("\nChoose traversal:\n");
    printf("1. BFS using Adjacency Matrix\n");
    printf("2. DFS using Adjacency Matrix\n");
    printf("3. BFS using Adjacency List\n");
    printf("4. DFS using Adjacency List\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Reset visited array
    for (i = 0; i < vertices; i++) visited[i] = 0;

    switch (choice) {
        case 1:
            BFSMatrix(start, vertices);
            break;
        case 2:
            DFSMatrix(start, vertices);
            break;
        case 3:
            for (i = 0; i < vertices; i++) graph->visited[i] = 0;
            BFSList(graph, start);
            break;
        case 4:
            for (i = 0; i < vertices; i++) graph->visited[i] = 0;
            DFSList(graph, start);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

// BFS for Adjacency Matrix
void BFSMatrix(int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    int i, curr;

    printf("BFS Traversal: ");
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        curr = queue[front++];
        printf("%d ", curr);

        for (i = 0; i < vertices; i++) {
            if (adjMatrix[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS for Adjacency Matrix
void DFSMatrix(int start, int vertices) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[start][i] && !visited[i]) {
            DFSMatrix(i, vertices);
        }
    }
}

// BFS for Adjacency List
void BFSList(Graph* graph, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    Node* temp;

    printf("BFS Traversal: ");
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS for Adjacency List
void DFSList(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFSList(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Adjacency List Helper Functions
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdgeList(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}