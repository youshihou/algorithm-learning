//
//  quick_sort.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_sort.h"
#include "sort-common.h"


int pivot_index(int* nums, int size, int begin, int end) {
    int pivot = nums[begin];
    end--;
    
    while (begin < end) {
        while (begin < end) {
            // right --> left
            if (pivot < nums[end]) {
                end--;
            } else {
                nums[begin++] = nums[end];
                break;
            }
        }
        
        while (begin < end) {
            // left --> right
            if (pivot > nums[begin]) {
                begin++;
            } else {
                nums[end--] = nums[begin];
                break;
            }
        }
    }
    
    nums[begin] = pivot;
    
    return begin;
}

void sort_(int* nums, int size, int begin, int end) {
    if (end - begin < 2) { return; }
    
    int mid = pivot_index(nums, size, begin, end);
    sort_(nums, size, begin, mid);
    sort_(nums, size, mid + 1, end);
}

void quick_sort(int* nums, int size) {
    if (nums == NULL || size <= 0) { return; }
    
    sort_(nums, size, 0, size);
}
