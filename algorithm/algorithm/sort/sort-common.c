//
//  sort-common.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "sort-common.h"

int cmp(int* a, int* b) {
    return *a - *b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_nums(int* nums, int numSize, char* name) {
    printf("\n%s start\n", name);
    for (int i = 0; i < numSize; i++) {
        printf("%d_", nums[i]);
    }
    printf("\n%s end\n", name);
}
