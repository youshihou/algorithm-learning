//
//  counting_sort.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "counting_sort.h"
#include "sort-common.h"

void counting_sort(int nums[], int size) {
    if (nums == NULL || size <= 0) { return; }
    
    int max = nums[0];
    int min = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    
    int countSize = max - min + 1;
    int counts[countSize];
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < size; i++) {
        counts[nums[i] - min]++;
    }
    
    for (int i = 1; i < countSize; i++) {
        counts[i] += counts[i - 1];
    }
    
    
    int list[size];
    // from right to left, make sure stability
    for (int i = size - 1; i >= 0; i--) {
        list[--counts[nums[i] - min]] = nums[i]; // CARE!!!
    }
    
    
    for (int i = 0; i < size; i++) {
        nums[i] = list[i];
    }
}


void counting_sort1(int nums[], int size) {
    if (nums == NULL || size <= 0) { return; }
    
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    int countSize = max + 1;
    int counts[countSize];
    memset(counts, 0, sizeof(counts));
    
    for (int i = 0; i < size; i++) {
        counts[nums[i]]++;
    }
    
    int idx = 0;
    for (int i = 0; i < countSize; i++) {
        while (counts[i]-- > 0) {
            nums[idx++] = i;
        }
    }
}
