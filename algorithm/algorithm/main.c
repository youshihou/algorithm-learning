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
#include "merge-sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"

#include "quick_find.h"
#include "quick_union.h"

int main(int argc, const char * argv[]) {    
//    int nums[] = {56, 9, 10, 28, 37, 111, 2};
//    int size = 7;
    
//    print_nums(nums, size, "bubble_sort start");
//    bubble_sort(nums, size);
//    print_nums(nums, size, "bubble_sort end");
//    
//    print_nums(nums, size, "selection_sort start");
//    selection_sort(nums, size);
//    print_nums(nums, size, "selection_sort start");
//
//    print_nums(nums, size, "heap_sort start");
//    heap_sort(nums, size);
//    print_nums(nums, size, "heap_sort end");
    
//    print_nums(nums, size, "insertion_sort start");
//    insertion_sort(nums, size);
//    print_nums(nums, size, "insertion_sort end");
    
//    int idx = index_of(nums, size, 56);
//    int idx = search(nums, size, 22);
//    printf("%d\n", idx);
    
//    print_nums(nums, size, "merge_sort start");
//    merge_sort(nums, size);
//    print_nums(nums, size, "merge_sort end");

//    print_nums(nums, size, "quick_sort start");
//    quick_sort(nums, size);
//    print_nums(nums, size, "quick_sort end");

//    print_nums(nums, size, "shell_sort start");
//    shell_sort(nums, size);
//    print_nums(nums, size, "shell_sort end");
    
//    print_nums(nums, size, "counting_sort start");
//    counting_sort(nums, size);
//    print_nums(nums, size, "counting_sort end");
  
//    print_nums(nums, size, "radix_sort start");
//    radix_sort(nums, size);
//    print_nums(nums, size, "radix_sort end");

//    print_nums(nums, size, "bucket_sort start");
//    bucket_sort(nums, size);
//    print_nums(nums, size, "bucket_sort end");
    
    
    
    int parents[12];
    quick_find_create(parents, 12);
    quick_find_union(parents, 12, 0, 1);
    quick_find_union(parents, 12, 0, 3);
    quick_find_union(parents, 12, 0, 4);
    quick_find_union(parents, 12, 2, 3);
    quick_find_union(parents, 12, 2, 5);

    quick_find_union(parents, 12, 6, 7);
    quick_find_union(parents, 12, 8, 10);
    quick_find_union(parents, 12, 9, 10);
    quick_find_union(parents, 12, 9, 11);

    printf("%d\n", quick_find_is_same(parents, 12, 0, 6));
    printf("%d\n", quick_find_is_same(parents, 12, 0, 5));
    quick_find_union(parents, 12, 4, 6);
    printf("%d\n", quick_find_is_same(parents, 12, 2, 7));

    
    return 0;
}
