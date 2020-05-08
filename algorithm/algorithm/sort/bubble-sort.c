//
//  bubble-sort.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "bubble-sort.h"
#include "sort-common.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int* bubble_sort(int* nums, int numSize) {
    if (nums == NULL || numSize <= 0) { return nums; }
    int* list = malloc(sizeof(int) * numSize);
    memset(list, 0, sizeof(int));
    
    for (int end = numSize - 1; end > 0; end--) {
        bool sorted = true;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin - 1]) {
                swap(&nums[begin], &nums[begin - 1]);
                sorted = false;
            }
        }
        if (sorted) { break; }
    }

    return list;
}


int* bubble_sort1(int* nums, int numSize) {
    if (nums == NULL || numSize <= 0) { return nums; }
    int* list = malloc(sizeof(int) * numSize);
    memset(list, 0, sizeof(int));
    
//    for (int end = numSize; end >= 0; end--) {
//        for (int begin = 1; begin < end; begin++) {
//            if (nums[begin] < nums[begin - 1]) {
//                swap(&nums[begin], &nums[begin - 1]);
//            }
//        }
//    }
    
    for (int end = numSize - 1; end > 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin - 1]) {
                swap(&nums[begin], &nums[begin - 1]);
            }
        }
    }

    return list;
}
