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

#define PTR struct node *

#define LOOPOVER(preAddr, curAddr) \
    for(PTR nextAddr ;(nextAddr = XOR(preAddr, curAddr->link))!= NULL;) { \
        preAddr = curAddr; \
        curAddr = nextAddr; \
    }

#define FOREACH(preAddr, curAddr) \
    for(PTR nextAddr  = curAddr; \
        nextAddr != NULL ;\
        nextAddr = XOR(preAddr, curAddr->link),\
            preAddr = curAddr, \
            curAddr = nextAddr)

unsigned long makeUL(struct node * p) {
    return (unsigned long)p;
}

struct node * XOR(struct node *p, struct node *q) {
    return (struct node *)(makeUL(p)^makeUL(q));
}

struct node * insert_back(struct node *root, int data) {
    struct node *p = NULL, *q = root;
    
    p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->link = NULL;
    
    if (root == NULL) {
        root = p;
    } else {
        struct node *pre = NULL;
        LOOPOVER(pre, q);
        p->link = XOR(NULL, q);
        q->link = XOR(p, pre);
    }
    return root;
}

struct node *getTail(struct node *root) {
    struct node *pre = NULL, *q = root;
    LOOPOVER(pre, q);
    return q;
}

void loop(struct node *root) {
    struct node *pre = NULL, *q = root;
    
    FOREACH(pre, q){
        printf("%d\n",q->data);
    }
}

struct node * Delete(struct node *root, int data) {
    
    return root;
}

