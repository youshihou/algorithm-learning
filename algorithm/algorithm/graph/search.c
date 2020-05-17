//
//  search.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "search.h"

//typedef int Vertex;

#define VERTEX_NULL (-1)


void destroy_(struct _graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->list[i].neighbors);
    }
    free(g);
}

struct _graph* make_sample_graph(size_t n) {
    struct _graph* g = malloc(sizeof(*g));
    assert(g);
    
    g->vertices = n;
    g->list = malloc(sizeof(struct node) * n);
    assert(g->list);
    
    const int alloc_neighbors = 4;
    int i = 0;
    for (int j = 0; j < n; j++) {
        g->list[j].parent = VERTEX_NULL;
        
        g->list[j].neighbors = malloc(sizeof(int) * alloc_neighbors);
        i = 0;
        if (j % 2 == 0) {
            g->list[j].neighbors[i++] = j / 2;
        }
        if (3 * j < n) {
            g->list[j].neighbors[i++] = j * 3;
        }
        if (j + 1 < n) {
            g->list[j].neighbors[i++] = j + 1;
        }
        g->list[j].neighbors[i++] = VERTEX_NULL;
    }
    
    return g;
}

void print_graph(const struct _graph* g) {
    puts("digraph G {");
    for (int j = 0; j < g->vertices; j++) {
        for (size_t i = 0; g->list[j].neighbors[i] != VERTEX_NULL; i++) {
            printf("%d -> %d;\n", j, g->list[j].neighbors[i]);
        }
    }
    puts("}");
}

void print_path(const struct _graph* g, int u) {
    do {
        printf(" %d", u);
        u = g->list[u].parent;
    } while (g->list[u].parent != u);
}

void print_tree(const struct _graph* g) {
    puts("digraph G {");
    for (int i = 0; i < g->vertices; i++) {
        if (g->list[i].parent != VERTEX_NULL) {
            printf("%d -> %d;\n", i, g->list[i].parent);
        }
    }
    puts("}");
}

static void dfs_helper(struct _graph* g, int parent, int child) {
    int neighbor;
    if (g->list[child].parent == VERTEX_NULL) {
        g->list[child].parent = parent;
        for (int i = 0; (neighbor = g->list[child].neighbors[i]) != VERTEX_NULL; i++) {
            dfs_helper(g, child, neighbor);
        }
    }
}

void dfs(struct _graph* g, int root) {
    dfs_helper(g, root, root);
}

void bfs(struct _graph* g, int root) {
    int* q = malloc(sizeof(int) * g->vertices);
    assert(q);
    
    int head = 0;
    int tail = 0;
    
    g->list[root].parent = root;
    q[tail++] = root;
    
    int cur;
    int nbr;
    while (head < tail) {
        cur = q[head++];
        
        for (int i = 0; (nbr = g->list[cur].neighbors[i]) != VERTEX_NULL; i++) {
            if (g->list[nbr].parent == VERTEX_NULL) {
                g->list[nbr].parent = cur;
                q[tail++] = nbr;
            }
        }
    }
    free(q);
}
