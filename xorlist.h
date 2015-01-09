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

struct node * insert_back(struct node *, int);
struct node * delete(struct node *, int);
void loop(struct node *);
struct node *getTail(struct node *);

#endif /* defined(__xorlist__xorlist__) */