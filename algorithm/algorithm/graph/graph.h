//
//  graph.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

struct successors {
    int d;
    int len;
    int is_sorted;
    int arr[];
};

struct graph {
    int vertices;
    int edges;
    struct successors *list[];
};


struct graph* create(int);
void destroy(struct graph*);
void add_edge(struct graph*, int, int);
int vertex_count(struct graph*);
int edge_count(struct graph*);
int out_degree(struct graph*, int);
int has_edge(struct graph*, int, int);
void foreach(struct graph*, int, void(*func)(struct graph*, int, int, void*), void*);


#endif /* graph_h */
