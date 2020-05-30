//
//  kmp.c
//  algorithm
//
//  Created by Ankui on 5/30/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "kmp.h"
#include "common.h"

static int* next_list(char* pattern) {
    size_t len = strlen(pattern);
    int* next = malloc(sizeof(int) * len);
    next[0] = -1;
    
    int i = 0;
    int n = -1;
    size_t iMax = len - 1;
    while (i < iMax) {
        if (n < 0 || pattern[i] == pattern[n]) {
            next[++i] = ++n;
        } else {
            n = next[n];
        }
    }
    
    return next;
}

int kmp(char* text, char* pattern) {
    if (text == NULL || pattern == NULL) { return -1; }
    size_t tlen = strlen(text);
    if (tlen == 0) { return -1; }
    int plen = (int)strlen(pattern);
    if (plen == 0) { return -1; }
    if (tlen < plen) { return -1; }
    
    int* next = next_list(pattern);
    
    int pi = 0;
    int ti = 0;
    size_t delta = tlen - plen;
    while (pi < plen && (ti - pi <= delta)) { // CARE!!! if pi < 0, plen must int
        if (pi < 0 || text[ti] == pattern[pi]) { // CARE!!! pi < 0
            ti++;
            pi++;
        } else {
            pi = next[pi];
        }
    }
    
    return (plen == pi) ? (ti - pi) : -1;
}
