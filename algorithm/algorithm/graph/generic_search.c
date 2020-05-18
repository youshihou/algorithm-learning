//
//  generic_search.c
//  algorithm
//
//  Created by Ankui on 5/18/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "generic_search.h"

#define SEARCH_INFO_NULL (-1)


static int* create_empty_list(int n) {
    int* a = malloc(sizeof(*a) * n);
    assert(a);
    
    for (int i = 0; i < n; i++) {
        a[i] = SEARCH_INFO_NULL;
    }
    
    return a;
}

struct info* info_create(struct graph* g) {
    struct info* s = malloc(sizeof(*s));
    assert(s);
    
    s->graph = g;
    s->reached = 0;
    
    int n = vertex_count(g);
    
    s->preorder = create_empty_list(n);
    s->time = create_empty_list(n);
    s->preorder = create_empty_list(n);
    s->depth = create_empty_list(n);
    
    return s;
}


void info_destroy(struct info* s) {
    free(s->depth);
    free(s->parent);
    free(s->time);
    free(s->preorder);
    free(s);
}



struct edge {
    int u;
    int v;
};

struct queue {
    struct edge* e;
    int bottom;
    int top;
};

static void push_edge(struct graph* g, int u, int v, void* data) {
    struct queue* q = data;
    assert(q->top < edge_count(g) + 1);
    
    q->e[q->top].u = u;
    q->e[q->top].v = v;
    q->top++;
}

static void generic_search(struct info* r, int root, int useQueue) {
    struct queue q;
    struct edge cur;
    
    q.e = malloc(sizeof(*q.e) * edge_count(r->graph) + 1);
    assert(q.e);
    
    q.bottom = q.top = 0;
    
    push_edge(r->graph, root, root, &q);
    
    while (q.bottom < q.top) {
        if (useQueue) {
            cur = q.e[q.bottom++];
        } else {
            cur = q.e[--q.top];
        }
        
        if (r->parent[cur.v] != SEARCH_INFO_NULL) {
            continue;
        }
        
        assert(r->reached < vertex_count(r->graph));
        r->parent[cur.v] = cur.u;
        r->time[cur.v] = r->reached;
        r->preorder[r->reached++] = cur.v;
        if (cur.u == cur.v) {
            r->depth[cur.v] = 0;
        } else {
            r->depth[cur.v] = r->depth[cur.u] + 1;
        }
        
        foreach(r->graph, cur.v, push_edge, &q);
    }
    
    free(q.e);
}

void _dfs(struct info* results, int root) {
    generic_search(results, root, 0);
}

void _bfs(struct info* results, int root) {
    generic_search(results, root, 1);
}




