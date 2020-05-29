//
//  quick_find.h
//  algorithm
//
//  Created by Ankui on 5/17/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef quick_find_h
#define quick_find_h

#include "common.h"

void quick_find_create(int*, int);
int quick_find_find(int*, int, int);
void quick_find_union(int*, int, int, int);
bool quick_find_is_same(int*, int, int, int);

#endif /* quick_find_h */
