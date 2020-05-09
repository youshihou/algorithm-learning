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
#include "heap_sort.h"



int main(int argc, const char * argv[]) {    
    int nums[] = {56, 9, 10, 19, 28, 37, 34, 111, 2, 55};
    int numSize = 10;
    
    bubble_sort(nums, numSize);
    print_nums(nums, numSize, "bubble_sort");
    
    selection_sort(nums, numSize);
    print_nums(nums, numSize, "selection_sort");

    heap_sort(nums, numSize);
    print_nums(nums, numSize, "heap_sort");
    
    return 0;
}
