//
//  quick_sort.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "quick_sort.h"
#include "sort-common.h"


int pivot_index(int* nums, int begin, int end) {
    int pivot = nums[begin];
    end--;
    
    while (begin < end) {
        
        // right --> left
        while (begin < end) {
            if (pivot < nums[end]) {
                end--;
            } else {
                nums[begin++] = nums[end];
                break;
            }
        }
        
        // left --> right
        while (begin < end) {
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

void sort_(int* nums, int begin, int end) {
    if (end - begin < 2) { return; }
    
    int mid = pivot_index(nums, begin, end);
    sort_(nums, begin, mid);
    sort_(nums, mid + 1, end);
}

void quick_sort(int* nums, int size) {
    if (nums == NULL || size <= 0) { return; }
    
    sort_(nums, 0, size);
}
