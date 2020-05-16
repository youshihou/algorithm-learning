//
//  radix_sort.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "radix_sort.h"
#include "sort-common.h"

void counting_sort_(int nums[], int size, int divider) {
    int counts[10] = {0};
    
    for (int i = 0; i < size; i++) {
        int idx = nums[i] / divider % 10;
        counts[idx]++;
    }
    
    for (int i = 1; i < 10; i++) {
        counts[i] += counts[i - 1];
    }
    
    int list[size];
    for (int i = size - 1; i >= 0; i--) {
        int idx = nums[i] / divider % 10;
        list[--counts[idx]] = nums[i];
    }
    
    for (int i = 0; i < size; i++) {
        nums[i] = list[i];
    }
}

void radix_sort(int nums[], int size) {
    if (nums == NULL || size <= 0) { return; }
    
    int max = nums[0];
    for (int i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    for (int divider = 1; divider <= max; divider *= 10) {
        counting_sort_(nums, size, divider);
    }
}
