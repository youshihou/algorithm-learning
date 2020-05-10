//
//  binary-search.c
//  algorithm
//
//  Created by Ankui on 5/10/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "binary-search.h"
#include "sort-common.h"

int index_of(int *nums, int numsSize, int num) {
    if (nums == NULL || numsSize <= 0) { return -1; }
    
    int begin = 0;
    int end = numsSize;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        int res = cmp(&num, &nums[mid]);
        if (res > 0) {
            begin = mid + 1;
        } else if (res < 0) {
            end = mid;
        } else {
            return mid;
        }
    }

    return -1;
}


int index_of2(int *nums, int numsSize, int num) {
    if (nums == NULL || numsSize <= 0) { return -1; }
    
    int begin = 0;
    int end = numsSize;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (num > nums[mid]) {
            begin = mid + 1;
        } else if (num < nums[mid]) {
            end = mid;
        } else {
            return mid;
        }
    }
    
    return -1;
}


int index_of1(int *nums, int numsSize, int num) {
    if (nums == NULL || numsSize <= 0) { return -1; }
    
    int begin = 0;
    int end = numsSize;
    for (int i = begin; i < numsSize; i++) {
        int mid = (begin + end) >> 1;
        int result = cmp(&num, &nums[mid]);
        if (result > 0) {
            begin = mid + 1;
        } else if (result < 0) {
            end = mid;
        } else {
            return mid;
        }
    }

    return -1;
}
