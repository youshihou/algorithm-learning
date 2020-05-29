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
#include "quick_union_size.h"
#include "quick_union_rank.h"
#include "quick_union_rank_path_compression.h"
#include "quick_union_rank_path_spliting.h"
#include "quick_union_rank_path_halving.h"

#if 0
#include "graph.h"
static void match_sink(struct graph* g, int source, int sink, void* data) {
    assert(data && sink == *((int*)data));
}
#endif

#include "search.h"

#include "skip_list.h"

int main(int argc, const char * argv[]) {
    
#if 0
    int nums[] = {56, 9, 10, 28, 37, 111, 2};
    int size = 7;
    {
        print_nums(nums, size, "bubble_sort start");
        bubble_sort(nums, size);
        print_nums(nums, size, "bubble_sort end");
    }
    
    {
        print_nums(nums, size, "selection_sort start");
        selection_sort(nums, size);
        print_nums(nums, size, "selection_sort start");
    }

    {
        print_nums(nums, size, "heap_sort start");
        heap_sort(nums, size);
        print_nums(nums, size, "heap_sort end");
    }
    
    {
        print_nums(nums, size, "insertion_sort start");
        insertion_sort(nums, size);
        print_nums(nums, size, "insertion_sort end");
    }
    
    {
        int idx = index_of(nums, size, 56);
        idx = search(nums, size, 22);
        printf("%d\n", idx);
    }
    
    {
        print_nums(nums, size, "merge_sort start");
        merge_sort(nums, size);
        print_nums(nums, size, "merge_sort end");
    }

    {
        print_nums(nums, size, "quick_sort start");
        quick_sort(nums, size);
        print_nums(nums, size, "quick_sort end");
    }

    {
        print_nums(nums, size, "shell_sort start");
        shell_sort(nums, size);
        print_nums(nums, size, "shell_sort end");
    }
    
    {
        print_nums(nums, size, "counting_sort start");
        counting_sort(nums, size);
        print_nums(nums, size, "counting_sort end");
    }
    
    {
        print_nums(nums, size, "radix_sort start");
        radix_sort(nums, size);
        print_nums(nums, size, "radix_sort end");
    }

    {
        print_nums(nums, size, "bucket_sort start");
        bucket_sort(nums, size);
        print_nums(nums, size, "bucket_sort end");
    }
#endif
    
    
#if 0
    int parents[12];
    {
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
        printf("%d\n", quick_union_is_same(parents, 12, 2, 7));
        quick_find_union(parents, 12, 4, 6);
        printf("%d\n", quick_find_is_same(parents, 12, 2, 7));
    }
    
    {
        quick_union_create(parents, 12);
        quick_union_union(parents, 12, 0, 1);
        quick_union_union(parents, 12, 0, 3);
        quick_union_union(parents, 12, 0, 4);
        quick_union_union(parents, 12, 2, 3);
        quick_union_union(parents, 12, 2, 5);

        quick_union_union(parents, 12, 6, 7);
        quick_union_union(parents, 12, 8, 10);
        quick_union_union(parents, 12, 9, 10);
        quick_union_union(parents, 12, 9, 11);

        printf("%d\n", quick_union_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_is_same(parents, 12, 2, 7));
        quick_union_union(parents, 12, 4, 6);
        printf("%d\n", quick_union_is_same(parents, 12, 2, 7));
    }
    
    {
        int sizes[12];
        quick_union_size_create(parents, 12, sizes);
        quick_union_size_union(parents, 12, sizes, 0, 1);
        quick_union_size_union(parents, 12, sizes, 0, 3);
        quick_union_size_union(parents, 12, sizes, 0, 4);
        quick_union_size_union(parents, 12, sizes, 2, 3);
        quick_union_size_union(parents, 12, sizes, 2, 5);

        quick_union_size_union(parents, 12, sizes, 6, 7);
        quick_union_size_union(parents, 12, sizes, 8, 10);
        quick_union_size_union(parents, 12, sizes, 9, 10);
        quick_union_size_union(parents, 12, sizes, 9, 11);

        printf("%d\n", quick_union_size_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_size_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_size_is_same(parents, 12, 2, 7));
        quick_union_size_union(parents, 12, sizes, 4, 6);
        printf("%d\n", quick_union_size_is_same(parents, 12, 2, 7));
    }

    {
        int ranks[12];
        quick_union_rank_create(parents, 12, ranks);
        quick_union_rank_union(parents, 12, ranks, 0, 1);
        quick_union_rank_union(parents, 12, ranks, 0, 3);
        quick_union_rank_union(parents, 12, ranks, 0, 4);
        quick_union_rank_union(parents, 12, ranks, 2, 3);
        quick_union_rank_union(parents, 12, ranks, 2, 5);

        quick_union_rank_union(parents, 12, ranks, 6, 7);
        quick_union_rank_union(parents, 12, ranks, 8, 10);
        quick_union_rank_union(parents, 12, ranks, 9, 10);
        quick_union_rank_union(parents, 12, ranks, 9, 11);

        printf("%d\n", quick_union_rank_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_rank_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_rank_is_same(parents, 12, 2, 7));
        quick_union_rank_union(parents, 12, ranks, 4, 6);
        printf("%d\n", quick_union_rank_is_same(parents, 12, 2, 7));
    }

    {
        int ranks[12];
        quick_union_rank_path_compression_create(parents, 12, ranks);
        quick_union_rank_path_compression_union(parents, 12, ranks, 0, 1);
        quick_union_rank_path_compression_union(parents, 12, ranks, 0, 3);
        quick_union_rank_path_compression_union(parents, 12, ranks, 0, 4);
        quick_union_rank_path_compression_union(parents, 12, ranks, 2, 3);
        quick_union_rank_path_compression_union(parents, 12, ranks, 2, 5);

        quick_union_rank_path_compression_union(parents, 12, ranks, 6, 7);
        quick_union_rank_path_compression_union(parents, 12, ranks, 8, 10);
        quick_union_rank_path_compression_union(parents, 12, ranks, 9, 10);
        quick_union_rank_path_compression_union(parents, 12, ranks, 9, 11);

        printf("%d\n", quick_union_rank_path_compression_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_rank_path_compression_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_rank_path_compression_is_same(parents, 12, 2, 7));
        quick_union_rank_path_compression_union(parents, 12, ranks, 4, 6);
        printf("%d\n", quick_union_rank_path_compression_is_same(parents, 12, 2, 7));
    }

    {
        int ranks[12];
        quick_union_rank_path_spliting_create(parents, 12, ranks);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 0, 1);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 0, 3);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 0, 4);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 2, 3);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 2, 5);

        quick_union_rank_path_spliting_union(parents, 12, ranks, 6, 7);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 8, 10);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 9, 10);
        quick_union_rank_path_spliting_union(parents, 12, ranks, 9, 11);

        printf("%d\n", quick_union_rank_path_spliting_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_rank_path_spliting_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_rank_path_spliting_is_same(parents, 12, 2, 7));
        quick_union_rank_path_spliting_union(parents, 12, ranks, 4, 6);
        printf("%d\n", quick_union_rank_path_spliting_is_same(parents, 12, 2, 7));
    }

    {
        int ranks[12];
        quick_union_rank_path_halving_create(parents, 12, ranks);
        quick_union_rank_path_halving_union(parents, 12, ranks, 0, 1);
        quick_union_rank_path_halving_union(parents, 12, ranks, 0, 3);
        quick_union_rank_path_halving_union(parents, 12, ranks, 0, 4);
        quick_union_rank_path_halving_union(parents, 12, ranks, 2, 3);
        quick_union_rank_path_halving_union(parents, 12, ranks, 2, 5);

        quick_union_rank_path_halving_union(parents, 12, ranks, 6, 7);
        quick_union_rank_path_halving_union(parents, 12, ranks, 8, 10);
        quick_union_rank_path_halving_union(parents, 12, ranks, 9, 10);
        quick_union_rank_path_halving_union(parents, 12, ranks, 9, 11);

        printf("%d\n", quick_union_rank_path_halving_is_same(parents, 12, 0, 6));
        printf("%d\n", quick_union_rank_path_halving_is_same(parents, 12, 0, 5));
        printf("%d\n", quick_union_rank_path_halving_is_same(parents, 12, 2, 7));
        quick_union_rank_path_halving_union(parents, 12, ranks, 4, 6);
        printf("%d\n", quick_union_rank_path_halving_is_same(parents, 12, 2, 7));
    }
