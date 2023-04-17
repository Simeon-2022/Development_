#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions_25.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

// Define a city struct
typedef struct city {
    char name[50];
} city;

// Define an edge struct
typedef struct edge {
    int weight;
    int to_vertex;
    struct edge* next;
} edge;

// Define a vertex struct
typedef struct vertex {
    city city_info;
    edge* edges;
} vertex;

// Define a graph struct
typedef struct graph {
    vertex vertices[MAX_CITIES];
    int num_vertices;
} graph;

// Function to add a new city to the graph
void add_city(graph* g, char* name) {
    if (g->num_vertices >= MAX_CITIES) {
        printf("Cannot add any more cities to the graph.\n");
        return;
    }

    // Create a new vertex for the city
    vertex new_vertex;
    strcpy(new_vertex.city_info.name, name);
    new_vertex.edges = NULL;

    // Add the vertex to the graph
    g->vertices[g->num_vertices++] = new_vertex;
}

// Function to add a new road between two cities
void add_road(graph* g, int from_vertex, int to_vertex, int weight) {
    if (from_vertex < 0 || from_vertex >= g->num_vertices || to_vertex < 0 || to_vertex >= g->num_vertices) {
        printf("Invalid vertex index.\n");
        return;
    }

    // Create a new edge for the road
    edge* new_edge = (edge*)malloc(sizeof(edge));
    new_edge->weight = weight;
    new_edge->to_vertex = to_vertex;
    new_edge->next = g->vertices[from_vertex].edges;

    // Add the edge to the source vertex
    g->vertices[from_vertex].edges = new_edge;
}

// Function to remove a city from the graph
void remove_city(graph* g, int vertex) {
    if (vertex < 0 || vertex >= g->num_vertices) {
        printf("Invalid vertex index.\n");
        return;
    }

    // Remove all edges to and from the vertex
    for (int i = 0; i < g->num_vertices; i++) {
        if (i == vertex) {
            continue;
        }

        edge* prev = NULL;
        edge* curr = g->vertices[i].edges;

        while (curr != NULL) {
            if (curr->to_vertex == vertex) {
                if (prev == NULL) {
                    g->vertices[i].edges = curr->next;
                }
                else {
                    prev->next = curr->next;
                }

                free(curr);
                curr = prev == NULL ? g->vertices[i].edges : prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Remove the vertex from the graph
    for (int i = vertex; i < g->num_vertices - 1; i++) {
        g->vertices[i] = g->vertices[i + 1];
    }

    g->num_vertices--;
}

void remove_road(graph *g, int from_vertex, int to_vertex) {
    if (g == NULL) {
        return;
    }

    vertex *from_v = from_vertex;
    vertex *to_v = to_vertex;

    if (from_v == NULL || to_v == NULL) {
        return;
    }


    // Find the edge between the two vertices
    edge *prev = NULL;
    edge *curr = from_v->edges;
    while (curr != NULL) {
        if (curr->to_vertex == to_vertex) {
            // Remove the edge
            if (prev == NULL) {
                from_v->edges = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}


int main(void) {

   
        graph g;
        g.num_vertices = 0;

        // Add two cities to the graph
        add_city(&g, "New York");
        add_city(&g, "Los Angeles");

        // Add a road between the two cities
        add_road(&g, 0, 1, 3000);

        // Remove the road between the two cities
        remove_road(&g, 0, 1);

        // Remove one of the cities
        remove_city(&g, 1);

        return 0;

}