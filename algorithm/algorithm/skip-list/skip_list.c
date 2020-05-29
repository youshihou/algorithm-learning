//
//  skip_list.c
//  algorithm
//
//  Created by Ankui on 5/29/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "skip_list.h"
#include "common.h"


#define MAX_HEIGHT (32)

struct skiplist {
    int key;
    int height;
    struct skiplist* next[1];
};



static int choose_height(void) {
    int i;
    for (i = 1; i < MAX_HEIGHT && ((rand() & 1) == 0); i++) {
        
    }
    return i;
}

static Skiplist skiplist_create_node(int key, int height) {
    assert(height > 0);
    assert(height <= MAX_HEIGHT);
    
    Skiplist s = malloc(sizeof(struct skiplist) + sizeof(struct skiplist*) * (height - 1));
    assert(s);
    
    s->key = key;
    s->height = height;
    
    return s;
}

Skiplist skiplist_create(void) {
    Skiplist s = skiplist_create_node(INT_MIN, MAX_HEIGHT);
    s->height = 1;
    
    for (int i = 0; i < MAX_HEIGHT; i++) {
        s->next[i] = 0;
    }
    
    return s;
}

void skiplist_destroy(Skiplist s) {
    Skiplist next;
    while (s) {
        next = s->next[0];
        free(s);
        s = next;
    }
}

int skiplist_search(Skiplist s, int key) {
    for (int level = s->height - 1; level >= 0; level--) {
        while (s->next[level] && s->next[level]->key <= key) {
            s = s->next[level];
        }
    }
    
    return s->key;
}



void skiplist_insert(Skiplist s, int key) {
    Skiplist elt = skiplist_create_node(key, choose_height());
    assert(elt);
    
    if (elt->height > s->height) {
        s->height = elt->height;
    }
    
    int level;
    for (level = s->height - 1; level >= elt->height; level--) {
        while (s->next[level] && s->next[level]->key < key) {
            s = s->next[level];
        }
    }
    
    for (; level >= 0; level--) {
        while (s->next[level] && s->next[level]->key < key) {
            s = s->next[level];
        }
        
        elt->next[level] = s->next[level];
        s->next[level] = elt;
    }
}

void skiplist_delete(Skiplist s, int key) {
    int level;
    Skiplist target = s;
    
    for (level = s->height - 1; level >= 0; level--) {
        while (target->next[level] && target->next[level]->key < key) {
            target = target->next[level];
        }
    }
    
    target = target->next[0];
    
    if (target == 0 || target->key != key) {
        return;
    }
    
    for (level = s->height - 1; level >= 0; level--) {
        while (s->next[level] && s->next[level]->key < key) {
            s = s->next[level];
        }
        
        if (s->next[level] == target) {
            s->next[level] = target->next[level];
        }
    }
    
    free(target);
}
