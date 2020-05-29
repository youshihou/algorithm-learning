//
//  quick_union.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef quick_union_h
#define quick_union_h

#include "common.h"

void quick_union_create(int*, int);
int quick_union_find(int*, int, int);
void quick_union_union(int*, int, int, int);
bool quick_union_is_same(int*, int, int, int);

#endif /* quick_union_h */
