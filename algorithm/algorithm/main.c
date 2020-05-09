//
//  main.c
//  algorithm
//
//  Created by Ankui on 5/8/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include <stdio.h>
#include "sort-common.h"
#include "bubble-sort.h"
#include "selection-sort.h"
#include "heap-sort.h"
#include "insertion-sort.h"


int main(int argc, const char * argv[]) {    
    int nums[] = {56, 9, 10, 19, 28, 37, 34, 111, 2, 55};
    int numsSize = 10;
    
    bubble_sort(nums, numsSize);
    print_nums(nums, numsSize, "bubble_sort");
    
    selection_sort(nums, numsSize);
    print_nums(nums, numsSize, "selection_sort");

    heap_sort(nums, numsSize);
    print_nums(nums, numsSize, "heap_sort");
    
    insertion_sort(nums, numsSize);
    print_nums(nums, numsSize, "insertion_sort");
    
    return 0;
}