#endif
    
    
#if 0
    {
        #define SIZE (37)
        struct graph* g = create(SIZE);
        assert(vertex_count(g) == SIZE);
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                assert(has_edge(g, i, j) == 0);
            }
        }
        
        for (int i = 0; i < SIZE; i++) {
            assert(out_degree(g, i) == 0);
            foreach(g, i, match_sink, 0);
        }
        assert(edge_count(g) == 0);
        
        for (int i = 0; i < SIZE; i++) {
            add_edge(g, i, i);
        }
        assert(edge_count(g) == SIZE);
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                assert(has_edge(g, i, j) == (i == j));
            }
        }
        
        for (int i = 0; i < SIZE; i++) {
            assert(out_degree(g, i) == 1);
            foreach(g, i, match_sink, &i);
        }
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i != j) {
                    add_edge(g, i, j);
                }
            }
        }
        assert(edge_count(g) == SIZE * SIZE);
        
        for (int i = 0; i < SIZE; i++) {
            assert(out_degree(g, i) == SIZE);
            for (int j = 0; j < SIZE; j++) {
                assert(has_edge(g, i, j) == 1);
            }
        }
        
        destroy(g);
    }
#endif
    
#if 0
    {
        if (argc != 3) {
            fprintf(stderr, "Usage: %s action n\nwhere action =\n  g - print graph\n  d - print dfs tree\n  b - print bfs tree\n", argv[0]);
            return 1;
        }
        
        int n = atoi(argv[2]);
        struct _graph* g = make_sample_graph(n);
        switch (argv[1][0]) {
            case 'g':
                print_graph(g);
                break;
                case 'd':
                dfs(g, 0);
                print_tree(g);
                break;
                case 'b':
                bfs(g, 0);
                print_tree(g);
                break;
            default:
                fprintf(stderr, "%s: unknown action '%c'\n", argv[0], argv[1][0]);
                return 1;;
        }
        destroy_(g);
    }
