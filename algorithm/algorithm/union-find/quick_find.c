//
//  quick_find.c
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_find.h"

void quick_find_create(int* parents, int capacity) {
    if (capacity <= 0) {
        printf("capacity must be >= 1.");
        return;
    }
    
    for (int i = 0; i < capacity; i++) {
        parents[i] = i;
    }
}

void quick_find_range_check(int capacity, int value) {
    if (value < 0 || value >= capacity) {
        printf("value is out of bounds.");
    }
}

int quick_find_find(int* parents, int capacity, int value) {
    quick_find_range_check(capacity, value);
    return parents[value];
}

void quick_find_union(int* parents, int capacity, int v1, int v2) {
    int p1 = quick_find_find(parents, capacity, v1);
    int p2 = quick_find_find(parents, capacity, v2);
    if (p1 == p2) { return; }
    
    for (int i = 0; i < capacity; i++) {
        if (parents[i] == p1) {
            parents[i] = p2;
        }
    }
}

bool quick_find_is_same(int* parents, int capacity, int v1, int v2) {
    return quick_find_find(parents, capacity, v1) == quick_find_find(parents, capacity, v2);
}
