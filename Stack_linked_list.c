/* single linked list based stack */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

int append(Node **root, int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->next = *root;
    *root = new;
    new->data = data;
    printf("Pushing on stack data : %d \n", data);
//    new->next = NULL;
}

void pop(Node **root) {
    Node *old = NULL;
    if (*root == NULL) {
        printf("Stack bottom !!! \n");
        return;
    }
    old = *root;
    printf("Popping out %d \n", old->data);
    *root = old->next;
    free(old);
}

void peek(Node **root){
    if (*root == NULL) {
        printf("Stack bottom !!! \n");
        return;
    }
    printf("Stack Peek data: %d\n", (*root)->data);    
}

int main () {
Node *root = NULL;
peek(&root);
append(&root, 30);
append(&root, 26);
append(&root, 53);
peek(&root);

pop(&root);
pop(&root);
pop(&root);
peek(&root);

return 1;
}