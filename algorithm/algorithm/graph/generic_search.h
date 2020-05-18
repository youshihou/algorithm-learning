//
//  generic_search.h
//  algorithm
//
//  Created by Ankui on 5/18/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef generic_search_h
#define generic_search_h

#include "graph-common.h"
#include "graph.h"

struct info {
    struct graph* graph;
    int reached;
    int* preorder;
    int* time;
    int* parent;
    int* depth;
};

struct info* info_create(struct graph*);
void info_destroy(struct info*);
void _dfs(struct info*, int);
void _bfs(struct info*, int);


#endif /* generic_search_h */
