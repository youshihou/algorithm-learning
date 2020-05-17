//
//  quick_union.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_union.h"

void quick_union_create(int* parents, int capacity) {
    if (capacity <= 0) {
        printf("capacity must be >= 1.");
        return;
    }
    
    for (int i = 0; i < capacity; i++) {
        parents[i] = i;
    }
}

void quick_union_range_check(int capacity, int value) {
    if (value < 0 || value >= capacity) {
        printf("value is out of bounds.");
    }
}

int quick_union_find(int* parents, int capacity, int value) {
    quick_union_range_check(capacity, value);
    
    while (value != parents[value]) {
        value = parents[value];
    }
    
    return value;
}

void quick_union_union(int* parents, int capacity, int v1, int v2) {
    int p1 = quick_union_find(parents, capacity, v1);
    int p2 = quick_union_find(parents, capacity, v2);
    if (p1 == p2) { return; }
    
    parents[p1] = p2;
}

bool quick_union_is_same(int* parents, int capacity, int v1, int v2) {
    return quick_union_find(parents, capacity, v1) == quick_union_find(parents, capacity, v2);
}