#endif
    
#if 1
    {
        if (argc != 2) {
            fprintf(stderr, "Usage: %s number-od-elements\n", argv[0]);
            return 1;
        }
        
        int n = atoi(argv[1]);
//        int n = 10;
        Skiplist s = skiplist_create();
        
        for (int i = 0; i < n; i += 2) {
            skiplist_insert(s, i);
        }
        
        assert(skiplist_search(s, -1) == INT_MIN);
        
        for (int i = 0; i < n; i += 2) {
            assert(skiplist_search(s, i) == i);
            assert(skiplist_search(s, i + 1) == i);
        }
        
        
        for (int i = 0; i < n; i += 4) {
            skiplist_delete(s, i);
        }
        
        assert(skiplist_search(s, 0) == INT_MIN);
        
        for (int i = 2; i < n; i += 4) {
            assert(skiplist_search(s, i) == i);
            assert(skiplist_search(s, i + 1) == i);
            assert(skiplist_search(s, i + 2) == i);
            assert(skiplist_search(s, i + 3) == i);
        }
        
        for (int i = 0; i < n; i++) {
            skiplist_insert(s, 0);
            assert(skiplist_search(s, 0) == 0);
            assert(skiplist_search(s, 1) == 0);
        }
        
        for (int i = 0; i < n; i++) {
            assert(skiplist_search(s, 0) == 0);
            assert(skiplist_search(s, 1) == 0);
            skiplist_delete(s, 0);
        }
        
        assert(skiplist_search(s, 0) == INT_MIN);
        
        skiplist_destroy(s);
    }
#endif
    
    return 0;
}
