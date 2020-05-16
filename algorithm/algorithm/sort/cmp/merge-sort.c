//
//  merge-sort.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "merge-sort.h"
#include "sort-common.h"

void merge(int* nums, int size, int begin, int mid, int end) {
    int li = 0; // CARE!!! is 0 not begin
    int le = mid - begin;
    int ri = mid;
    int re = end;
    int ai = begin; // CARE!!! is begin not 0
    
    int left[size >> 1];
    for (int i = li; i < le; i++) {
        left[i] = nums[begin + i]; // CARE!!! is begin + i not i
    }
    
    while (li < le) {
        if (ri < re && nums[ri] < left[li]) { // CARE!!! ri < re
            nums[ai++] = nums[ri++];
        } else {
            nums[ai++] = left[li++];
        }
    }
}

void sort(int* nums, int size, int begin, int end) {
    if (end - begin < 2) { return; }
    
    int mid = (begin + end) >> 1;
    sort(nums, size, begin, mid);
    sort(nums, size, mid, end);
    merge(nums, size, begin, mid, end);
}

void merge_sort(int* nums, int size) {
    if (nums == NULL || size <= 0) { return; }
    
    sort(nums, size, 0, size);
}
