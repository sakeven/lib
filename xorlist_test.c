#include "xorlist.h"
#include <stdio.h>

int main(){
    struct node *root = NULL, *tail = NULL;
    root = insert_back(root, 1);
    root = insert_back(root, 2);
    root = insert_back(root, 1);
    root = insert_back(root, 3);
    root = insert_back(root, 4);
    loop(root);
    tail = getTail(root);
    loop(tail);
    return 0;
}