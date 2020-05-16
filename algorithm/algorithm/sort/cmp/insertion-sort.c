//
//  insertion-sort.c
//  algorithm
//
//  Created by Ankui on 5/9/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "insertion-sort.h"
#include "sort-common.h"
#include "binary-search.h"

int search_index(int* nums, int index) {
    if (nums == NULL || index <= 0) { return index; }
    
    int num = nums[index];
    int begin = 0;
    int end = index;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (num < nums[mid]) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    
    return begin;
}

void insert(int* nums, int begin, int insertIdx) {
    int num = nums[begin];
    for (int i = begin; i > insertIdx; i--) {
        nums[i] = nums[i - 1];
    }
    nums[insertIdx] = num;
}

void insertion_sort(int nums[], int numsSize) {
    if (nums == NULL || numsSize < 2) { return; }

    for (int begin = 1; begin < numsSize; begin++) {
        int insertIdx = search_index(nums, begin);
        insert(nums, begin, insertIdx);
    }
}


void insertion_sort3(int nums[], int numsSize) {
    if (nums == NULL || numsSize < 2) { return; }

    for (int begin = 1; begin < numsSize; begin++) {
        int insertIdx = search_index(nums, begin);
        int num = nums[begin];
        for (int i = begin; i > insertIdx; i--) { // CARE!!! is i > insertIdx not i > 0
            nums[i] = nums[i - 1]; // CARE!!! is i not begin
        }
        nums[insertIdx] = num;
    }
}


void insertion_sort2(int nums[], int numsSize) {
    if (nums == NULL || numsSize < 2) { return; }

    for (int begin = 1; begin < numsSize; begin++) {
        int cur = begin;
        int num = nums[cur];
        while (cur > 0 && cmp(&num, &nums[cur - 1]) < 0) {
            nums[cur] = nums[cur - 1];
            cur--;
        }
        nums[cur] = num;
    }
}


void insertion_sort1(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2) { return; }

    for (int begin = 1; begin < numsSize; begin++) {
        int cur = begin;
        while (cur > 0 && cmp(&nums[cur], &nums[cur - 1]) < 0) {
            swap(&nums[cur], &nums[cur - 1]);
            cur--;
        }
    }
}
