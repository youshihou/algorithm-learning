//
//  skip_list.h
//  algorithm
//
//  Created by Ankui on 5/29/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#ifndef skip_list_h
#define skip_list_h

#include <stdio.h>

typedef struct skiplist* Skiplist;

Skiplist skiplist_create(void);
void skiplist_destroy(Skiplist);
int skiplist_search(Skiplist, int);
void skiplist_insert(Skiplist, int);
void skiplist_delete(Skiplist, int);


#endif /* skip_list_h */
