//
//  main.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include <stdio.h>
#include "bubble-sort.h"
#include "selection-sort.h"

int main(int argc, const char * argv[]) {    
    int nums[] = {56, 9, 10, 19, 28, 37, 34};
    int numSize = 7;
    
    printf("\nbubble_sort---start\n");
    bubble_sort(nums, numSize);
    for (int i = 0; i < numSize; i++) {
        printf("%d_", nums[i]);
    }
    printf("\nbubble_sort---end\n");
    
    printf("\nselection_sort----start\n");
    selection_sort(nums, numSize);
    for (int i = 0; i < numSize; i++) {
        printf("%d_", nums[i]);
    }
    printf("\nselection_sort----end\n");

    return 0;
}
