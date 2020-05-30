//
//  brute_force.c
//  algorithm
//
//  Created by Ankui on 5/30/20.
//  Copyright © 2020 Ankui. All rights reserved.
//

#include "brute_force.h"
#include "common.h"


int brute_force(char* text, char* pattern) {
    if (text == NULL || pattern == NULL) { return -1; }
    size_t tlen = strlen(text);
    if (tlen == 0) { return -1; }
    size_t plen = strlen(pattern);
    if (plen == 0) { return -1; }
    if (tlen < plen) { return -1; }
    
    size_t tiMax = tlen - plen;
    for (int ti = 0; ti <= tiMax; ti++) {
        int pi = 0;
        for (; pi < plen; pi++) {
            if (text[ti + pi] != pattern[pi]) { break; }
        }
        
        if (plen == pi) { return ti; }
    }
    
    return -1;
}



int brute_force2(char* text, char* pattern) {
    if (text == NULL || pattern == NULL) { return -1; }
    size_t tlen = strlen(text);
    if (tlen == 0) { return -1; }
    size_t plen = strlen(pattern);
    if (plen == 0) { return -1; }
    if (tlen < plen) { return -1; }
    
    int pi = 0;
    int ti = 0;
    size_t delta = tlen - plen;
    while (pi < plen && ti - pi <= delta) {
        if (text[ti] == pattern[pi]) {
            ti++;
            pi++;
        } else {
            ti -= pi - 1;
            pi = 0;
        }
    }
    
    return (plen == pi) ? (ti - pi) : -1;
}



int brute_force1(char* text, char* pattern) {
    if (text == NULL || pattern == NULL) { return -1; }
    size_t tlen = strlen(text);
    if (tlen == 0) { return -1; }
    size_t plen = strlen(pattern);
    if (plen == 0) { return -1; }
    if (tlen < plen) { return -1; }
    
    int pi = 0;
    int ti = 0;
    while (pi < plen && ti < tlen) {
        if (text[ti] == pattern[pi]) {
            ti++;
            pi++;
        } else {
            ti -= pi - 1;
            pi = 0;
        }
    }
    
    return (plen == pi) ? (ti - pi) : -1; // CARE!!! plen == pi
}
