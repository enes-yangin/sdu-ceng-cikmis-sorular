#include <stdio.h>
#include <stdlib.h>

// Define the Graph structure using an adjacency matrix.
// The matrix stores 0 (no edge) or 1 (edge exists) between vertices.
typedef struct {
    int numVertices;   // Number of vertices in the graph.
    int **adjMatrix;   // 2D array representing the adjacency matrix.
} Graph;

/*
 * createGraph: Creates a graph with the given number of vertices.
 * Explanation: This function allocates memory for the Graph structure and its
 * adjacency matrix, initializing all entries to 0 (indicating no edges).
 */
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix.
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize with 0 (no edge)
        }
    }
    return graph;
}

/*
 * addEdge: Adds an edge between two vertices in the graph.
 * Explanation: For an undirected graph, this function sets the value 1 at the
 * corresponding positions in the adjacency matrix for both (src, dest) and (dest, src).
 */
void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertex number.\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Because the graph is undirected.
}

/*
 * removeEdge: Removes an edge between two vertices in the graph.
 * Explanation: This function sets the corresponding entries in the adjacency matrix
 * to 0 for both (src, dest) and (dest, src), effectively removing the edge.
 */
void removeEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertex number.\n");
        return;
    }
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0; // Because the graph is undirected.
}

/*
 * printGraph: Prints the graph's adjacency matrix.
 * Explanation: This function iterates over the adjacency matrix and prints its values,
 * allowing visualization of the graph's connections.
 */
void printGraph(Graph* graph) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * freeGraph: Frees the memory allocated for the graph.
 * Explanation: This function deallocates the memory for each row of the adjacency matrix,
 * then frees the matrix itself and finally the Graph structure.
 */
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

/*
 * DFSUtil: Utility function for DFS traversal starting from a given vertex.
 * Explanation: This recursive function marks the current vertex as visited and
 * then recursively visits all adjacent unvisited vertices.
 */
void DFSUtil(Graph* graph, int vertex, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

/*
 * DFS: Performs a Depth-First Search traversal starting from the specified vertex.
 * Explanation: This function initializes the visited array and calls the DFSUtil
 * function to recursively traverse the graph.
 */
void DFS(Graph* graph, int startVertex) {
    int *visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

/*
 * BFS: Performs a Breadth-First Search traversal starting from the specified vertex.
 * Explanation: This function uses a simple queue (implemented as an array) to visit vertices
 * in a level order manner. It marks each vertex as visited once enqueued.
 */
void BFS(Graph* graph, int startVertex) {
    int *visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    int *queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue the starting vertex and mark it as visited.
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Enqueue all adjacent unvisited vertices.
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

// Main function to demonstrate the graph operations.
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Add edges to the graph.
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the current state of the graph.
    printGraph(graph);

    // Perform DFS and BFS traversals.
    DFS(graph, 0);
    BFS(graph, 0);

    // Remove an edge and print the graph again.
    printf("Removing edge between 1 and 4.\n");
    removeEdge(graph, 1, 4);
    printGraph(graph);

    // Free the graph memory.
    freeGraph(graph);

    return 0;
}
