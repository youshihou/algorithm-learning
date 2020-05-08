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

int main(int argc, const char * argv[]) {    
    int nums[] = {56, 9, 10, 19, 28, 37, 34};
    int numSize = 7;
    
    bubble_sort(nums, numSize);
    print_nums(nums, numSize, "bubble_sort");
    
    selection_sort(nums, numSize);
    print_nums(nums, numSize, "selection_sort");

    return 0;
}
