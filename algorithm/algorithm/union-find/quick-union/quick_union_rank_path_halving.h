//
//  quick_union_rank_path_halving.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef quick_union_rank_path_halving_h
#define quick_union_rank_path_halving_h

#include "common.h"

void quick_union_rank_path_halving_create(int*, int, int*);
void quick_union_rank_path_halving_union(int*, int, int*, int, int);
int quick_union_rank_path_halving_find(int*, int, int);
bool quick_union_rank_path_halving_is_same(int*, int, int, int);


#endif /* quick_union_rank_path_halving_h */
