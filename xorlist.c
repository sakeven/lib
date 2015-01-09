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


PTR delete(PTR root, int data) {
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

Iter begin(PTR root){
    Iter it = {
        .cur = root,
        .pre = NULL,
        .next = root->link
    };
    
    return it;
}

Iter rbegin(PTR root){
    PTR pre = NULL, q = root;
    
    LOOPOVER(pre, q);
    
    Iter it = {
        .cur = q,
        .pre = pre,
        .next = NULL
    };
    
    return it;
}

Iter end(PTR root){
    PTR pre = NULL, q = root;
    
    LOOPOVER(pre, q);
    
    Iter it = {
        .cur = NULL,
        .pre = q,
        .next = NULL
    };
    
    return it;
}

Iter rend(PTR root){
    
    Iter it = {
        .cur = NULL,
        .pre = NULL,
        .next = root
    };
    
    return it;
}

void next(Iter* nd){
    PTR pre = nd->pre;
    
    nd->pre = nd->cur;
    
    if (nd->next != NULL){
        nd->cur = nd->next;
    } else {
        nd->cur = XOR(nd->cur->link, pre);
    }
    
    nd->next = NULL;
}

void pre(Iter* nd){
    PTR next = nd->next;
    
    nd->next = nd->cur;
    
    if (nd->pre != NULL){
        nd->cur = nd->pre;
    } else {
        nd->cur = XOR(nd->cur->link, next);
    }
    
    nd->pre = NULL;
}

int same(Iter *A, Iter *B) {
    return A->cur == B->cur &&
        A->next == B->next &&
        A->pre == B->pre;
}
