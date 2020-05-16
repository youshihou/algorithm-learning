//
//  shell_sort.c
//  algorithm
//
//  Created by Ankui on 5/16/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "shell_sort.h"
#include "sort-common.h"

void sort__(int* nums, int size, int step) {
    for (int col = 0; col < step; col++) {
        // col, col + step, col + 2 * step, col + 3 * step, ...
        for (int begin = col + step; begin < size; begin += step) {
            int cur = begin;
            int num = nums[cur];
            while (cur > col && cmp(&num, &nums[cur - step]) < 0) {
                nums[cur] = nums[cur - step];
                cur -= step;
            }
            nums[cur] = num;
        }
    }
}

void shell_step(int list[], int size) {
    if (size <= 0) { return; }
            
//    for (int i = 0, step = size; i < size && (step >>= 1) > 0; i++) {
//        list[i] = step;
//    }
    
    while ((size >>= 1) > 0) {
        *list = size;
        list++;
    }
}

void shell_sort(int* nums, int size) {
    int* list = malloc(sizeof(int) * size);
    memset(list, 0, sizeof(int) * size);
    shell_step(list, size);
    
    for (int i = 0; i < size; i ++) {
        int step = list[i];
        if (step <= 0) { break; }
        sort__(nums, size, step);
    }
}
