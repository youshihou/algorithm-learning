//
//  quick_union_rank.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef quick_union_rank_h
#define quick_union_rank_h

#include "union-find-common.h"

void quick_union_rank_create(int*, int, int*);
void quick_union_rank_union(int*, int, int*, int, int);
int quick_union_rank_find(int*, int, int);
bool quick_union_rank_is_same(int*, int, int, int);


#endif /* quick_union_rank_h */
