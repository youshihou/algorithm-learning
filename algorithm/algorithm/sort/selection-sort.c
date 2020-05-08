//
//  selection-sort.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "selection-sort.h"
#include "sort-common.h"


int* selection_sort(int* nums, int numSize) {
    if (nums == NULL || numSize <= 0) { return nums; }
    int* list = malloc(sizeof(int) * numSize);
    memset(list, 0, sizeof(int));
    
    for (int end = numSize - 1; end > 0; end--) {
        int maxIndex = 0;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] >= nums[maxIndex]) {
                maxIndex = begin;
            }
        }
        swap(&nums[maxIndex], &nums[end]);
    }

    return list;
}
