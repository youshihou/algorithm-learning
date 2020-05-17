//
//  quick_union_rank_path_halving.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_union_rank_path_halving.h"

void quick_union_rank_path_halving_range_check(int capacity, int value) {
    if (value < 0 || value >= capacity) {
        printf("value is out of bounds.");
    }
}



void quick_union_rank_path_halving_create(int* parents, int capacity, int* ranks) {
    if (capacity <= 0) {
        printf("capacity must be >= 1.");
        return;
    }
    
    for (int i = 0; i < capacity; i++) {
        parents[i] = i;
    }
    
    for (int i = 0; i < capacity; i++) {
        ranks[i] = 1;
    }
}

int quick_union_rank_path_halving_find(int* parents, int capacity, int v) {
    quick_union_rank_path_halving_range_check(capacity, v);
    
    while (v != parents[v]) {
        parents[v] = parents[parents[v]];
        v = parents[v];
    }
    
    return v;
}

void quick_union_rank_path_halving_union(int* parents, int capacity, int* ranks, int v1, int v2) {
    int p1 = quick_union_rank_path_halving_find(parents, capacity, v1);
    int p2 = quick_union_rank_path_halving_find(parents, capacity, v2);
    if (p1 == p2) { return; }
    
    if (ranks[p1] < ranks[p2]) {
        parents[p1] = p2;
    } else if (ranks[p1] > ranks[p2]) {
        parents[p2] = p1;
    } else {
        parents[p1] = p2;
        ranks[p2] += 1; // CARE!!! is ranks[p2] not ranks[p1]
    }
}


bool quick_union_rank_path_halving_is_same(int* parents, int capacity, int v1, int v2) {
    return quick_union_rank_path_halving_find(parents, capacity, v1) == quick_union_rank_path_halving_find(parents, capacity, v2);
}
