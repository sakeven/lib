//
//  xorlist_test.c
//  xorlist
//
//  Created by sake on 15/1/9.
//  Copyright (c) 2015年 sake. All rights reserved.
//

#include "xorlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node *root = NULL, *tail = NULL;
    root = insert_back(root, 1);
    root = insert_back(root, 2);
    root = insert_back(root, 5);
    root = insert_back(root, 3);
    root = insert_back(root, 4);
    loop(root);
    printf("reverse\n");
    tail = getTail(root);
    loop(tail);
    printf("Begin\n");
    Iter it = begin(root);
    printf("%d\n", it.cur->data);
    next(&it);
    printf("%d\n", it.cur->data);
    pre(&it);
    printf("%d\n", it.cur->data);
    
    Iter en = end(root);
    for (; !same(&it, &en); next(&it)) {
        printf("%d\n",it.cur->data);
    }
    
    Iter ren = rend(root);
    it = rbegin(root);
    for (; !same(&it, &ren); pre(&it)) {
        printf("%d\n",it.cur->data);
    }
    return 0;
}