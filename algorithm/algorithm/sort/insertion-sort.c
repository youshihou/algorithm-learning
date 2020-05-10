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

void insertion_sort(int nums[], int numsSize) {
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
