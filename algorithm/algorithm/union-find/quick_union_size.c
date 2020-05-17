//
//  quick_union_size.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_union_size.h"

void quick_union_size_range_check(int capacity, int value) {
    if (value < 0 || value >= capacity) {
        printf("value is out of bounds.");
    }
}



void quick_union_size_create(int* parents, int capacity, int* sizes) {
    if (capacity <= 0) {
        printf("capacity must be >= 1.");
        return;
    }
    
    for (int i = 0; i < capacity; i++) {
        parents[i] = i;
    }
    
    for (int i = 0; i < capacity; i++) {
        sizes[i] = 1;
    }
}

int quick_union_size_find(int* parents, int capacity, int value) {
    quick_union_size_range_check(capacity, value);
    
    while (value != parents[value]) {
        value = parents[value];
    }
    
    return value;
}

bool quick_union_size_is_same(int* parents, int capacity, int v1, int v2) {
    return quick_union_size_find(parents, capacity, v1) == quick_union_size_find(parents, capacity, v2);
}


void quick_union_size_union(int* parents, int capacity, int* sizes, int v1, int v2) {
    int p1 = quick_union_size_find(parents, capacity, v1);
    int p2 = quick_union_size_find(parents, capacity, v2);
    if (p1 == p2) { return; }
    
    if (sizes[p1] < sizes[p2]) {
        parents[p1] = p2;
        sizes[p2] += sizes[p1];
    } else {
        parents[p2] = p1;
        sizes[p1] += sizes[p2];
    }
}
