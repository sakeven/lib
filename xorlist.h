//
//  xorlist.h
//  xorlist
//
//  Created by sake on 15/1/9.
//  Copyright (c) 2015年 sake. All rights reserved.
//

#ifndef __xorlist__xorlist__
#define __xorlist__xorlist__

#include <stdio.h>

struct node{
    int data;
    struct node *link;
};

typedef struct {
    struct node *cur;
    struct node *pre, *next;
} Iter;

struct node * insert_back(struct node *, int);
struct node * delete(struct node *, int);
void loop(struct node *);
struct node *getTail(struct node *);

Iter begin(struct node *);
Iter rbegin(struct node *);
Iter end(struct node *);
Iter rend(struct node *);

void next(Iter*);
void pre(Iter*);

int same(Iter *, Iter *);

#endif /* defined(__xorlist__xorlist__) */
