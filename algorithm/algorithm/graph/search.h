//
//  search.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef search_h
#define search_h

#include "common.h"

struct node {
    int parent;
    int* neighbors;
};

struct _graph {
    size_t vertices;
    struct node* list;
};

struct _graph* make_sample_graph(size_t);
void destroy_(struct _graph*);
void print_graph(const struct _graph*);
void print_path(const struct _graph*, int);
void print_tree(const struct _graph*);
void dfs(struct _graph*, int);
void bfs(struct _graph*, int);
    
    
#endif /* search_h */
