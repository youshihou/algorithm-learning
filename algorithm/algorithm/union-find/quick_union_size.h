//
//  quick_union_size.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef quick_union_size_h
#define quick_union_size_h

#include "union-find-common.h"

void quick_union_size_create(int*, int, int*);
void quick_union_size_union(int*, int, int*, int, int);
int quick_union_size_find(int*, int, int);
bool quick_union_size_is_same(int*, int, int, int);

#endif /* quick_union_size_h */
