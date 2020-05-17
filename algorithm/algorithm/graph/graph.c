//
//  graph.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "graph.h"
#include "graph-common.h"

struct graph* create(int n) {
    struct graph* g = malloc(sizeof(struct graph) + sizeof(struct successors *) * n);
    assert(g);
    
    g->vertices = n;
    g->edges = 0;
    
    for (int i = 0; i < n; i++) {
        g->list[i] = malloc(sizeof(struct successors));
        assert(g->list[i]);
        
        g->list[i]->d = 0;
        g->list[i]->len = 0;
        g->list[i]->is_sorted = 1;
    }
    
    return g;
}

void destroy(struct graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->list[i]);
    }
    free(g);
}

void add_edge(struct graph* g, int u, int v) {
    assert(u >= 0);
    assert(u < g->vertices);
    assert(v >= 0);
    assert(v < g->vertices);
    
    while (g->list[u]->d >= g->list[u]->len) {
        g->list[u]->len = (g->list[u]->len << 1) + 1;
        g->list[u] = realloc(g->list[u], sizeof(struct successors) + sizeof(int) * g->list[u]->len);
    }
    
    struct successors *s = g->list[u];
    s->arr[s->d++] = v;
    s->is_sorted = 0;
    
    g->edges++;
}


int vertex_count(struct graph* g) {
    return g->vertices;
}

int edge_count(struct graph* g) {
    return g->edges;
}

int out_degree(struct graph* g, int source) {
    assert(source >= 0);
    assert(source < g->vertices);
    
    return g->list[source]->d;
}


#define BSEARCH_THRESHOLD (10)
static int int_cmp(const void* a, const void* b) {
    return *((const int*)a) - *((const int*)b);
}

int has_edge(struct graph* g, int source, int sink) {
    assert(source >= 0);
    assert(source < g->vertices);
    assert(sink >= 0);
    assert(sink < g->vertices);
    
    if (out_degree(g, source) >= BSEARCH_THRESHOLD) {
        if (!g->list[source]->is_sorted) {
            qsort(g->list[source]->arr, g->list[source]->d, sizeof(int), int_cmp);
        }
        return bsearch(&sink, g->list[source]->arr, g->list[source]->d, sizeof(int), int_cmp) != 0;
        
    } else {
        for (int i = 0; i < g->list[source]->d; i++) {
            if (g->list[source]->arr[i] == sink) {
                return 1;
            }
        }
        return 0;
    }
}

void foreach(struct graph* g, int source, void(*func)(struct graph* g, int source, int sink, void* data), void* data) {
    assert(source >= 0);
    assert(source < g->vertices);
    
    for (int i = 0; i < g->list[source]->d; i++) {
        func(g, source, g->list[source]->arr[i], data);
    }
}
