//
//  xorlist.c
//  xorlist
//
//  Created by sake on 15/1/9.
//  Copyright (c) 2015年 sake. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "xorlist.h"

typedef struct node * PTR; 

#define LOOPOVER(preAddr, curAddr) \
    for(PTR nextAddr ;(nextAddr = XOR(preAddr, curAddr->link))!= NULL;) { \
        preAddr = curAddr; \
        curAddr = nextAddr; \
    }

#define FOREACH(preAddr, curAddr) \
    for(PTR nextAddr  = curAddr; \
        nextAddr != NULL ; \
        nextAddr = XOR(preAddr, curAddr->link), \
            preAddr = curAddr, \
            curAddr = nextAddr)

unsigned long makeUL(PTR p) {
    return (unsigned long)p;
}

PTR XOR(PTR p, PTR q) {
    return (PTR)(makeUL(p)^makeUL(q));
}

PTR insert_back(PTR root, int data) {
    PTR p = NULL, q = root;
    
    p = (PTR)malloc(sizeof(struct node));
    p->data = data;
    p->link = NULL;
    
    if (root == NULL) {
        root = p;
    } else {
        PTR pre = NULL;
        LOOPOVER(pre, q);
        p->link = XOR(NULL, q);
        q->link = XOR(p, pre);
    }
    return root;
}

PTR getTail(PTR root) {
    PTR pre = NULL, q = root;
    LOOPOVER(pre, q);
    return q;
}

void loop(PTR root) {
    PTR pre = NULL, q = root;
    
    FOREACH(pre, q){
        printf("%d\n",q->data);
    }
}

PTR delete(PTR root, int data) {
    
    return root;
}

