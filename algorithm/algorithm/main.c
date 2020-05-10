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
#include "binary-search.h"

int main(int argc, const char * argv[]) {    
    int nums[] = {56, 9, 10, 28, 37, 111, 2};
    int numsSize = 7;
    
//    print_nums(nums, numsSize, "bubble_sort start");
//    bubble_sort(nums, numsSize);
//    print_nums(nums, numsSize, "bubble_sort end");
//    
//    print_nums(nums, numsSize, "selection_sort start");
//    selection_sort(nums, numsSize);
//    print_nums(nums, numsSize, "selection_sort start");
//
//    print_nums(nums, numsSize, "heap_sort start");
//    heap_sort(nums, numsSize);
//    print_nums(nums, numsSize, "heap_sort end");
    
    print_nums(nums, numsSize, "insertion_sort start");
    insertion_sort(nums, numsSize);
    print_nums(nums, numsSize, "insertion_sort end");
    
//    int idx = index_of(nums, numsSize, 56);
    int idx = search(nums, numsSize, 22);
    printf("%d\n", idx);
    
    return 0;
}
