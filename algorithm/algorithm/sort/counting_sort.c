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
