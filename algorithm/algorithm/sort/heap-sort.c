//
//  heap_sort.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "heap_sort.h"
#include "sort-common.h"

void sift_down(int* nums, int numSize, int index) {
    int num = nums[index];
    int half = numSize >> 1;
    while (index < half) {
        int childIndex = (index << 1) + 1;
        int child = nums[childIndex];
        int rightIndex = childIndex + 1;
        if (rightIndex < numSize && cmp(&nums[rightIndex], &child) > 0) {
            child = nums[childIndex = rightIndex];
        }
        
        if (cmp(&num, &child) >= 0) { break; }
        
        nums[index] = child;
        index = childIndex;
    }
    nums[index] = num;
}


int* heap_sort(int* nums, int numSize) {
    if (nums == NULL || numSize < 2) { return nums; }
    int* list = malloc(sizeof(int) * numSize);
    memset(list, 0, sizeof(int));
    
    for (int i = (numSize >> 1) - 1; i >= 0; i--) {
        sift_down(nums, numSize, i);
    }

    while (numSize > 1) {
        swap(&nums[0], &nums[--numSize]);
        sift_down(nums, numSize, 0);
    }
    
    return list;
}
