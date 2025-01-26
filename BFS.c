#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct Edge {
    int destination;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    char name[10];
    Edge* edges;
} Node;

typedef struct Graph {
    Node nodes[MAX_NODES];
    int numNodes;
    bool directed;
} Graph;

Graph graph;

void addEdge(int src, int dest, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->destination = dest;
    edge->weight = weight;
    edge->next = graph.nodes[src].edges;
    graph.nodes[src].edges = edge;

    if (!graph.directed) {
        Edge* backEdge = (Edge*)malloc(sizeof(Edge));
        backEdge->destination = src;
        backEdge->weight = weight;
        backEdge->next = graph.nodes[dest].edges;
        graph.nodes[dest].edges = backEdge;
    }
}

int getNodeIndex(char* name) {
    for (int i = 0; i < graph.numNodes; i++) {
        if (strcmp(graph.nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void bfs(int start) {
    bool visited[MAX_NODES] = { false };
    int queue[MAX_NODES], front = -1, rear = -1;
    int totalWeight = 0;
    char traversalPath[MAX_NODES * 10];
    traversalPath[0] = '\0';

    visited[start] = true;
    queue[++rear] = start;

    while (front < rear) {
        front++;
        int currentNode = queue[front];
        
        if (traversalPath[0] != '\0') {
            strcat(traversalPath, " -> ");
        }
        strcat(traversalPath, graph.nodes[currentNode].name);

        Edge* edge = graph.nodes[currentNode].edges;
        while (edge) {
            if (!visited[edge->destination]) {
                visited[edge->destination] = true;
                queue[++rear] = edge->destination;
            }
            totalWeight += edge->weight;
            edge = edge->next;
        }
    }

    printf("BFS Traversal Path: %s\n", traversalPath);
    printf("Total Weight: %d\n", totalWeight);

    printf("Unreachable Nodes: ");
    bool hasUnreachable = false;
    for (int i = 0; i < graph.numNodes; i++) {
        if (!visited[i]) {
            printf("%s ", graph.nodes[i].name);
            hasUnreachable = true;
        }
    }
    if (!hasUnreachable) {
        printf("None");
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("graph.txt", "r");
    if (!file) {
        fprintf(stderr, "Could not open file graph.txt\n");
        return 1;
    }

    fscanf(file, "%d", &graph.numNodes);
    for (int i = 0; i < graph.numNodes; i++) {
        fscanf(file, "%s", graph.nodes[i].name);
        graph.nodes[i].edges = NULL;
    }

    char graphType[10];
    fscanf(file, "%s", graphType);
    graph.directed = (strcmp(graphType, "directed") == 0);

    char node1[10], node2[10];
    int weight;
    while (fscanf(file, "%s %s %d", node1, node2, &weight) != EOF) {
        int src = getNodeIndex(node1);
        int dest = getNodeIndex(node2);
        addEdge(src, dest, weight);
    }

    fclose(file);
    bfs(0);
    return 0;
}